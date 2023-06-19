#ifndef DEVICECONFIG_H
#define DEVICECONFIG_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

void checkCPULoad()
{
    // Check CPU load by observing idle task time
    // Here, we just print the CPU usage. You might want to add a condition to check if CPU usage is below a certain threshold.
    UBaseType_t uxArraySize = uxTaskGetNumberOfTasks();
    TaskStatus_t* pxTaskStatusArray = pvPortMalloc( uxArraySize * sizeof( TaskStatus_t ) );
    if( pxTaskStatusArray != NULL ) {
        uxArraySize = uxTaskGetSystemState( pxTaskStatusArray, uxArraySize, NULL );
        for(UBaseType_t x = 0; x < uxArraySize; x++) {
            if(strcmp(pxTaskStatusArray[x].pcTaskName, "IDLE") == 0) {
                printf("Idle task CPU usage: %0.2f%%\n", 100.0 * (1.0 - ((float)pxTaskStatusArray[x].ulRunTimeCounter) / xTaskGetTickCount()));
            }
        }
        vPortFree( pxTaskStatusArray );
    }
}

bool printHighPriorityTasks()
{

    // Check if high priority tasks are running (priority >= 5 as an example)
    // You should replace the priority level with what you consider a "high priority task" in your application.
    uxArraySize = uxTaskGetNumberOfTasks();
    pxTaskStatusArray = pvPortMalloc( uxArraySize * sizeof( TaskStatus_t ) );
    if( pxTaskStatusArray != NULL ) {
        uxArraySize = uxTaskGetSystemState( pxTaskStatusArray, uxArraySize, NULL );
        for(UBaseType_t x = 0; x < uxArraySize; x++) {
            if(pxTaskStatusArray[x].uxBasePriority >= 5) {
                printf("High priority task %s is running\n", pxTaskStatusArray[x].pcTaskName);
                vPortFree( pxTaskStatusArray );
                return false;
            }
        }
        vPortFree( pxTaskStatusArray );
    }
    return true;
}

#endif

# CloudPatchOTA

This project is a reusable library for FreeRTOS that provides the functionality to download, verify and apply firmware updates over the air to the embedded devices. The library is based on the BalenaOS reference design and can be integrated into existing FreeRTOS projects.


Force the device to update to the latest firmware version by calling ```void execOTA(WiFiClient client,String host,int port,String bin)``` from ```OTAUpdateModule```.

If the link to the s3 object is _bucket−name.s3.ap−south−1.amazonaws.com/sketch−name.ino.bin_ , then *_"bucket−name.s3.ap−south−1.amazonaws.com"_* is your host and _"/sketch−name.ino.bin"_ is your bin. Make sure to update the read permissions and CORS configurations for your bucket. 

#ifndef SECRETS_H
#define SECRETS_H
#include <pgmspace.h> 
#define SECRET
#define THINGNAME "esp32_test"                         //change this
 
const char WIFI_SSID[] = "Test";               //change this
const char WIFI_PASSWORD[] = "87654321";           //change this
const char AWS_IOT_ENDPOINT[] = "a2eqgyalutp8ki-ats.iot.ap-south-1.amazonaws.com";       //change this
const char host[] = "bucketwithota.s3.ap-south-1.amazonaws.com";
const char bin[] = "/updated.bin";



// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";




// Device Certificate                                               //change this
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUOtMCRll/llb6gezZutAr4+XArZQwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIzMDYwNjEzNDgy
NVoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAJ9Q8b6nVmKbblLLOfS6
DMVw5vg62JVwP5QhQ4x1fOUoZk0G/s0RrUKV7R0VSVrq31FDobYrdGWtjTzUOVGB
cZ60EkdqcP8hI727XTWbP96i1Ei6/DoohSjacYCcfFqICpBxHQtYpQNNupjsMd2k
POdVcHJHX6g7ztcouDbAUn5g3GZPCB6FpC3HHT5fCbUS8aCV+hLltk/Gk/MJS0L1
sSCyluCBKfWeprxg1urqsNqTa5ElR2hcGFDB2SntRpnVjr7xZ19pBXOkCyLf1wDM
XZSz44SPy8JwE03ZkVqsC6gLUgoZZ2lIuJePacj0x7KmLjYfcDRD9G3+LiZfqDrI
Y40CAwEAAaNgMF4wHwYDVR0jBBgwFoAUPu60RaKXJrzPbEliwruqkm13lnEwHQYD
VR0OBBYEFP94wQ+4yyERjkuTpwL8z0GVZaKyMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQCc3KM2rxOGeudNPOQPJJXrairQ
DHGncjiuyAEug1xPaJG4jY1lvMps/cEz6hByn8tPyKS2mwqywM4X2G30oNybcXb/
XM9vy2WGHSqnUsE+bNvWF0oN06j+p5rCNajDLC/h23proEQnamzLS84DDtJgLt1o
ZsylBwbN9G+RCrQizqCqW8KJl+dzd0k+NWIKWekdIOuL5q66oeUE+e3epFYw+2tf
5BF9p8nxfxUaAK34VMoz983EbH85kIDglvroQBrL6Dwm8xMxgopjSat0cJgO9Lid
X+A5ETOBF552FE8h1Kd2jUzn6uqnnidr1Q7fvpHlYNIGItZ89iSpio7DREIV
-----END CERTIFICATE----- 
)KEY";
 



// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAn1DxvqdWYptuUss59LoMxXDm+DrYlXA/lCFDjHV85ShmTQb+
zRGtQpXtHRVJWurfUUOhtit0Za2NPNQ5UYFxnrQSR2pw/yEjvbtdNZs/3qLUSLr8
OiiFKNpxgJx8WogKkHEdC1ilA026mOwx3aQ851VwckdfqDvO1yi4NsBSfmDcZk8I
HoWkLccdPl8JtRLxoJX6EuW2T8aT8wlLQvWxILKW4IEp9Z6mvGDW6uqw2pNrkSVH
aFwYUMHZKe1GmdWOvvFnX2kFc6QLIt/XAMxdlLPjhI/LwnATTdmRWqwLqAtSChln
aUi4l49pyPTHsqYuNh9wNEP0bf4uJl+oOshjjQIDAQABAoIBAAWrP67lDXHczgQs
LxfCNwofhlh235YRtHF07Y5l79fHpDxBb3eklWG1LAbI5x9RFDk0CuEMksu7bTco
5hE8Zeqbxbq80uCBMWBi9mId8Bvf92XPIYKARpy5iShmaRZfmOCi5cGtmdGQRn+C
iBO28GPa6nFmkMTPvABz9nocRdMxWMUVfBG/zsw8aPQ4XGXU7OiuOwSI7OSOiQpb
YpXvG3u2mj1AAKdwSWso9zWvXbzWYyp24cKmdyerm2jqtQZtGJ/NXnchsBY0MjC2
mTecSCUZX1SLtR26jN7fHyQxEldtCj2sR+/xpkpy7M5kB4OZp6hAyzwTiMu6LdvP
pyWEsAECgYEA0KAxNp/4SVEcp1cWKL6LAiBo+InkfuIR2Mf2SnnV9AbtYPssxQfj
0u3WiZlQLRqJpXZ+1n6L71X5njjHBlH7dyE58JauKMGLF3xJbLaV/k7yBKkejOan
DHEY8t2t7d5H3/0496Nbb9W/w3hxJKNaYcG3+QH2ZakKPaPnuCTRYI0CgYEAw35L
W+XBjHn0GZ8gablZh0F6UndyWYQpzDINoVq41PEkuMQmhJsS/nYEjZOgSVOQlGQy
DYG4QASUE83J00HpIEyzs8PiB00SUmXzu7iz++HpyECK+HGOx3mDzRvtJvRswhv3
+MALVlvN+ZnA5ymDpZqOmjrH+R1Tfa8Xcs+5zwECgYBMR2X3DQJg/DE31hWaDCET
Q/pddT2ATvQriOE6VdWuhaHhZbT2zW21P5TDdrTj6OIPB4ZUsqxDc/HysdvDKdKB
ujpPByjiafGLQrwt7YxmEUNYBOXQqrzFRczTb84aPL2W3iUoFihmeYbF15G2zatM
NuInP1pxzR6bbwRYRc3wOQKBgQC8n6USnFLtudW+yvy5Re+OQ61E2J9qo8y4iyr/
nstsGug1pn0LwZzIDRNDj0c+uPRtWWe6BInEqyY9HXg48AWB9sAFGWGDbefZvSk4
3XQ7+rRZVX1BTkBXU3XKd8GQrpIpkFbomlPWFWpeBO5NnI67QK+LPGAqixM9160m
SCueAQKBgQC39pZozNwHVcujjVcuzklphECs8lFoYLvzZcUsfLGtUQLo9lyef6Kq
imVUW6uYI4SeY/UI6TsDZ1zyRUZdaRIdMY1RgzYNm02491s5gnXP+eUTFfjZLUnf
kWIR+5S5bofl/S7hRI7787c80UTo7qcxGt/CIucy6SnH7KS+KfcPYg==
-----END RSA PRIVATE KEY----- 
)KEY";

#endif

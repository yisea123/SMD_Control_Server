// John Davis
// Copyright 2015 3ML LLC

#include <Bridge.h>
#include <Process.h>
#include <FileIO.h>

void setup() {

  Serial.begin(115200);
  //while(!Serial);

  Serial.print(F("Hello\n"));
  
  //setup the environment
  Bridge.begin();
  Serial.print(F("Bridge Started\n"));

  while(!FileSystem.exists("/mnt/sda1/smd_server/SMD_Server"))
    delay(1000);
  
  //start the SMD Server.
  Process server;
  server.runShellCommand("export LD_LIBRARY_PATH=/mnt/sda1/smd_server/lib && ifconfig eth1 10.20.6.1 && /mnt/sda1/smd_server/SMD_Server");
  
  //turn on the LED to let us know that we are good
  pinMode(13,OUTPUT);
  
  while(true) {
    digitalWrite(13,HIGH);
    delay(150);
    digitalWrite(13,LOW);
    delay(150); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
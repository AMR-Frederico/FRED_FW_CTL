#include <Arduino.h>
#include <MAIN/ps4.h>
#include <MAIN/ros_com.h>
// test

bool connected = false;
bool emergency_break = false;


void setup() {
  // Serial.begin(115200);
  pinMode(LED_BUILDIN,OUTPUT);
  digitalWrite(LED_BUILDIN, LOW);
  PS4setup();
  ros_init();
}

void loop() {
  connected = ps4Connected();

  if(connected){
    digitalWrite(LED_BUILDIN, HIGH);

    cmd_linear = ps4Linear();
    cmd_angular = ps4Angular();

    
    // if(battery(30)){
    //     //ADD BLINK 
    //   //  digitalWrite(LED_BUILDIN, LOW);
    //   //  Serial.print("BAT LOW ");
    // }

    // Serial.print("| Linear: ");
    // Serial.print(cmd_linear);
    // Serial.print("| Angular: ");
    // Serial.print(cmd_angular);
    // Serial.println("");


  }else{
    digitalWrite(LED_BUILDIN, LOW);
  }
  // ros_loop(cmd_linear,cmd_angular,1);

  // nh.spinOnce();
}
#include <ros.h>
#include <sensor_msgs/Joy.h>



// Subscribers ------------

//Publisher 
#define joy_topic "joy"

//debug

ros::NodeHandle  nh;

//------------------SUBS--------------------




//-----------------PUBS-------------------------

sensor_msgs::Joy ps4_control_msg ;
ros::Publisher ps4_control_pub(joy_topic, &ps4_control_msg);

// debug




bool rosConnected(ros::NodeHandle  nh,bool _connect){
    bool connected = nh.connected();
    if(_connect != connected){
        _connect = connected;
        // digitalWrite(LED_BUILD_IN,!connected);
       
    }
    
    return connected;
}


void ros_init(){

  nh.initNode(); 
  nh.advertise(ps4_control_pub);

}

void ros_loop(float cmd_vel_linear, float cmd_vel_angular, int emergency_break){

    ps4_control_msg.header.frame_id = "joy";

    ps4_control_msg.axes[0] = (cmd_linear);
    ps4_control_msg.axes[1] = (cmd_angular);
    ps4_control_msg.buttons[0] = emergency_break;


    ps4_control_pub.publish(&ps4_control_msg);



}
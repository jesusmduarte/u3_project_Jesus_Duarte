/*
 * File:          three_wheels.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */
 // motors and stuff
#include <webots/robot.h>
#include <webots/motor.h>
//#include <webots/keyboard.h>
//sensors
#include <webots/distance_sensor.h>
//#include <webots/light_sensor.h>
#include <webots/position_sensor.h>
//calculations
#include <stdio.h>
#define PI 3.14

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
  wb_robot_init();

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
  WbDeviceTag first_motor = wb_robot_get_device("wheel1");
  WbDeviceTag second_motor = wb_robot_get_device("wheel2");
  WbDeviceTag third_motor = wb_robot_get_device("wheel3");

  WbDeviceTag right_distance = wb_robot_get_device("right_light");
  WbDeviceTag left_distance = wb_robot_get_device("left_light");

  WbDeviceTag ps1 = wb_robot_get_device("first_ps");
  WbDeviceTag ps2 = wb_robot_get_device("second_ps");
  WbDeviceTag ps3 = wb_robot_get_device("third_ps");
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */

  wb_motor_set_position(first_motor, INFINITY);
  wb_motor_set_position(second_motor, INFINITY);
  wb_motor_set_position(third_motor, INFINITY);

  //wb_keyboard_enable(TIME_STEP);
  wb_distance_sensor_enable(right_distance, TIME_STEP);
  wb_distance_sensor_enable(left_distance, TIME_STEP);

  wb_position_sensor_enable(ps1, TIME_STEP);
  wb_position_sensor_enable(ps2, TIME_STEP);
  wb_position_sensor_enable(ps3, TIME_STEP);

  double rgt_val;
  double lft_val;

  double ps1_val;
  double ps2_val;
  double ps3_val;

  while (wb_robot_step(TIME_STEP) != -1) {

    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
     float one_speed = -3.14;
     

     rgt_val = wb_distance_sensor_get_value(right_distance);
     printf("Distance sensor value: %lf\n", rgt_val);
     lft_val = wb_distance_sensor_get_value(left_distance);
     printf("Distance sensor value: %lf\n",lft_val);

     ps1_val= wb_position_sensor_get_value(ps1);
     printf("Right position sensor value: %lf\n", ps1_val);
     ps2_val = wb_position_sensor_get_value(ps2);
     printf("Left position sensor value: %lf\n", ps2_val);
     ps3_val = wb_position_sensor_get_value(ps3);
     printf("Left position sensor value: %lf\n", ps3_val);

     ///satarting motors forward
     //wb_motor_set_velocity(first_motor, one_speed);
     //wb_motor_set_velocity(second_motor, one_speed);
     //wb_motor_set_velocity(third_motor, 0);
     
    ///turn to the back
     //wb_motor_set_velocity(first_motor, one_speed);
     //wb_motor_set_velocity(second_motor, one_speed);
     //wb_motor_set_velocity(third_motor, 0);
     
    ////turnt to the left
     //wb_motor_set_velocity(first_motor, one_speed);
     //wb_motor_set_velocity(second_motor, one_speed);
     //wb_motor_set_velocity(third_motor, -one_speed*1.85);
     
     //turn to the right0
     wb_motor_set_velocity(third_motor, one_speed*1.85);
     wb_motor_set_velocity(first_motor, -one_speed*.80);
     wb_motor_set_velocity(second_motor, -one_speed);
     
    /*
     * Enter here functions to send actuator commands, like:
     * wb_differential_wheels_set_speed(100.0,100.0);
     */

   //Note to professor:
   // have trouble with the light sensor so i cant continue with the
  // project, in fact the problem doesnt have a solution and dont have enough time to post it
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}

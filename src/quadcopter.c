#include "quadcopter.h"
#include "simpletools.h"

int main()
{
  //motor_init();
  //xbee_init();
  imu_init();
  
  simpleterm_close();
  imu_run();
  //cog_run(&imu_run, 40);
  //cog_run(&xbee_run, 10);
  //cog_run(&ultrasonic_run, 10);
  //motor_run();
}
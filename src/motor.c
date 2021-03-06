#include "quadcopter.h"
#include "simpletools.h"
#include "servo.h"

#define SWAP(x,y) \
    if (newMotors[y]->current_val < newMotors[x]->current_val) \
    {                                                          \
      volatile Motor* tmp = newMotors[x];                      \
      newMotors[x] = newMotors[y];                             \
      newMotors[y] = tmp;                                      \
    }
#define PWM_CYCLE 20000

void quad_time(int, int);
void quad_power(int);

void pwm_run();

volatile Motor f = { .pin = PIN_MOTOR_F, .current_val = 0 };
volatile Motor b = { .pin = PIN_MOTOR_B, .current_val = 0 };
volatile Motor l = { .pin = PIN_MOTOR_L, .current_val = 0 };
volatile Motor r = { .pin = PIN_MOTOR_R, .current_val = 0 };

void motor_init()
{
  motors[0] = &f;
  motors[1] = &b;
  motors[2] = &l;
  motors[3] = &r;
  imu.pitch.inc = &f;
  imu.pitch.dec = &b;
  imu.roll.inc = &r;
  imu.roll.dec = &l;
}

void motor_run()
{
  cog_run(&pwm_run, 100);
  while(1) {
    int tmp = lastCommand;
    switch(tmp) {
      case COMMAND_WAKEUP:
        quad_power(1000);
        break;
      case COMMAND_TAKEOFF:
        quad_power(1200);
        break;
      case COMMAND_SHUTDOWN:
        quad_power(1100);
        break;
      case 0x64:
        quad_power(1300);
        break;
      case 0x65:
        quad_power(1400);
        break;
    }
  }
}

void pwm_run()
{
  servo_start();
  waitcnt(CNT + CLKFREQ/2);
  while(1)
  {
    for (int i=0;i<4;i++)
      servo_set(motors[i]->pin, motors[i]->current_val);
  }
}

void quad_time(int power, int time) {
  int tmp = CNT;
  quad_power(power);
  waitcnt(tmp + CLKFREQ*time);
}

void quad_power(int power)
{
  for (int i=0;i<4;i++)
    motors[i]->current_val = power;
}
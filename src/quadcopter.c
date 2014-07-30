#include "quadcopter.h"
#include "simpletools.h"
#include "simplei2c.h"
#include <propeller.h>
#include <stdio.h>

int main()
{
  xbeeInit();

  while(1)
  {
    int signal = xbeeGetByte();
    if (signal == 0x01)
      motorWakeup();
    else if (signal == 0x02)
      motorRun();
    else if (signal == 0x03)
      motorStop();
  }
  //waitcnt(CNT + CLKFREQ);

  //imuInit();
//
  //cog_run(&imuRun, 1);
  //cog_run(&xbeeRun, 2);
//
  //signed short gx,gy,gz,ax,ay,az;
  
  motorRun(4, 1500);

  //while(1)
  //{
  //  waitcnt(CNT + CLKFREQ/10);
  //  getImuData(&gx, &gy, &gz, &ax, &ay, &az);
  //  gx = computePID(gx, 0);
  //  printf("G: %5d %5d %5d\t", gx, gy, gz);
  //  printf("A: %5d %5d %5d\n", ax, ay, az);
  //}
}
#include "simpletools.h"
#include "simplei2c.h"
#include <propeller.h>
#include <stdio.h>

#define PIN_IMU_SDA 0
#define PIN_IMU_SCL 1

#define GYRO_ADDR  0xD0
#define GYRO_REG_X 0x1D
#define GYRO_REG_Y 0x1F
#define GYRO_REG_Z 0x21

#define ACCL_ADDR  0xA6
#define ACCL_REG_X 0x32
#define ACCL_REG_Y 0x34
#define ACCL_REG_Z 0x36

volatile signed short gx;
volatile signed short gy;
volatile signed short gz;
volatile signed short ax;
volatile signed short ay;
volatile signed short az;

unsigned short readFromRegister(i2c*, int, int);
void writeToRegister(i2c*, int, int, int);
unsigned short readValue(i2c*, int, int, int);
unsigned short combine(char, char);

void imuInit();
void imuUpdate();
void imuRun();
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h
#include <wiringPiI2c.h>
#define  PWR_MGMT_1 
 #define GYRO_XOUT_H 0x43
 #define GYRO_XOUT_L 0x44
 #define GYRO_YOUT_H 0x45
 #define GYRO_YOUT_L 0x46
 #define GYRO_ZOUT_H 0x47
 #define GYRO_ZOUT_L 0x48

 #define ACCEL_XOUT_H 0x3B
 #define ACCEL_XOUT_L 0x3C
 #define ACCEL_YOUT_H 0x3D
 #define ACCEL_YOUT_L 0x3E
 #define ACCEL_ZOUT_H 0x3F
 #define ACCEL_ZOUT_L 0x40
 
 #define AK8963_XOUT_L 0x03
 #define AK8963_XOUT_H 0x04
 #define AK8963_YOUT_L 0x05 
 #define AK8963_YOUT_H 0x06
 #define AK8963_ZOUT_L 0x07
 #define AK8963_ZOUT_L 0x08
 #define AK8963_CNTL 0x0A 
 
 
 int(main){

 int fd wiringPiSetup(0x68);
 int magno wiringPiSetup(0x0C);
 
 wiringPiI2CWriteReg8(fd, MPU6050_REG_PWR_MGMT_1, 0);

delay(10);

uint8_t axh,axl,ayh,ayl,azh,azl,gxh,gxl,gyh,gyl,gzh,gzl,mxh,mxl,myh,myl,mzh,mzl;
while (1){
axh = wiringPiI2CReadReg8(fd, 0x3B);
axl = wiringPiI2CReadReg8(fd, 0x3C);
int16_t accelX = (axh << 8) | axl;

ayh = wiringPiI2CReadReg8(fd, 0x3D);
ayl = wiringPiI2CReadReg8(fd, 0x3E);
int16_t accelY = (ayh << 8) | ayl;

azh = wiringPiI2CReadReg8(fd, 0x3F);
azl = wiringPiI2CReadReg8(fd, 0x40);
int16_t accelZ = (azh << 8) | azl;

gxh = wiringPiI2CReadReg8(fd, 0x43);
gxl = wiringPiI2CReadReg8(fd, 0x44);
int16_t gyroX = (gxh << 8) | gxl;

gyh = wiringPiI2CReadReg8(fd, 0x45);
gyl = wiringPiI2CReadReg8(fd, 0x46);
int16_t gyroY = (gyh << 8) | gyl;

gzh = wiringPiI2CReadReg8(fd, 0x47);
gzl = wiringPiI2CReadReg8(fd, 0x48);
int16_t gyroZ = (gzh << 8) | gzl;

mxh = wiringPiI2CReadReg8(magno, 0x03);
mxl = wiringPiI2CReadReg8(magno, 0x04);
int16_t magX = (mxh << 8) | mxl;

myh = wiringPiI2CReadReg8(magno, 0x05);
myl = wiringPiI2CReadReg8(magno, 0x06);
int16_t magY = (myh << 8) | myl;

mzh = wiringPiI2CReadReg8(magno, 0x07);
mzl = wiringPiI2CReadReg8(magno, 0x08);
int16_t magZ = (mzh << 8) | mzl;
}
printf("%i\n", accelX);
printf("%i\n", accelY);
printf("%i\n", accelZ);
printf("%i\n", gyroX);
printf("%i\n", gyroY);
printf("%i\n", gyroZ);
printf("%i\n", magX);
printf("%i\n", magY);
printf("%i\n", magZ);

  pitch = atan2 (accelY , ( sqrt ((accelX * accelX) + (accelZ * accelZ))));
  roll = atan2(-accelX , ( sqrt((accelY * accelY) + (accelZ * accelZ))));

  // yaw from mag

  float Yh = (magY * cos(roll)) - (magZ * sin(roll));
  float Xh = (magX * cos(pitch)) + (magY * sin(roll) * sin(pitch)) + (magZ * cos(roll) * sin(pitch));

  //yaw =  atan2(Yh, Xh);
}

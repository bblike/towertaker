#ifndef __MOTOR__PID__H__
#define __MOTOR__PID__H__


#include "vex.h"

using namespace vex;


float kp, ki, kd;


float pid_calculate(float error, float integral, float difference)
{
		float output;
		kp = 1;
    ki = 0.0000003;
    kd = 0.8;

		output = kp * error + ki * integral - kd * difference;
		return output;
}

void straight(float targetR, float targetL,float length)
{
  right_1.resetRotation();
  right_2.resetRotation();
  left_1.resetRotation();
  left_2.resetRotation();
	
    float garyR =0;
		float errorR = 0;
		float error_lastR = 0;
		float integralR = 0;
		float differenceR = 0;
    float garyL =0;
		float errorL = 0;
		float error_lastL = 0;
		float integralL = 0;
		float differenceL = 0;
		float speedLeft = 0;
		float speedRight = 0;
    int sign_R =0;
    int sign_L =0;
		int count = 0;
		while(count <= 20){
      garyR=(right_1.rotation(rotationUnits::deg)+right_2.rotation(rotationUnits::deg)) /720* length;
      garyL=-(left_1.rotation(rotationUnits::deg)+left_2.rotation(rotationUnits::deg)) /720*length;

			errorR = targetR - garyR;
			differenceR = error_lastR - errorR;
			speedRight = pid_calculate(errorR, integralR, differenceR);

			errorL = targetL - garyL;
			differenceL = error_lastL - errorL;
			speedLeft = pid_calculate(errorL, integralL, differenceL);
			
      if(speedLeft > 100){
        speedLeft = 100;}
      if(speedLeft < -100){
        speedLeft = -100;}
      if(speedRight > 100){
        speedRight = 100;}
      if(speedRight < -100){
        speedRight = -100;}

      sign_R=speedRight/fabsf(speedRight);
      sign_L=speedLeft/fabsf(speedLeft);
      speedRight=fabsf(speedRight);
      speedLeft=fabsf(speedLeft);

      if(sign_R>0){
        right_1.spin(vex::directionType::fwd,speedRight,vex::velocityUnits::pct);
        right_2.spin(vex::directionType::fwd,speedRight,vex::velocityUnits::pct);
      }
      else {
        right_1.spin(vex::directionType::rev,speedRight,vex::velocityUnits::pct);
        right_2.spin(vex::directionType::rev,speedRight,vex::velocityUnits::pct);
      }
      if(sign_L>0){
        left_1.spin(vex::directionType::rev,speedLeft,vex::velocityUnits::pct);
        left_2.spin(vex::directionType::rev,speedLeft,vex::velocityUnits::pct);
      }
      else {
        left_1.spin(vex::directionType::fwd,speedLeft,vex::velocityUnits::pct);
        left_2.spin(vex::directionType::fwd,speedLeft,vex::velocityUnits::pct);
      }
       
        if(speedRight < 12 && speedLeft < 12 ){
          integralL=integralL+errorL;
          integralR=integralR+errorR;
        }
				
			if(speedLeft <= 4 && speedRight < 4 )//&&(garyR>targetR-3)&&(garyL>targetL-3))||((garyR=targetR) && (garyL=targetL))){
				count = count + 1;


			error_lastR = errorR;
			error_lastL = errorL;
			vex::task::sleep(20);
	}
}






#endif
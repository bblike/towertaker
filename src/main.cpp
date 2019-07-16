
#include "pid.h"


// A global instance of vex::brain used for printing to the V5 brain screen




int main() {
   double handmove = 100;
    while(1) {
       //jack is sb
        // Allow other tasks to run
        right_1.spin(vex::directionType::fwd,controller1.Axis3.value() - controller1.Axis1.value(),vex::velocityUnits::pct);
        right_2.spin(vex::directionType::fwd,controller1.Axis3.value() - controller1.Axis1.value(),vex::velocityUnits::pct);
        left_1.spin(vex::directionType::rev,controller1.Axis3.value() + controller1.Axis1.value(),vex::velocityUnits::pct);
        left_2.spin(vex::directionType::rev,controller1.Axis3.value() +controller1.Axis1.value(),vex::velocityUnits::pct);
        
        if (controller1.ButtonR1.pressing()){
          hand1.spin(vex::directionType::fwd,handmove,vex::velocityUnits::pct);
          hand2.spin(vex::directionType::rev,handmove,vex::velocityUnits::pct);
        }
        else if (controller1.ButtonR2.pressing()) {
        hand1.spin(vex::directionType::rev,handmove,vex::velocityUnits::pct);
        hand2.spin(vex::directionType::fwd,handmove,vex::velocityUnits::pct);
        }
        else{
          hand1.stop();
          hand2.stop();
        
        }
        if (controller1.ButtonL1.pressing()){
          if(cubeplacerpush.pressing()){
          push.stop();
          }
          else {push.spin(vex::directionType::rev,27,vex::velocityUnits::pct);}
        }
        else if (controller1.ButtonL2.pressing()) {
          if(cubeplacerpull.pressing()){
          push.stop();}
          else {push.spin(vex::directionType::fwd,12,vex::velocityUnits::pct);}
        }
        else{
          push.stop();//
        }
        if (controller1.ButtonUp.pressing()){
          arm.spin(vex::directionType::rev,100,vex::velocityUnits::pct);}
          else if (controller1.ButtonDown.pressing()){
            if(stopper_1.pressing()&&stopper_2.pressing()){
              arm.stop();
            }
            else{
            arm.spin(vex::directionType::rev,1,vex::velocityUnits::pct);}
          }
          else{arm.spin(vex::directionType::fwd,20,vex::velocityUnits::pct);}
    }
   }
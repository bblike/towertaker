/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "v5.h"
#include "v5_vcs.h"

vex::brain Brain;
vex::motor right_1(vex::PORT1,vex::gearSetting::ratio18_1,true);
vex::motor right_2(vex::PORT2,vex::gearSetting::ratio18_1,true);
vex::motor left_1(vex::PORT3,vex::gearSetting::ratio18_1,true);
vex::motor left_2(vex::PORT4,vex::gearSetting::ratio18_1,true);
vex::motor arm(vex::PORT5,vex::gearSetting::ratio6_1,true);
vex::motor hand1(vex::PORT6,vex::gearSetting::ratio18_1,true);
vex::motor hand2(vex::PORT7,vex::gearSetting::ratio18_1,true);
vex::motor push(vex::PORT8,vex::gearSetting::ratio6_1,true);
vex::bumper cubeplacerpush=vex::bumper(Brain.ThreeWirePort.A);
vex::bumper cubeplacerpull=vex::bumper(Brain.ThreeWirePort.C);
vex::bumper stopper_1=vex::bumper(Brain.ThreeWirePort.E);
vex::bumper stopper_2=vex::bumper(Brain.ThreeWirePort.F);
vex::controller controller1 =vex::controller();
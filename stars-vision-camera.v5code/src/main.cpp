/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Jovan                                            */
/*    Created:      Sat Mar 26 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "str-vs-math.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();



  while(true){
  float distance_t = 0;
  float distanceSum = 0;
  float centerYObjectSum = 0;
  

  //get average of 10 ditance samples
    if(Controller1.ButtonA.pressing()){
      for(int i = 0; i < 11; i++){
        distance_t = (VsCalculateDistanceToObject_mm(SIG_BLUE)/10); //get distance and divide by 10 to get CM
        distanceSum += distance_t; // add all the distance

        centerYObjectSum += VsGetCenterY(SIG_BLUE);

      } 

      printf("\nDistance Average: %4.3f  | CenterY Average: %4.3f", distanceSum/10, centerYObjectSum/10); //divide by 10 to get an average
    } 
  //

  VsDrawObjectOnBrain(SIG_BLUE);

  wait(200, msec);

  }
  
}

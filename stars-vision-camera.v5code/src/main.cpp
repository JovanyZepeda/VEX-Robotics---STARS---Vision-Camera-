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
#include "../str-vision-header/str-vs-math.h"
#include "../str-vision-src/str-vs-math.cpp"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while(true){
  
  float distance_t = 0;
  float distanceSum = 0;

  //get average of 10 ditance samples
    if(Controller1.ButtonA.pressing()){
      for(int i = 0; i < 11; i++){
        distance_t = (VsCalculateDistanceToObject_mm(SIG_BLUE)/10); //get distance and divide by 10 to get CM
        distanceSum += distance_t; // add all the distance
      } 

      printf("\nDistance Average: %4.3f", distanceSum/10); //divide by 10 to get an average
    }
  //

  wait(200, msec);

  }
  
}

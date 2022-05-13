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


  float distance_t = 0;
  float distanceSum = 0;
  float centerYObjectSum = 0;


  while(true){
  
  
    //get average of 10 distance samples - Largest object
      if(Controller1.ButtonA.pressing()){
        for(int i = 0; i < 10; i++){
          distance_t = (VsDistanceToObject_mm(SIG_PURPLE) /10); //Get distance and convert to cm
          distanceSum += distance_t; // Add all the distance
          centerYObjectSum += VsGetCenterY_px(SIG_PURPLE);
        } 

        printf("\nDistance Average: %4.3f  | CenterY Average: %4.3f  | Object count: %4.3ld", distanceSum/10, centerYObjectSum/10, Vision1.objectCount); //Divide by 10 to get an average
        distanceSum = 0;
        distance_t = 0;
        centerYObjectSum = 0;

      } 
    //
    
    
    //get average of 10 distance samples - Largest object - Version 2
      if(Controller1.ButtonY.pressing()){
        
        distance_t = (VsDistanceToObject_version2_mm(SIG_PURPLE) ); //Get distance and convert to cm
        centerYObjectSum = VsGetCenterY_px(SIG_PURPLE);
        

        printf("\nDistance Average: %4.3f  | CenterY Average: %4.3f  | Object count: %4.3ld", distance_t, centerYObjectSum, Vision1.objectCount); //Divide by 10 to get an average
      
        distance_t = 0;
        centerYObjectSum = 0;

      } 
    //



    //get average of 10 distance samples - From an Array
      if(Controller1.ButtonX.pressing()){
        for(int j = 0; j < Vision1.objectCount + 1; j++){ // Go through Each Object in array
          for(int i = 0; i < 10; i++){ // Calculate 10 samples
            distance_t = (VsDistanceToObject_mm(SIG_PURPLE, j) /10); //Get distance and convert to cm
            distanceSum += distance_t; // Add all the distance
            centerYObjectSum += VsGetCenterY_px(SIG_PURPLE,j);
          } 

          printf("\nDistance Average: %4.3f  | CenterY Average: %4.3f  | Object count: %4.3li", distanceSum/10, centerYObjectSum/10, j); //Divide by 10 to get an average
          distanceSum = 0;
          distance_t = 0;
          centerYObjectSum = 0;

        }
      } 
    //

    //Draw all objects
    VsDrawObjectOnBrain(SIG_PURPLE, purple);

    wait(200, msec);

  }
  
}

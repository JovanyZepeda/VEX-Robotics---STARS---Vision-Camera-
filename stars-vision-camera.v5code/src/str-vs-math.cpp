#include "str-vs-math.h"
#include "str-vs-config.h"
#include "vex.h"

using namespace vex;

//Resrouces
//https://docs.robotmesh.com/vex-iq-cpp-vision-guide 
//

// Global Variables --------------------------
 const float g_vsCameraHeight_mm = 305.0;
 const float g_vsTheta_c_deg = 180-34.00;
 const float g_vsFOV_deg = 41; //https://www.vexforum.com/t/vision-sensor-fov-measurements/62397
 const float g_vsMaxYPixel_px = 400; //Maximum y pixel vertical legnth 


//functions ---------------------------------

//Function: Distance to Object
 float VsDistanceToObject_mm(signature &sig_target){
   // take a picture and search for blue object
    Vision1.takeSnapshot(sig_target);
   //local variables
    float l_vsObjectYPosition_px = Vision1.largestObject.centerY;

    
   //Calculate ditance
    float l_vsTargetDistance_mm = -g_vsCameraHeight_mm * tanf( atanf( (tan(M_PI*g_vsFOV_deg/360) * (g_vsMaxYPixel_px - 2 * l_vsObjectYPosition_px)  ) / g_vsMaxYPixel_px ) - ( (M_PI/180) * g_vsTheta_c_deg) );

    //if no object detected, make 0
    if(Vision1.largestObject.exists == 0){
      l_vsTargetDistance_mm = 0;
    }

   return l_vsTargetDistance_mm;
  }
//


//Function: Distance to Object
 float VsDistanceToObject_version2_mm(signature &sig_target){
   // take a picture and search for blue object
    Vision1.takeSnapshot(sig_target);
   //local variables
    float l_vsObjectYPosition_px = Vision1.largestObject.centerY;

    
   //Calculate ditance
    float l_vsTargetDistance_mm = -g_vsCameraHeight_mm * tanf( atanf( g_vsMaxYPixel_px/2440 - l_vsObjectYPosition_px/1220 ) - (g_vsTheta_c_deg * M_PI/180) );

    //if no object detected, make 0
    if(Vision1.largestObject.exists == 0){
      l_vsTargetDistance_mm = 0;
    }

   return l_vsTargetDistance_mm;
  }
//


//Function: Distrance to an object. Select from an array.
  float VsDistanceToObject_mm(signature &sig_target, int ObjectIndex){
    //take a picture and search for blue object
      Vision1.takeSnapshot(sig_target);
    //local variables
      float l_vsObjectYPosition_px = Vision1.objects[ObjectIndex].centerY;

      
    //Calculate distance
      float l_vsTargetDistance_mm = -g_vsCameraHeight_mm * tanf( atanf( (tan(M_PI*g_vsFOV_deg/360) * (g_vsMaxYPixel_px - 2 * l_vsObjectYPosition_px)  ) / g_vsMaxYPixel_px ) - ( (M_PI/180) * g_vsTheta_c_deg) );



    return l_vsTargetDistance_mm;
  }
//

//Function: Get CenterY
  float VsGetCenterY_px(signature &sig_target){
    // take a picture and search for blue object
    Vision1.takeSnapshot(sig_target);

    return Vision1.largestObject.centerY;
  }
//

//Funcition: Get CenterY From an Array
  float  VsGetCenterY_px(signature &sig_target, int ObjectIndex){
    // take a picture and search for blue object
    Vision1.takeSnapshot(sig_target);

    return Vision1.objects[ObjectIndex].centerY;
  }

  //Get CenterX
  float VsGetCenterX_Largest_px(signature &sig_target){
    // take a picture and search for blue object
    Vision1.takeSnapshot(sig_target);

    return Vision1.largestObject.centerX;
  }
//
  


//Function: Calculate Theta from center from camera
 float VsCalculateTargetThetaFromCameraCenter(signature &sig_target){
  //Take picture
  Vision1.takeSnapshot(sig_target);

  //local Variables
  float targetCenterY_Pixel = Vision1.largestObject.centerY;
  float targetY_pixel = 0;
  float Ymax_Pixel = 212;
  float phiFOV_deg = g_vsFOV_deg/2;
  float targetThetaFromCenter_deg = 0;

  // Calculate target y using centerY
  if(targetCenterY_Pixel < 0.5*Ymax_Pixel){
    targetY_pixel = (0.5*Ymax_Pixel) - targetCenterY_Pixel;

  } else if (targetCenterY_Pixel > 0.5*Ymax_Pixel) {
    targetY_pixel = targetCenterY_Pixel - (0.5*Ymax_Pixel);

  } else {
    targetY_pixel = 0;
  }

//Function: calculate angle of target from center of camera
  float targetThetaFromCentertemp_deg = (180/M_PI) * atanf( (2*targetY_pixel/Ymax_Pixel) * tanf( (M_PI/180) * phiFOV_deg)  );

  //give the angle its sign
  if (targetCenterY_Pixel > 0.5*Ymax_Pixel){
     targetThetaFromCenter_deg = -fabsf(targetThetaFromCentertemp_deg) ;

  } else if (targetCenterY_Pixel < 0.5*Ymax_Pixel){
     targetThetaFromCenter_deg = fabsf(targetThetaFromCentertemp_deg);

  } else if (targetCenterY_Pixel == 0.5*Ymax_Pixel){
     targetThetaFromCenter_deg = 0;

  } 
  
  // If object is not detected. make angle = 0
  if(Vision1.largestObject.exists == 0){
    targetThetaFromCenter_deg = 0;
  }


  return targetThetaFromCenter_deg;
  }

//Function: Draw on screen
  void VsDrawObjectOnBrain(signature &sig_target){
    //Take picture
    Vision1.takeSnapshot(sig_target);

    //Clear Screen
    Brain.Screen.clearScreen();

    //Draw Rectangle - BLUE Color
    Brain.Screen.setFillColor(blue);
    Brain.Screen.drawRectangle(Vision1.largestObject.originX, Vision1.largestObject.originY, Vision1.largestObject.width, Vision1.largestObject.height);

  }
//

//Function: Draw on screen. all objects from array
  void VsDrawObjectOnBrain(signature &sig_target, const color &sig_color){
      //Take picture
      Vision1.takeSnapshot(sig_target);

      //Clear Screen
      Brain.Screen.clearScreen();

      for(int j = 0; j < Vision1.objectCount+1; j++){
        //Draw Rectangle - BLUE Color
        Brain.Screen.setFillColor(sig_color);
        Brain.Screen.drawRectangle(Vision1.objects[j].originX, Vision1.objects[j].originY, Vision1.objects[j].width, Vision1.objects[j].height);
        //
      }
  }
//
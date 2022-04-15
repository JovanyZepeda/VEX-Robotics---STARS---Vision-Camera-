#include "str-vs-math.h"
#include "str-vs-config.h"
#include "vex.h"

using namespace vex;


// Global Variables --------------------------
 const float g_vsMountHeight_mm = 445.0;
 const float g_vsHorDisplacenmentTheta_deg = -25.00;
 const float g_vsFOV_deg = 60/2; //https://www.vexforum.com/t/vision-sensor-fov-measurements/62397

//functions ---------------------------------

//Distance to Object
 float VsCalculateDistanceToObject_mm(signature &sig_target){
   // take a picture and search for blue object
    Vision1.takeSnapshot(SIG_BLUE);
   //local variables
   float targetTheta_deg = VsCalculateTargetThetaFromCameraCenter(SIG_BLUE);
   float targetTheta_rad =  (M_PI/180) * (g_vsHorDisplacenmentTheta_deg +  targetTheta_deg);
   float objectHeight_mm = 160;
    
   //Calculate ditance
   float targetDistance_mm = fabsf((g_vsMountHeight_mm - objectHeight_mm) / ( tanf(  targetTheta_rad ) )) ;

    //if no object detected, make 0
    if(Vision1.largestObject.exists == 0){
      targetDistance_mm = 0;
    }

   return targetDistance_mm;
}

//Get CenterY
  float VsGetCenterY(signature &sig_target){
    // take a picture and search for blue object
    Vision1.takeSnapshot(sig_target);

    return Vision1.largestObject.centerY;
  }
  //Get CenterX
  float VsGetCenterX(signature &sig_target){
    // take a picture and search for blue object
    Vision1.takeSnapshot(sig_target);

    return Vision1.largestObject.centerX;
  }


//Calculate Theta from center from camera
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

//calculate angle of target from center of camera
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


void VsDrawObjectOnBrain(signature &sig_target){
  //Take picture
  Vision1.takeSnapshot(sig_target);

  //Clear Screen
  Brain.Screen.clearScreen();

  //Draw Rectangle - BLUE Color
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(Vision1.largestObject.originX, Vision1.largestObject.originY, Vision1.largestObject.width, Vision1.largestObject.height);
 

 

}


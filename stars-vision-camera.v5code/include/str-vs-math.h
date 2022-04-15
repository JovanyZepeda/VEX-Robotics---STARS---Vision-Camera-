#include "vex.h"

#ifndef VS_MATH
#define VS_MATH

using namespace vex;


// Global Variables --------------------------
extern const float g_vsMountHeight_mm;
extern const float g_vsHorDisplacenmentTheta_deg;
extern const float g_vsFOV_deg;

// extern vision::signature SIG_BLUE;

//functions ---------------------------------
extern float VsCalculateDistanceToObject_mm(signature &sig_target);

extern float VsCalculateTargetThetaFromCameraCenter(signature &sig_target);

extern void VsDrawObjectOnBrain(signature &sig_target);

extern void VsDisplayObjectStats();

extern float  VsGetCenterY(signature &sig_target);

extern float VsGetCenterX(signature &sig_target);

#endif


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
extern float VsDistanceToObject_mm(signature &sig_target);

extern float VsDistanceToObject_version2_mm(signature &sig_target);

extern float VsDistanceToObject_version3_mm(signature &sig_target);

extern float VsDistanceToObject_mm(signature &sig_target, int ObjectIndex);

extern float VsCalculateTargetThetaFromCameraCenter(signature &sig_target);

///

extern void VsDrawObjectOnBrain(signature &sig_target);

extern void VsDrawObjectOnBrain(signature &sig_target, const color &sig_color);

//

extern void VsDisplayObjectStats();

//

extern float  VsGetCenterY_px(signature &sig_target);

extern float  VsGetCenterY_px(signature &sig_target, int ObjectIndex);

//

extern float VsGetCenterX_px(signature &sig_target);

extern float VsGetCenterX_px(signature &sig_target, int ObjectIndex);

#endif


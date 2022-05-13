/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature SIG_BLUE = vex::vision::signature (1, -2651, -2007, -2329, 13523, 19393, 16458, 2.8, 0);
vex::vision::signature SIG_RED = vex::vision::signature (2, 7941, 8823, 8382, -573, 1, -286, 5.6, 0);
vex::vision::signature SIG_PURPLE = vex::vision::signature (3, 851, 2269, 1560, 3361, 5461, 4411, 2.2, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision Vision1 = vex::vision (vex::PORT9, 59, SIG_BLUE, SIG_RED, SIG_PURPLE, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/
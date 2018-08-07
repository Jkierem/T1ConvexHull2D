#ifndef __CORE__H__
#define __CORE__H__

#include "../Juan/Juan.h"

namespace Core {
    Hull naiveConvexHull( Cloud dots );
    Hull jarvisConvexHull( Cloud dots );
    Hull jarvisHelper( Cloud dots );
    Hull divideAndConquerConvexHull( Cloud dots );
} /* Core */

#endif

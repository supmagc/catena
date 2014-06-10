#ifndef _H_CHALK_TYPES
#define _H_CHALK_TYPES 1

#include "Rock.h"

namespace Chalk {

    struct RenderSettings {

        Rock::RUINT nWidth;
        Rock::RUINT nHeight;
        Rock::RBOOL bFullscreen;
    };
};

#endif // _H_CHALK_TYPES
%module Rock

#define _UNICODE 1
#define _WIN32 1

#ifdef _WIN32 || _WIN64
%import <windows.i>
#endif

%import "../inc/Rock_Defines.h"
%import "../inc/Rock_Types.h"

%{
#include "Rock.h"
using namespace Rock;
%}

// %include "../inc/Rock_Vector2.h"
// %include "../inc/Rock_Vector3.h"
// %include "../inc/Rock_Vector4.h"
// %include "../inc/Rock_Matrix4x4.h"

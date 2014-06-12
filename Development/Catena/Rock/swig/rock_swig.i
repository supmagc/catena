%module Rock_Shared

//
// Standard defines to compile for windows with unicode support
//
#define _UNICODE 1
#define _SWIG 1
#define _WINDOWS 1
#define _WIN32 1

//
// Basic imports, required for type recognition
//
%import <windows.i>
%import "../inc/Rock_Defines.h"
%import "../inc/Rock_Types.h"

//
// Include PCH
//
%begin %{
#include "Rock_Std.h"
%}

//
// Rock includes
//
%header %{
#include "Rock.h"
using namespace Rock;
%}

//
// Rock interface definitions
//
// %include "../inc/Rock_Vector2.h"
// %include "../inc/Rock_Vector3.h"
// %include "../inc/Rock_Vector4.h"
// %include "../inc/Rock_Matrix4x4.h"

//
// Expose namespace for depending modules
//
using namespace Rock;

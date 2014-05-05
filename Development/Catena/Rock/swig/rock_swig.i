%module Rock

%{
#include "Rock.h"
using namespace Rock;
%}

%import <windows.i>
%import "../inc/Rock_Defines.h"
%import "../inc/Rock_Types.h"

%include "../inc/Rock_Vector2.h"
%include "../inc/Rock_Vector3.h"
%include "../inc/Rock_Vector4.h"
%include "../inc/Rock_Matrix4x4.h"

%module Rock

%import <windows.i>
%import "../inc/Rock_Defines.h"
%import "../inc/Rock_Types.h"

%apply signed char { RINT8 };
%apply unsigned char { RUINT8 };
%apply short { RINT16 };
%apply unsigned short { RUINT16 };
%apply int { RINT32 };
%apply unsigned int { RUINT32 };
%apply long { RINT64 };
%apply unsigned long { RUINT64 };
%apply float { RFLOAT };
%apply double { RDOUBLE };
%apply unsigned char { RBYTE };
%apply bool { RBOOL };

%{
#include "Rock.h"
using namespace Rock;
%}

%include "../inc/Rock_Vector2.h"
%include "../inc/Rock_Vector3.h"
%include "../inc/Rock_Vector4.h"
%include "../inc/Rock_Matrix4x4.h"

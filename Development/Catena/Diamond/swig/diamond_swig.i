%module Diamond

%import "../../Rock/swig/rock_swig.i"
%import "../inc/Diamond_Defines.h"

%{
#include "Rock.h"
#include "Chalk.h"
#include "Chalk_D3d9.h"
#include "Diamond.h"

using namespace Rock;
using namespace Chalk;
using namespace Diamond;
%}

%include "../inc/Diamond_Core.h"
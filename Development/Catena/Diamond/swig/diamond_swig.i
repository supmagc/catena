%module Diamond_Shared

//
// Basic imports, required for type recognition
//
%import "../../Rock/swig/rock_swig.i"
%import "../inc/Diamond_Defines.h"

// Include PCH
%begin %{
#include "Diamond_Std.h"
%}

//
// Diamond includes
//
%header %{
#include "Rock.h"
#include "Chalk.h"
#include "Chalk_D3d9.h"
#include "Diamond.h"
%}

//
// Rock interface definitions
//
%include "../inc/Diamond_Core.h"
%include "../inc/Diamond_Scene.h"
%include "../inc/Diamond_Renderer.h"

//
// Expose namespace for depending modules
//
using namespace Diamond;

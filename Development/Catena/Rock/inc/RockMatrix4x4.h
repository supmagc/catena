#ifndef _H_ROCK_MATRIX4X4
#define _H_ROCK_MATRIX4X4

#include "RockDefines.h"

namespace Rock {

	struct ROCK_API Matrix4x4 {

		float m[16];

		Matrix4x4();
		Matrix4x4(Matrix4x4 const& obj);
		~Matrix4x4();

		Matrix4x4& operator=(Matrix4x4 const& obj);
	};

	typedef Matrix4x4 Matrix;
};

#endif // _H_ROCK_MATRIX4X4
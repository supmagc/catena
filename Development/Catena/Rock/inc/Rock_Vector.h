#ifndef _H_ROCK_VECTOR
#define _H_ROCK_VECTOR 1

#include "Rock_Types.h"
#include "Rock_Defines.h"
#include "Rock_Checks.h"

namespace Rock {

    template<typename TVec, RUINT TVecDim>
    struct ROCK_API Vector {
        TVec data[TVecDim];
		
		Vector() {catMemZero(&this, sizeof(TVec) * n);}

		TVec& operator[](RUINT i) {
			CHECK_SLOW_TRUE(i < n);
			CHECK_SLOW_TRUE(i >= 0);
			return data[i];
		}
	};

    template<typename TVec>
    struct ROCK_API Vector < TVec, 2 > {
        union {
            TVec data[2];
            struct { TVec x, y; };
            struct { TVec u, v; };
        };

		Vector() : Vector(0) {}
		Vector(TVec n0) : Vector(n0, n0) {}
		Vector(TVec n0, TVec n1) : x(n0), y(n1) {}

		TVec& operator[](RUINT i) {
			CHECK_SLOW_TRUE(i < 2);
			CHECK_SLOW_TRUE(i >= 0);
			return data[i];
		}
	};

    template<typename TVec>
    struct ROCK_API Vector < TVec, 3 > {
        union {
            TVec data[3];
            struct { TVec x, y, z; };
            struct { TVec r, g, b; };
            Vector<TVec, 2> xy;
            Vector<TVec, 2> uv;
        };

		Vector() : Vector(0) {}
		Vector(TVec n0) : Vector(n0, n0, n0) {}
		Vector(TVec n0, TVec n1, TVec n2) : x(n0), y(n1), z(n2) {}

		TVec& operator[](RUINT i) {
			CHECK_SLOW_TRUE(i < 3);
			CHECK_SLOW_TRUE(i >= 0);
			return data[i];
		}
	};

    template<typename TVec>
    struct ROCK_API Vector < TVec, 4 > {
        union {
            TVec data[4];
            struct { TVec x, y, z, w; };
            struct { TVec r, g, b, a; };
            Vector<TVec, 2> xy;
            Vector<TVec, 2> uv;
            Vector<TVec, 3> xyz;
            Vector<TVec, 3> rgb;
        };

		Vector() : Vector(0) {}
		Vector(TVec n0) : Vector(n0, n0, n0, n0) {}
		Vector(TVec n0, TVec n1, TVec n2, TVec n3) : x(n0), y(n1), z(n2), w(n3) {}

		TVec& operator[](RUINT i) {
			CHECK_SLOW_TRUE(i < 4);
			CHECK_SLOW_TRUE(i >= 0);
			return data[i];
		}
	};

    typedef Vector<RFLOAT, 2> Vec2;
    typedef Vector<RFLOAT, 3> Vec3;
    typedef Vector<RFLOAT, 4> Vec4;
	typedef Vector<RFLOAT, 2> Uv;
	typedef Vector<RFLOAT, 3> ColRgb;
	typedef Vector<RFLOAT, 4> ColRgba;

	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API TNum Length(Vector<TVec, TVecDim> v);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API TNum LengthSq(Vector<TVec, TVecDim> v);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API TNum Distance(Vector<TVec, TVecDim> v0, Vector<TVec, TVecDim> v1);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API TNum Dot(Vector<TVec, TVecDim> v0, Vector<TVec, TVecDim> v1);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API RBOOL operator<(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API RBOOL operator>(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API RBOOL operator<(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API RBOOL operator>(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API RBOOL operator<=(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API RBOOL operator>=(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API RBOOL operator<=(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API RBOOL operator>=(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API Vector<TVec, TVecDim> operator+(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API Vector<TVec, TVecDim> operator-(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API Vector<TVec, TVecDim> operator*(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API Vector<TVec, TVecDim> operator/(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API Vector<TVec, TVecDim> operator+(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API Vector<TVec, TVecDim> operator-(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API Vector<TVec, TVecDim> operator*(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API Vector<TVec, TVecDim> operator/(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API Vector<TVec, TVecDim>& operator+=(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API Vector<TVec, TVecDim>& operator-=(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API Vector<TVec, TVecDim>& operator*=(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim, typename TNum = RFLOAT> INLINE ROCK_API Vector<TVec, TVecDim>& operator/=(Vector<TVec, TVecDim> const& v, TNum n);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API Vector<TVec, TVecDim>& operator+=(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API Vector<TVec, TVecDim>& operator-=(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API Vector<TVec, TVecDim>& operator*=(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API Vector<TVec, TVecDim>& operator/=(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);

	#include "../inl/Vector.inl"
}

#endif // _H_ROCK_VECTOR
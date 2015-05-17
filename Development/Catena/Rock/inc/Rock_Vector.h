#ifndef _H_ROCK_VECTOR
#define _H_ROCK_VECTOR 1

#include "Rock_Types.h"
#include "Rock_Defines.h"
#include "Rock_Checks.h"
#include "Rock_Functions.h"

namespace Rock {

    template<typename TVec, RUINT TVecDim, typename CRTP>
    struct VectorBase {
        INLINE CRTP& Crtp() { return static_cast<CRTP&>(*this); }
        INLINE CRTP const& Crtp() const { return static_cast<CRTP const&>(*this); }

        typedef TVec Type;
        VectorBase() { catMemZero(this, sizeof(TVec) * TVecDim); }

        INLINE TVec& operator[](RUINT i) {
            CHECK_SLOW_TRUE(i < TVecDim);
            CHECK_SLOW_TRUE(i >= 0);
            return Crtp().data[i];
        }

        INLINE TVec const& operator[](RUINT i) const {
            CHECK_SLOW_TRUE(i < TVecDim);
            CHECK_SLOW_TRUE(i >= 0);
            return Crtp().data[i];
        }
    };

    template<typename TVec, RUINT TVecDim>
    struct ROCK_API Vector : VectorBase<TVec, TVecDim, Vector<TVec, TVecDim>> {
        TVec data[TVecDim];
	};

    template<typename TVec>
    struct ROCK_API Vector < TVec, 1 > : VectorBase<TVec, 1, Vector<TVec, 1>>{
        union {
            TVec data[1];
            struct { TVec x; };
            struct { TVec k; };
        };

        Vector() : Vector(0) {}
        explicit Vector(TVec const& n0) : x(n0) {}
    };

    template<typename TVec>
    struct ROCK_API Vector < TVec, 2 > : VectorBase<TVec, 2, Vector<TVec, 2>>{
        union {
            TVec data[2];
            struct { TVec x, y; };
            struct { TVec u, v; };
            struct { TVec k, a; };
        };

		Vector() : Vector(0) {}
        explicit Vector(TVec const& n0) : Vector(n0, n0) {}
        Vector(TVec const& n0, TVec const& n1) : x(n0), y(n1) {}
	};

    template<typename TVec>
    struct ROCK_API Vector < TVec, 3 > : VectorBase<TVec, 3, Vector<TVec, 3>>{
        union {
            TVec data[3];
            struct { TVec x, y, z; };
            struct { TVec r, g, b; };
            Vector<TVec, 2> xy;
            Vector<TVec, 2> uv;
        };

		Vector() : Vector(0) {}
        explicit Vector(TVec const& n0) : Vector(n0, n0, n0) {}
        Vector(TVec const& n0, TVec const& n1, TVec const& n2) : x(n0), y(n1), z(n2) {}
	};

    template<typename TVec>
    struct ROCK_API Vector < TVec, 4 > : VectorBase<TVec, 4, Vector<TVec, 4>>{
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
		explicit Vector(TVec const& n0) : Vector(n0, n0, n0, n0) {}
        Vector(TVec const& n0, TVec const& n1, TVec const& n2, TVec const& n3) : x(n0), y(n1), z(n2), w(n3) {}
	};

    typedef Vector<RFLOAT, 1> Vector1;
    typedef Vector<RFLOAT, 2> Vector2;
    typedef Vector<RFLOAT, 3> Vector3;
    typedef Vector<RFLOAT, 4> Vector4;
	typedef Vector<RFLOAT, 2> Uv;
    typedef Vector<RFLOAT, 1> ColorK;
    typedef Vector<RFLOAT, 2> ColorKa;
    typedef Vector<RFLOAT, 3> ColorRgb;
	typedef Vector<RFLOAT, 4> ColorRgba;
    typedef Vector1 RVector1;
    typedef Vector2 RVector2;
    typedef Vector3 RVector3;
    typedef Vector4 RVector4;
    typedef Vector3 RVector;
    typedef Uv RUv;
    typedef ColorK RColorK;
    typedef ColorKa RColorKa;
    typedef ColorRgb RColorRgb;
    typedef ColorRgba RColorRgba;

    template<typename TVec> INLINE ROCK_API Vector<TVec, 3> CrossLh(Vector<TVec, 3> const& v0, Vector<TVec, 3> const& v1);
    template<typename TVec> INLINE ROCK_API Vector<TVec, 3> CrossRh(Vector<TVec, 3> const& v0, Vector<TVec, 3> const& v1);
    template<typename TVec, RUINT TVecDim> INLINE ROCK_API TVec Length(Vector<TVec, TVecDim> const& v);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API TVec LengthSq(Vector<TVec, TVecDim> const& v);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API TVec Distance(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
	template<typename TVec, RUINT TVecDim> INLINE ROCK_API TVec Dot(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1);
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

namespace VectorMeta {
	// Calculates the sum of the squares of all data elements
	template<typename TVec, RUINT TVecDim, RUINT TIndex>
	struct SquareSum {
		static INLINE TVec f(Vector<TVec, TVecDim> const& v) {
			return v.data[TIndex - 1] * v.data[TIndex - 1] + SquareSum<TVec, TVecDim, TIndex - 1>::f(v);
		};
	};
	template<typename TVec, RUINT TVecDim>
	struct SquareSum<TVec, TVecDim, 1> {
		static INLINE TVec f(Vector<TVec, TVecDim> const& v) {
			return v.data[0] * v.data[0];
		};
	};

	// Calculates the sum of vector parametsr multiplications
	template<typename TVec, RUINT TVecDim, RUINT TIndex>
	struct MultiplySum {
		static INLINE TVec f(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1) {
			return v0.data[TIndex - 1] * v1.data[TIndex - 1] + MultiplySum<TVec, TVecDim, TIndex - 1>::f(v0, v1);
		};
	};
	template<typename TVec, RUINT TVecDim>
	struct MultiplySum<TVec, TVecDim, 1> {
		static INLINE TVec f(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1) {
			return v0.data[0] * v1.data[0];
		};
	};

	// Calculates the sum/subsreaction/multiplication/division of a vector and a scalar
	// Calculates the sum/subsreaction/multiplication/division of two vectors
#define VECTOR_META_OPERATION(name, op) \
	template<typename TVec, RUINT TVecDim, RUINT TIndex, typename TNum> struct Scalar##name { \
		static INLINE void f(Vector<TVec, TVecDim>& v, TNum n) { \
			v.data[TIndex-1] op##= n; \
			Scalar##name<TVec, TVecDim, TIndex - 1, TNum>::f(v, n); \
		}; \
	}; \
	template<typename TVec, RUINT TVecDim, typename TNum> struct Scalar##name<TVec, TVecDim, 1, TNum> { \
		static INLINE void f(Vector<TVec, TVecDim>& v, TNum n) { \
			v.data[0] op##= n; \
		}; \
	}; \
	template<typename TVec, RUINT TVecDim, RUINT TIndex> struct Vector##name { \
		static INLINE void f(Vector<TVec, TVecDim>& v0, Vector<TVec, TVecDim> const& v1) { \
			v0.data[TIndex - 1] op##= v1.data[TIndex - 1]; \
			Vector##name<TVec, TVecDim, TIndex - 1>::f(v0, v1); \
		}; \
	}; \
	template<typename TVec, RUINT TVecDim> struct Vector##name<TVec, TVecDim, 1> { \
		static INLINE void f(Vector<TVec, TVecDim>& v0, Vector<TVec, TVecDim> const& v1) { \
			v0.data[0] op##= v1.data[0]; \
		}; \
	};

VECTOR_META_OPERATION(Add, +)
VECTOR_META_OPERATION(Subtract, -)
VECTOR_META_OPERATION(Multiply, *)
VECTOR_META_OPERATION(Divide, /)

#undef VECTOR_META_OPERATION
}

template<typename TVec, RUINT TVecDim>
INLINE TVec Length(Vector<TVec, TVecDim> const& v) {
	return sqrt(LengthSq(v));
};

template<typename TVec, RUINT TVecDim>
INLINE TVec LengthSq(Vector<TVec, TVecDim> const& v) {
	return VectorMeta::SquareSum<TVec, TVecDim, TVecDim>::f(v);
};

template<typename TVec, RUINT TVecDim>
INLINE TVec Distance(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1) {
	return Length(v0 - v1);
}

template<typename TVec, RUINT TVecDim>
INLINE TVec Dot(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1) {
	return VectorMeta::MultiplySum<TVec, TVecDim, TVecDim>::f(v0, v1);
}

template<typename TVec>
INLINE Vector<TVec, 3> CrossLh(Vector<TVec, 3> const& v0, Vector<TVec, 3> const& v1) {
    return Vector<TVec, 3>(
        v0.data[2] * v1.data[1] - v0.data[1] * v1.data[2],
        v0.data[0] * v1.data[2] - v0.data[2] * v1.data[0],
        v0.data[1] * v1.data[0] - v0.data[0] * v1.data[1]
    );
}

template<typename TVec>
INLINE Vector<TVec, 3> CrossRh(Vector<TVec, 3> const& v0, Vector<TVec, 3> const& v1) {
    return Vector<TVec, 3>(
        v0.data[1] * v1.data[2] - v0.data[2] * v1.data[1],
        v0.data[2] * v1.data[0] - v0.data[0] * v1.data[2],
        v0.data[0] * v1.data[1] - v0.data[1] * v1.data[0]
    );
}

#define VECTOR_COMPARE(comp) \
template<typename TVec, RUINT TVecDim, typename TNum> INLINE RBOOL operator##comp##(Vector<TVec, TVecDim> const& v, TNum n) { \
	return LengthSq(v) comp n*n; \
} \
template<typename TVec, RUINT TVecDim> INLINE RBOOL operator##comp##(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1) { \
	return LengthSq(v0) comp LengthSq(v1); \
}

VECTOR_COMPARE(<)
VECTOR_COMPARE(>)
VECTOR_COMPARE(<=)
VECTOR_COMPARE(>=)

#undef VECTOR_COMPARE

#define VECTOR_OPERATION(name, op) \
template<typename TVec, RUINT TVecDim, typename TNum> INLINE Vector<TVec, TVecDim> operator##op##(Vector<TVec, TVecDim> const& v, TNum n) { \
	Vector<TVec, TVecDim> vReturn(v); \
	vReturn op##= n; \
	return vReturn; \
} \
template<typename TVec, RUINT TVecDim> INLINE Vector<TVec, TVecDim> operator##op##(Vector<TVec, TVecDim> const& v0, Vector<TVec, TVecDim> const& v1) { \
	Vector<TVec, TVecDim> vReturn(v0); \
	vReturn op##= v1; \
	return vReturn; \
} \
template<typename TVec, RUINT TVecDim, typename TNum> INLINE Vector<TVec, TVecDim>& operator##op##=(Vector<TVec, TVecDim>& v, TNum n) { \
	VectorMeta::Scalar##name##<TVec, TVecDim, TVecDim, TNum>::f(v, n); \
	return v; \
} \
template<typename TVec, RUINT TVecDim> INLINE Vector<TVec, TVecDim>& operator##op##=(Vector<TVec, TVecDim>& v0, Vector<TVec, TVecDim> const& v1) { \
	VectorMeta::Vector##name##<TVec, TVecDim, TVecDim>::f(v0, v1); \
	return v0; \
}

VECTOR_OPERATION(Add, +)
VECTOR_OPERATION(Subtract, -)
VECTOR_OPERATION(Multiply, *)
VECTOR_OPERATION(Divide, /)

#undef VECTOR_OPERATION

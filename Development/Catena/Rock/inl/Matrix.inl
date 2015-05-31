// Seperate namespace to keep template expansion code away
namespace MatrixMeta {

    // Set identity values
    template<typename TMat, RUINT TMatRows, RUINT TMatColumns, RUINT TIndex>
    struct Identity {
        static INLINE void f(Matrix<TMat, TMatRows, TMatColumns>& m, TMat const& n) {
            m.data[TIndex][TIndex] = n;
            Identity<TMat, TMatRows, TMatColumns, TIndex - 1>::f(m, n);
        };
    };
    template<typename TMat, RUINT TMatRows, RUINT TMatColumns>
    struct Identity<TMat, TMatRows, TMatColumns, 0> {
        static INLINE void f(Matrix<TMat, TMatRows, TMatColumns>& m, TMat const& n) {
            m.data[0][0] = n;
        };
    };
}

template<typename TMat, RUINT TMatRows, RUINT TMatColumns>
INLINE Matrix<TMat, TMatRows, TMatColumns> Matrix<TMat, TMatRows, TMatColumns>::Identity() {
    Matrix<TMat, TMatRows, TMatColumns> m;
    if(TMatRows > TMatColumns)
        MatrixMeta::Identity<TMat, TMatRows, TMatColumns, TMatColumns - 1>::f(m, (TMat)1);
    else
        MatrixMeta::Identity<TMat, TMatRows, TMatColumns, TMatRows - 1>::f(m, (TMat)1);
    return m;
}
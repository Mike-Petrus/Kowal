#pragma once

#include <linalg.h>

namespace vam{

    // linalg::vec<T, M> defines a fixed-length vector containg exactly M elements of type T
    template<int N, class T> using Vec = linalg::vec<T, N>;

    template<class T> using Vec2 = Vec<2, T>;
    using Vec2f = Vec2<float>;
    using Vec2i = Vec2<int>;

    template<class T> using Vec3 = Vec<3, T>;
    using Vec3f = Vec3<float>;
    using Vec3i = Vec3<int>;

    //linalg::mat<T, M, N> defines a fixed-sized matrix containing exactly M rows and N columns of type T, in column-major order
    template<class T, int M, int N> using Mat = linalg::mat<T, M, N>;

    template<class T> using Mat2 = Mat<T, 2, 2>;
    using Mat2f = Mat2<float>;

    template<class T> using Mat3 = Mat<T, 3, 3>;
    using Mat3f = Mat3<float>;
}
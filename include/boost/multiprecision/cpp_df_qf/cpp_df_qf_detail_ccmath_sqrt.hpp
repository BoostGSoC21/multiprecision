///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2023 - 2024.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_SQRT_2023_01_07_HPP
#define BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_SQRT_2023_01_07_HPP

#include <cmath>
#include <type_traits>

namespace boost { namespace multiprecision { namespace backends { namespace cpp_df_qf_detail { namespace ccmath {

namespace detail {

template <class T>
auto sqrt_impl(T x) -> typename std::enable_if<std::is_same<float, T>::value ||
                                               std::is_same<double, T>::value ||
                                               std::is_same<long double, T>::value, T>::type
{
   // Default to the quadmath qsqrt function.
   using std::sqrt;

   return sqrt(x);
}

#if defined(BOOST_MP_CPP_DOUBLE_FP_HAS_FLOAT128)
template <class T>
auto sqrt_impl(T x) -> typename std::enable_if<std::is_same<::boost::float128_type, T>::value, T>::type
{
   // Default to the regular sqrt function.
   return ::sqrtq(x);
}
#endif

} // namespace detail

template <typename Real>
auto sqrt(Real x) -> Real
{
   return cpp_df_qf_detail::ccmath::detail::sqrt_impl<Real>(x);
}

} } } } } // namespace boost::multiprecision::backends::cpp_df_qf_detail::ccmath

#endif // BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_SQRT_2023_01_07_HPP

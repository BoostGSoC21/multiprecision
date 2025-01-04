///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2024.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_FLOOR_2024_12_30_HPP
#define BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_FLOOR_2024_12_30_HPP

#include <cmath>
#include <type_traits>

namespace boost { namespace multiprecision { namespace backends { namespace cpp_df_qf_detail { namespace ccmath {

namespace detail {

template <class T>
auto floor_impl(T x) -> typename std::enable_if<std::is_same<float, T>::value ||
                                               std::is_same<double, T>::value ||
                                               std::is_same<long double, T>::value, T>::type
{
   // Default to the regular floor function.
   using std::floor;

   return floor(x);
}

#if defined(BOOST_MP_CPP_DOUBLE_FP_HAS_FLOAT128)
template <class T>
auto floor_impl(T x) -> typename std::enable_if<std::is_same<::boost::float128_type, T>::value, T>::type
{
   // Default to the quadmath floorq function.

   return ::floorq(x);
}
#endif

} // namespace detail

template <typename Real>
auto floor(Real x) -> Real
{
   return cpp_df_qf_detail::ccmath::detail::floor_impl<Real>(x);
}

} } } } } // namespace boost::multiprecision::backends::cpp_df_qf_detail::ccmath

#endif // BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_FLOOR_2024_12_30_HPP

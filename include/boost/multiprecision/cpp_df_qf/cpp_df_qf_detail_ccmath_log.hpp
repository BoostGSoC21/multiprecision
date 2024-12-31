///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2024.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_LOG_2024_12_30_HPP
#define BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_LOG_2024_12_30_HPP

#include <cmath>
#include <type_traits>

namespace boost { namespace multiprecision { namespace backends { namespace cpp_df_qf_detail { namespace ccmath {

namespace detail {

#if defined(BOOST_HAS_FLOAT128)
template <class T>
auto log_impl(T x) -> typename ::std::enable_if<::std::is_same<T, ::boost::float128_type>::value, T>::type
{
   return ::logq(x);
}
#endif

template <class T>
auto log_impl(T x) -> typename ::std::enable_if<::std::is_floating_point<T>::value, T>::type
{
   // Default to the regular std::log function.
   using std::log;

   return log(x);
}

} // namespace detail

template <typename Real>
auto log(Real x) -> Real
{
   return cpp_df_qf_detail::ccmath::detail::log_impl<Real>(x);
}

} } } } } // namespace boost::multiprecision::backends::cpp_df_qf_detail::ccmath

#endif // BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_LOG_2024_12_30_HPP
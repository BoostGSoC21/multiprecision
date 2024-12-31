///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2023 - 2024.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_LDEXP_2023_01_07_HPP
#define BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_LDEXP_2023_01_07_HPP

#include <cmath>
#include <type_traits>

namespace boost { namespace multiprecision { namespace backends { namespace cpp_df_qf_detail { namespace ccmath {

namespace detail {

#if defined(BOOST_HAS_FLOAT128)
template <class T>
auto ldexp_impl(T arg, int expval) -> typename ::std::enable_if<::std::is_same<T, ::boost::float128_type>::value, T>::type
{
   return ::ldexpq(arg, expval);
}
#endif

template <class T>
auto ldexp_impl(T arg, int expval) -> typename ::std::enable_if<::std::is_floating_point<T>::value, T>::type
{
   // Default to the regular std::ldexp function.
   using std::ldexp;

   return ldexp(arg, expval);
}

} // Namespace detail

template <typename Real>
auto ldexp(Real arg, int expval) -> Real
{
   return detail::ldexp_impl(arg, expval);
}

} } } } } // namespace boost::multiprecision::backends::cpp_df_qf_detail::ccmath

#endif // BOOST_MP_CPP_DF_QF_DETAIL_CCMATH_LDEXP_2023_01_07_HPP

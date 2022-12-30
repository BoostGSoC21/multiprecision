///////////////////////////////////////////////////////////////////////////////
//  Copyright 2021 Fahad Syed.
//  Copyright 2021 Christopher Kormanyos.
//  Copyright 2021 Janek Kozicki.
//  Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_MP_CPP_DOUBLE_FP_BACKEND_2021_06_05_HPP
#define BOOST_MP_CPP_DOUBLE_FP_BACKEND_2021_06_05_HPP

#include <boost/config.hpp>

#include <limits>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

#if defined(BOOST_MATH_USE_FLOAT128)
#include <boost/multiprecision/float128.hpp>
#endif
#include <boost/multiprecision/number.hpp>
#include <boost/multiprecision/detail/float_string_cvt.hpp>
#include <boost/multiprecision/detail/hash.hpp>
#include <boost/multiprecision/traits/max_digits10.hpp>

namespace boost { namespace multiprecision { namespace backends {

template <typename FloatingPointType>
class cpp_double_fp_backend;

namespace detail {

template <class T>
struct is_arithmetic_or_float128
{
   static constexpr bool value = ((std::is_arithmetic<T>::value == true)
#if defined(BOOST_MATH_USE_FLOAT128)
                                  || (std::is_same<typename std::decay<T>::type, boost::multiprecision::float128>::value == true)
#endif
   );
};

template <class T>
struct is_floating_point_or_float128
{
   static constexpr bool value = ((std::is_floating_point<T>::value == true)
#if defined(BOOST_MATH_USE_FLOAT128)
                                  || (std::is_same<typename std::decay<T>::type, boost::multiprecision::float128>::value == true)
#endif
   );
};

} // namespace detail

template <typename FloatingPointType>
inline cpp_double_fp_backend<FloatingPointType> operator+(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);
template <typename FloatingPointType>
inline cpp_double_fp_backend<FloatingPointType> operator-(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);
template <typename FloatingPointType>
inline cpp_double_fp_backend<FloatingPointType> operator*(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);
template <typename FloatingPointType>
inline cpp_double_fp_backend<FloatingPointType> operator/(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);

template <typename FloatingPointType>
cpp_double_fp_backend<FloatingPointType> operator+(const cpp_double_fp_backend<FloatingPointType>& a, const FloatingPointType& b);
template <typename FloatingPointType>
cpp_double_fp_backend<FloatingPointType> operator-(const cpp_double_fp_backend<FloatingPointType>& a, const FloatingPointType& b);
template <typename FloatingPointType>
cpp_double_fp_backend<FloatingPointType> operator*(const cpp_double_fp_backend<FloatingPointType>& a, const FloatingPointType& b);
template <typename FloatingPointType>
cpp_double_fp_backend<FloatingPointType> operator/(const cpp_double_fp_backend<FloatingPointType>& a, const FloatingPointType& b);

template <typename FloatingPointType>
inline bool operator<(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);
template <typename FloatingPointType>
inline bool operator<=(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);
template <typename FloatingPointType>
inline bool operator==(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);
template <typename FloatingPointType>
inline bool operator!=(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);
template <typename FloatingPointType>
inline bool operator>=(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);
template <typename FloatingPointType>
inline bool operator>(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);

template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR void eval_add(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x);
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR void eval_subtract(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x);
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR void eval_multiply(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x);
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR void eval_divide(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x);
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR bool eval_eq(cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR bool eval_lt(cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR bool eval_gt(cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b);
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR bool eval_is_zero(cpp_double_fp_backend<FloatingPointType>& x);

template <typename FloatingPointType>
void eval_fabs(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& a);
template <typename FloatingPointType>
void eval_frexp(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& a, int* v);
template <typename FloatingPointType>
void eval_ldexp(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& a, int v);
template <typename FloatingPointType>
void eval_floor(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x);
template <typename FloatingPointType>
void eval_ceil(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x);
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR int eval_fpclassify(const cpp_double_fp_backend<FloatingPointType>& o);
template <typename FloatingPointType>
void eval_sqrt(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& o);

template <typename FloatingPointType,
          typename std::enable_if<((detail::is_floating_point_or_float128<FloatingPointType>::value == true) && ((std::numeric_limits<FloatingPointType>::digits10 * 2) < 16))>::type const* = nullptr>
void eval_exp(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x);

template <typename FloatingPointType,
          typename std::enable_if<((detail::is_floating_point_or_float128<FloatingPointType>::value == true) && (((std::numeric_limits<FloatingPointType>::digits10 * 2) >= 16) && ((std::numeric_limits<FloatingPointType>::digits10 * 2) <= 36)))>::type const* = nullptr>
void eval_exp(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x);

template <typename FloatingPointType,
          typename std::enable_if<((detail::is_floating_point_or_float128<FloatingPointType>::value == true) && ((std::numeric_limits<FloatingPointType>::digits10 * 2) > 36))>::type const* = nullptr>
void eval_exp(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x);

template <typename FloatingPointType>
void eval_log(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x);

template <typename FloatingPointType,
          typename R>
typename std::enable_if<std::is_integral<R>::value == true>::type eval_convert_to(R* result, const cpp_double_fp_backend<FloatingPointType>& backend);

template <typename FloatingPointType,
          typename R>
typename std::enable_if<std::is_integral<R>::value == false>::type eval_convert_to(R* result, const cpp_double_fp_backend<FloatingPointType>& backend);

template <typename FloatingPointType,
          typename char_type,
          typename traits_type>
std::basic_ostream<char_type, traits_type>& operator<<(std::basic_ostream<char_type, traits_type>& os,
                                                       const cpp_double_fp_backend<FloatingPointType>&  f);

template <typename FloatingPointType>
std::size_t hash_value(const cpp_double_fp_backend<FloatingPointType>& a);

template <typename FloatingPointType>
cpp_double_fp_backend<FloatingPointType> fabs(const cpp_double_fp_backend<FloatingPointType>& a);

}}} // namespace boost::multiprecision::backends

namespace boost { namespace math {

template <typename FloatingPointType>
int(fpclassify)(const boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>& o);

}} // namespace boost::math

namespace std {

// Foward declarations of various specializations of std::numeric_limits

template <typename FloatingPointType,
          const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
class numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >;

} // namespace std

namespace boost { namespace multiprecision {

template <typename FloatingPointType>
struct number_category<backends::cpp_double_fp_backend<FloatingPointType> >
    : public std::integral_constant<int, number_kind_floating_point>
{};

namespace backends {

namespace detail {

template <typename R>
typename std::enable_if<std::is_unsigned<R>::value == false, R>::type minus_max()
{
   return std::is_signed<R>::value ? (std::numeric_limits<R>::min)() : -(std::numeric_limits<R>::max)();
}

template <typename R>
typename std::enable_if<std::is_unsigned<R>::value == true, R>::type minus_max()
{
   return 0;
}

template <typename FloatingPointType>
struct exact_arithmetic
{
   // The exact_arithmetic<> struct implements extended precision
   // techniques that are used in cpp_double_fp_backend and cpp_quad_float.

   static_assert(detail::is_floating_point_or_float128<FloatingPointType>::value == true,
                 "Error: exact_arithmetic<> invoked with unknown floating-point type");

   using float_type  = FloatingPointType;
   using float_pair  = std::pair<float_type, float_type>;
   using float_tuple = std::tuple<float_type, float_type, float_type, float_type>;

   static BOOST_MP_CXX14_CONSTEXPR float_pair split(const float_type& a)
   {
      // Split a floating point number in two (high and low) parts approximating the
      // upper-half and lower-half bits of the float

      static_assert(detail::is_floating_point_or_float128<FloatingPointType>::value == true,
                    "Error: exact_arithmetic<>::split invoked with unknown floating-point type");

      // TODO Replace bit shifts with constexpr funcs or ldexp for better compaitibility
      constexpr int MantissaBits = std::numeric_limits<float_type>::digits;
      constexpr int SplitBits    = MantissaBits / 2 + 1;

      // Check if the integer is wide enough to hold the Splitter.
      static_assert(std::numeric_limits<uintmax_t>::digits > SplitBits,
                    "Inadequate integer width for binary shifting needed in split(), try using ldexp instead");

      // If the above line gives an compilation error, replace the
      // line below it with the commented line

      constexpr float_type Splitter       = FloatingPointType((uintmax_t(1) << SplitBits) + 1);
      const     float_type SplitThreshold = (std::numeric_limits<float_type>::max)() / (Splitter * 2);

      float_type temp, hi, lo;

      // Handle if multiplication with the splitter would cause overflow
      if (a > SplitThreshold || a < -SplitThreshold)
      {
         constexpr float_type Normalizer = float_type(1ULL << (SplitBits + 1));

         const float_type a_ = a / Normalizer;

         temp = Splitter * a_;
         hi   = temp - (temp - a_);
         lo   = a_ - hi;

         hi *= Normalizer;
         lo *= Normalizer;
      }
      else
      {
         temp = Splitter * a;
         hi   = temp - (temp - a);
         lo   = a - hi;
      }

      return std::make_pair(hi, lo);
   }

   static BOOST_MP_CXX14_CONSTEXPR float_pair fast_sum(const float_type& a, const float_type& b)
   {
      // Exact addition of two floating point numbers, given |a| > |b|
      const float_type a_plus_b = a + b;

      return float_pair(a_plus_b, b - (a_plus_b - a));
   }

   static BOOST_MP_CXX14_CONSTEXPR float_pair sum(const float_type& a, const float_type& b)
   {
      // Exact addition of two floating point numbers
      const float_type a_plus_b = a + b;
      const float_type v        = a_plus_b - a;

      return float_pair(a_plus_b, (a - (a_plus_b - v)) + (b - v));
   }

   static BOOST_MP_CXX14_CONSTEXPR void three_sum(float_type& a, float_type& b, float_type& c)
   {
      using std::get;
      using std::tie;

      std::tuple<float_type, float_type, float_type> t;

      tie(get<0>(t), get<1>(t)) = sum(a, b);
      tie(a, get<2>(t))         = sum(c, get<0>(t));
      tie(b, c)                 = sum(get<1>(t), get<2>(t));
   }

   static BOOST_MP_CXX14_CONSTEXPR void sum(float_pair& p, float_type& e)
   {
      using std::tie;

      float_pair t;
      float_type t_;

      t                = sum(p.first, p.second);
      tie(p.first, t_) = sum(e, t.first);
      tie(p.second, e) = sum(t.second, t_);
   }

   static BOOST_MP_CXX14_CONSTEXPR float_tuple four_sum(float_type a, float_type b, float_type c, float_type d)
   {
      float_tuple out = std::make_tuple(a, b, c, d);
      normalize(out);
      return out;
   }

   static BOOST_MP_CXX14_CONSTEXPR float_pair difference(const float_type& a, const float_type& b)
   {
      // Exact subtraction of two floating point numbers
      const float_type a_minus_b = a - b;
      const float_type v         = a_minus_b - a;

      return float_pair(a_minus_b, (a - (a_minus_b - v)) - (b + v));
   }

   static BOOST_MP_CXX14_CONSTEXPR float_pair product(const float_type& a, const float_type& b)
   {
      // Exact product of two floating point numbers
      const float_pair a_split = split(a);
      const float_pair b_split = split(b);

      const volatile float_type pf = a * b;

      return
        std::make_pair
        (
          const_cast<const float_type&>(pf),
            (
                ((a_split.first  * b_split.first) - const_cast<const float_type&>(pf))
              +  (a_split.first  * b_split.second)
              +  (a_split.second * b_split.first)
            )
          +
            (a_split.second * b_split.second)
        );
   }

   static BOOST_MP_CXX14_CONSTEXPR void normalize(float_pair& p, bool fast = true)
   {
      // Converts a pair of floats to standard form.

      p = (fast ? fast_sum(p.first, p.second) : sum(p.first, p.second));
   }

   static void extra_normalize(float_pair& p)
   {
      // TODO: discuss ?
      // If exponent of the second component is farther away than digits represented by this type
      // then means that these "dangling" bits should be zero.
      int e1 { };
      int e2 { };

      using std::frexp;

      frexp(p.first, &e1);
      frexp(p.second, &e2);

      // Interesting: when we set   digits = 2 * <digits of underlying type>
      // then this extra normalize, to work with DecomposedReal guard_bits
      // needs the subtraction of 2 here.
      if ((e1 - e2) > cpp_double_fp_backend<float_type>::my_digits - 2)
      {
         p.second = 0;
      }
      // ... maybe even better would be to zero all the bits further away than cpp_double_fp_backend<float_type>>::digits away
      // not only when entire p.second is too far.
      // FIXME - currently I have no idea how to implement this efficiently. But for debugging maybe even the super slow (with frexp, ldexp) implementation will help in edge cases...
      // best would be doing & operation on a bitmask..... But can we make sure that would work on all architectures?
   }

   static BOOST_MP_CXX14_CONSTEXPR void normalize(float_tuple& t)
   {
      using std::get;
      using std::tie;

      float_tuple s(float_type(0.0F), float_type(0.0F), float_type(0.0F), float_type(0.0F));

      tie(get<0>(s), get<3>(t)) = fast_sum(get<2>(t), get<3>(t));
      tie(get<0>(s), get<2>(t)) = fast_sum(get<1>(t), get<0>(s));
      tie(get<0>(t), get<1>(t)) = fast_sum(get<0>(t), get<0>(s));

      tie(get<0>(s), get<1>(s)) = std::make_tuple(get<0>(t), get<1>(t));

      if (get<1>(s) != 0)
      {
         tie(get<1>(s), get<2>(s)) = fast_sum(get<1>(s), get<2>(t));

         (get<2>(s) != 0) ? tie(get<2>(s), get<3>(s)) = fast_sum(get<2>(s), get<3>(t))
                          : tie(get<1>(s), get<2>(s)) = fast_sum(get<1>(s), get<3>(t));
      }
      else
      {
         tie(get<0>(s), get<1>(s)) = fast_sum(get<0>(s), get<2>(t));

         (get<1>(s) != 0) ? tie(get<1>(s), get<2>(s)) = fast_sum(get<1>(s), get<3>(t))
                          : tie(get<0>(s), get<1>(s)) = fast_sum(get<0>(s), get<3>(t));
      }

      t = s;
   }

   static BOOST_MP_CXX14_CONSTEXPR void normalize(float_tuple& t, float_type e)
   {
      using std::get;
      using std::tie;

      float_tuple s(float_type(0.0F), float_type(0.0F), float_type(0.0F), float_type(0.0F));

      tie(get<0>(s), e)         = fast_sum(get<3>(t), e);
      tie(get<0>(s), get<3>(t)) = fast_sum(get<2>(t), get<0>(s));
      tie(get<0>(s), get<2>(t)) = fast_sum(get<1>(t), get<0>(s));
      tie(get<0>(t), get<1>(t)) = fast_sum(get<0>(t), get<0>(s));

      tie(get<0>(s), get<1>(s)) = std::make_tuple(get<0>(t), get<1>(t));

      if (get<1>(s) != 0)
      {
         tie(get<1>(s), get<2>(s)) = fast_sum(get<1>(s), get<2>(t));

         if (get<2>(s) != 0)
         {
            tie(get<2>(s), get<3>(s)) = fast_sum(get<2>(s), get<3>(t));

            if(get<3>(s) != 0)
            {
              get<3>(s) += e;
            }
            else
            {
              tie(get<2>(s), get<3>(s)) = fast_sum(get<2>(s), e);
            }
         }
         else
         {
            tie(get<1>(s), get<2>(s)) = fast_sum(get<1>(s), get<3>(t));

            (get<2>(s) != 0) ? tie(get<2>(s), get<3>(s)) = fast_sum(get<2>(s), e)
                             : tie(get<1>(s), get<2>(s)) = fast_sum(get<1>(s), e);
         }
      }
      else
      {
         tie(get<0>(s), get<1>(s)) = fast_sum(get<0>(s), get<2>(t));

         if (get<1>(s) != 0)
         {
            tie(get<1>(s), get<2>(s)) = fast_sum(get<1>(s), get<3>(t));

            (get<2>(s) != 0) ? tie(get<2>(s), get<3>(s)) = fast_sum(get<2>(s), e)
                             : tie(get<1>(s), get<2>(s)) = fast_sum(get<1>(s), e);
         }
         else
         {
            tie(get<0>(s), get<1>(s)) = fast_sum(get<0>(s), get<3>(t));

            (get<1>(s) != 0) ? tie(get<1>(s), get<2>(s)) = fast_sum(get<1>(s), e)
                             : tie(get<0>(s), get<1>(s)) = fast_sum(get<0>(s), e);
         }
      }

      t = s;
   }
};

} // namespace detail

// A cpp_double_fp_backend is represented by an unevaluated sum of two floating-point
// units (say a0 and a1) which satisfy |a1| <= (1 / 2) * ulp(a0).
// The type of the floating-point constituents should adhere to IEEE754.

template <typename FloatingPointType>
class cpp_double_fp_backend
{
 public:
   using float_type = FloatingPointType;
   using rep_type   = std::pair<float_type, float_type>;
   using arithmetic = detail::exact_arithmetic<float_type>;

   using signed_types   = std::tuple<signed char, signed short, signed int, signed long, signed long long, std::intmax_t>;
   using unsigned_types = std::tuple<unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long, std::uintmax_t>;
   using float_types    = std::tuple<float, double, long double>;
   using exponent_type  = int;

   static constexpr int my_digits         = 2 * std::numeric_limits<float_type>::digits;
   static constexpr int my_digits10       = boost::multiprecision::detail::calc_digits10<my_digits>::value;
   static constexpr int my_max_digits10   = boost::multiprecision::detail::calc_max_digits10<my_digits>::value;
   static constexpr int my_max_exponent   = std::numeric_limits<float_type>::max_exponent;
   static constexpr int my_min_exponent   = std::numeric_limits<float_type>::min_exponent + std::numeric_limits<float_type>::digits;
   static constexpr int my_max_exponent10 = (int)(float(my_max_exponent) * 0.301F);
   static constexpr int my_min_exponent10 = (int)(float(my_min_exponent) * 0.301F);

   static_assert(((my_max_exponent - my_digits) >= 77),
                 "Error: floating-point constituent does not have wide enough exponent range");

   // Default constructor.
   constexpr cpp_double_fp_backend() { }

   // Copy constructor.
   constexpr cpp_double_fp_backend(const cpp_double_fp_backend& other) : data(other.data) {}

   // Constructors from other floating-point types.
   template <typename OtherFloatType,
             typename std::enable_if<(detail::is_floating_point_or_float128<OtherFloatType>::value == true) && (std::numeric_limits<OtherFloatType>::digits <= std::numeric_limits<float_type>::digits)>::type const* = nullptr>
   constexpr cpp_double_fp_backend(const OtherFloatType& f) : data(std::make_pair(f, static_cast<float_type>(0.0F))) { }

   template <typename OtherFloatType,
             typename std::enable_if<((detail::is_floating_point_or_float128<OtherFloatType>::value == true) && (std::numeric_limits<OtherFloatType>::digits > std::numeric_limits<float_type>::digits))>::type const* = nullptr>
   constexpr cpp_double_fp_backend(const OtherFloatType& f)
       : data(std::make_pair(static_cast<float_type>(f),
                             static_cast<float_type>(f - (OtherFloatType) static_cast<float_type>(f)))) { }

   // Constructor from other cpp_double_fp_backend<> objects.
   template <typename OtherFloatType,
             typename std::enable_if<((detail::is_floating_point_or_float128<OtherFloatType>::value == true) && (std::is_same<FloatingPointType, OtherFloatType>::value == false))>::type const* = nullptr>
   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend(const cpp_double_fp_backend<OtherFloatType>& a)
       : cpp_double_fp_backend(a.my_first())
   {
      // TBD: Maybe specialize this constructor for cases either wider or less wide.
      *this += a.my_second();
   }

   // Constructors from integers
   template <typename SignedIntegralType,
             typename std::enable_if<(   (std::is_integral<SignedIntegralType>::value == true)
                                      && (std::is_unsigned<SignedIntegralType>::value == false)
                                      && (std::numeric_limits<SignedIntegralType>::digits + 1 <= std::numeric_limits<float_type>::digits))>::type const* = nullptr>
   constexpr cpp_double_fp_backend(const SignedIntegralType& n)
      : data(std::make_pair(static_cast<float_type>(n), static_cast<float_type>(0.0F))) { }

   template <typename UnsignedIntegralType,
             typename std::enable_if<(   (std::is_integral<UnsignedIntegralType>::value == true)
                                      && (std::is_unsigned<UnsignedIntegralType>::value == true)
                                      && (std::numeric_limits<UnsignedIntegralType>::digits <= std::numeric_limits<float_type>::digits))>::type const* = nullptr>
   constexpr cpp_double_fp_backend(const UnsignedIntegralType& u)
      : data(std::make_pair(static_cast<float_type>(u), static_cast<float_type>(0.0F))) { }

   // Constructors from integers which hold more information than *this can contain
   template <typename SignedIntegralType,
             typename std::enable_if<(   (std::is_integral<SignedIntegralType>::value == true)
                                      && (std::is_unsigned<SignedIntegralType>::value == false)
                                      && (std::numeric_limits<SignedIntegralType>::digits + 1 > std::numeric_limits<float_type>::digits))>::type const* = nullptr>
   constexpr cpp_double_fp_backend(SignedIntegralType n)
      : data
        (
           std::make_pair
           (
              static_cast<float_type>(n),
              static_cast<float_type>(n - static_cast<SignedIntegralType>(static_cast<float_type>(n)))
           )
        ) { }

   template <typename UnsignedIntegralType,
             typename std::enable_if<(   (std::is_integral<UnsignedIntegralType>::value == true)
                                      && (std::is_unsigned<UnsignedIntegralType>::value == true)
                                      && (std::numeric_limits<UnsignedIntegralType>::digits > std::numeric_limits<float_type>::digits))>::type const* = nullptr>
   constexpr cpp_double_fp_backend(UnsignedIntegralType u)
      : data
        (
           std::make_pair
           (
              static_cast<float_type>(u),
              static_cast<float_type>(typename std::make_signed<UnsignedIntegralType>::type(u - static_cast<UnsignedIntegralType>(static_cast<float_type>(u))))
           )
        ) { }

   constexpr cpp_double_fp_backend(const float_type& a, const float_type& b) noexcept : data(std::make_pair(a, b)) { }

   constexpr cpp_double_fp_backend(const std::pair<float_type, float_type>& p) noexcept : data(p) { }

   cpp_double_fp_backend(const std::string& str)
   {
      boost::multiprecision::detail::convert_from_string(*this, str.c_str());
   }

   cpp_double_fp_backend(const char* pstr)
   {
      boost::multiprecision::detail::convert_from_string(*this, pstr);
   }

   constexpr cpp_double_fp_backend(cpp_double_fp_backend&& other) noexcept : data(other.data) { }

   std::size_t hash() const
   {
      // Here we first convert to scientific string, then
      // hash the charactgers in the scientific string.
      // TBD: Is there a faster or more simple hash method?

      const std::string str_to_hash = str(cpp_double_fp_backend::my_digits10, std::ios::scientific);

      std::size_t result = 0;

      for (std::string::size_type i = 0U; i < str_to_hash.length(); ++i)
      {
         boost::multiprecision::detail::hash_combine(result, str_to_hash.at(i));
      }

      return result;
   }

   // Methods
   constexpr bool is_neg() const { return (data.first < 0); }

   constexpr bool is_zero() const { return (compare(cpp_double_fp_backend(0U)) == 0); }
   constexpr bool is_one () const { return (compare(cpp_double_fp_backend(1U)) == 0); }

   BOOST_MP_CXX14_CONSTEXPR void negate()
   {
      data.first  = -data.first;
      data.second = -data.second;

      arithmetic::normalize(data);
   }

   // Getters/Setters
   constexpr const float_type& my_first () const noexcept { return data.first; }
   constexpr const float_type& my_second() const noexcept { return data.second; }

   BOOST_MP_CXX14_CONSTEXPR       rep_type& rep ()       noexcept { return data; }
   BOOST_MP_CXX14_CONSTEXPR const rep_type& rep () const noexcept { return data; }
   BOOST_MP_CXX14_CONSTEXPR const rep_type& crep() const noexcept { return data; }

   std::string raw_str() const
   {
      // Retrieve debug string.

      std::stringstream ss;
      ss << std::hexfloat << std::showpos << data.first << " + " << std::hexfloat << data.second;
      return ss.str();
   }

   // Assignment operators.
   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator=(const cpp_double_fp_backend& other)
   {
      if (this != &other)
      {
         data = other.data;
      }

      return *this;
   }

   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator=(cpp_double_fp_backend&& other)
   {
      data = other.data;

      return *this;
   }

   // Non-member add/sub/mul/div with constituent type.
   friend BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend operator+(const cpp_double_fp_backend& a, const float_type& b)
   {
      using other_cpp_double_float_type = cpp_double_fp_backend<float_type>;

      typename other_cpp_double_float_type::rep_type s = other_cpp_double_float_type::arithmetic::sum(a.my_first(), b);

      s.second += a.my_second();
      other_cpp_double_float_type::arithmetic::normalize(s);

      return other_cpp_double_float_type(s);
   }

   friend BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend operator-(const cpp_double_fp_backend& a, const float_type& b)
   {
      using other_cpp_double_float_type = cpp_double_fp_backend<float_type>;

      typename other_cpp_double_float_type::rep_type s = other_cpp_double_float_type::arithmetic::difference(a.my_first(), b);

      s.second += a.my_second();

      other_cpp_double_float_type::arithmetic::normalize(s);

      return other_cpp_double_float_type(s);
   }

   friend BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend operator*(const cpp_double_fp_backend& a, const float_type& b)
   {
      using other_cpp_double_float_type = cpp_double_fp_backend<float_type>;

      typename other_cpp_double_float_type::rep_type p = other_cpp_double_float_type::arithmetic::product(a.my_first(), b);

      using boost::multiprecision::isfinite;
      using std::isfinite;

      if ((isfinite)(p.first) == false)
      {
         return other_cpp_double_float_type(p);
      }

      p.second += a.my_second() * b;

      other_cpp_double_float_type::arithmetic::normalize(p);

      return other_cpp_double_float_type(p);
   }

   friend BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend operator/(const cpp_double_fp_backend& a, const float_type& b)
   {
      using other_cpp_double_float_type = cpp_double_fp_backend<float_type>;

      typename other_cpp_double_float_type::rep_type p, q, s;

      p.first = a.my_first() / b;

      q = other_cpp_double_float_type::arithmetic::product(p.first, b);
      s = other_cpp_double_float_type::arithmetic::difference(a.my_first(), q.first);

      s.second += a.my_second();
      s.second -= q.second;

      p.second = (s.first + s.second) / b;

      other_cpp_double_float_type::arithmetic::normalize(p);

      return other_cpp_double_float_type(p);
   }

   // Unary add/sub/mul/div with constituent part.
   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator+=(const float_type& a)
   {
      *this = *this + a;
      return *this;
   }

   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator-=(const float_type& a)
   {
      *this = *this - a;
      return *this;
   }

   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator*=(const float_type& a)
   {
      *this = *this * a;
      return *this;
   }

   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator/=(const float_type& a)
   {
      *this = *this / a;
      return *this;
   }

   // Unary add/sub/mul/div.
   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator+=(const cpp_double_fp_backend& other)
   {
      using boost::multiprecision::isfinite;
      using std::isfinite;

      float_type sec = my_second();
      data = arithmetic::sum(my_first(), other.my_first());

      if(!((isfinite)(my_first())))
      {
         return *this;
      }

      const rep_type t = arithmetic::sum(sec, other.my_second());

      data.second += t.first;
      arithmetic::normalize(data);
      data.second += t.second;
      arithmetic::normalize(data);

      return *this;
   }

   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator-=(const cpp_double_fp_backend& other)
   {
      using boost::multiprecision::isfinite;
      using std::isfinite;

      float_type sec = my_second();
      data = arithmetic::difference(my_first(), other.my_first());

      if ((isfinite)(my_first()) == false)
         return *this;

      const rep_type t = arithmetic::difference(sec, other.my_second());

      data.second += t.first;
      arithmetic::normalize(data);

      data.second += t.second;
      arithmetic::normalize(data);

      return *this;
   }

   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator*=(const cpp_double_fp_backend& other)
   {
      rep_type tmp = arithmetic::product(data.first, other.data.first);

      tmp.second += (data.first * other.data.second + data.second * other.data.first);

      data = tmp;

      return *this;
   }

   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator/=(const cpp_double_fp_backend& other)
   {
      rep_type p;

      // First approximation
      p.first = my_first() / other.my_first();

      using boost::multiprecision::isfinite;
      using std::isfinite;

      if (!((isfinite)(p.first)))
      {
         data = p;
         return *this;
      }

      cpp_double_fp_backend r = *this - (other * p.first);

      p.second = r.my_first() / other.my_first();
      r -= other * p.second;

      const FloatingPointType p_prime = r.my_first() / other.my_first();

      arithmetic::normalize(p);

      data = p;

      operator+=(p_prime);

      return *this;
   }

   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend operator++(int)
   {
      cpp_double_fp_backend t(*this);
      ++*this;
      return t;
   }

   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend operator--(int)
   {
      cpp_double_fp_backend t(*this);
      --*this;
      return t;
   }

   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator++() { return *this += cpp_double_fp_backend<float_type>(float_type(1.0F)); }
   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend& operator--() { return *this -= cpp_double_fp_backend<float_type>(float_type(1.0F)); }

   BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend operator-() const
   {
      cpp_double_fp_backend v(*this);
      v.negate();
      return v;
   }

   // Helper functions
   BOOST_MP_CXX14_CONSTEXPR static cpp_double_fp_backend pown(const cpp_double_fp_backend& x, int p)
   {
      using local_float_type = cpp_double_fp_backend;

      local_float_type result;

      if (p < 0)
         result = pown(local_float_type(1U) / x, -p);
      else if (p == 0)
         result = local_float_type(1U);
      else if (p == 1)
         result = x;
      else if (p == 2)
         result = local_float_type(x * x);
      else if (p == 3)
         result = local_float_type((x * x) * x);
      else
      {
         result = local_float_type(1U);

         local_float_type y(x);

         auto p_local = static_cast<std::uint32_t>(p);

         for (;;)
         {
            if (static_cast<std::uint_fast8_t>(p_local & 1U) != static_cast<std::uint_fast8_t>(UINT8_C(0)))
            {
               result *= y;
            }

            p_local >>= 1U;

            if (p_local == static_cast<std::uint32_t>(UINT8_C(0)))
            {
               break;
            }
            else
            {
               y *= y;
            }
         }
      }

      return result;
   }

   BOOST_MP_CXX14_CONSTEXPR void swap(cpp_double_fp_backend& other)
   {
      if(this != &other)
      {
         const rep_type tmp = data;

         data = other.data;

         other.data = tmp;
      }
   }

   BOOST_MP_CXX14_CONSTEXPR void swap(cpp_double_fp_backend&& other) noexcept
   {
      const rep_type tmp = data;

      data = other.data;

      other.data = tmp;
   }

   constexpr int compare(const cpp_double_fp_backend& other) const
   {
      // Return 1 for *this > other, -1 for *this < other, 0 for *this = other.
      return (my_first() > other.my_first()) ?  1 : (my_first()  < other.my_first())
                                             ? -1 : (my_second() > other.my_second())
                                             ?  1 : (my_second() < other.my_second())
                                             ? -1 : 0;
   }

   std::string str(std::streamsize number_of_digits, const std::ios::fmtflags format_flags) const
   {
      if (number_of_digits == 0)
         number_of_digits = cpp_double_fp_backend::my_digits10;

      const std::string my_str = boost::multiprecision::detail::convert_to_string(*this, number_of_digits, format_flags);

      return my_str;
   }

   int order02() const
   {
      int e2;

      using std::frexp;

      frexp(my_first(), &e2);

      return e2;
   }

   int  order10  () const { return (int)(float(order02()) * 0.301F); }
   bool small_arg() const { return (order10() < (-my_digits10 / 6)); }
   bool near_one () const { return cpp_double_fp_backend(fabs(cpp_double_fp_backend(1U) - *this)).small_arg(); }

   static BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend my_value_max() noexcept
   {
      using std::ldexp;
      using std::sqrt;
#if defined(BOOST_MATH_USE_FLOAT128)
      using boost::multiprecision::ldexp;
      using boost::multiprecision::sqrt;
#endif

      return
         cpp_double_fp_backend
         (
            arithmetic::fast_sum
            (
               float_type(  (std::numeric_limits<float_type>::max)()
                          * float_type(float_type(1.0F) - float_type(1.5F) * sqrt(std::numeric_limits<float_type>::epsilon()))),
               ldexp
               (
                   (std::numeric_limits<float_type>::max)(),
                  -(std::numeric_limits<float_type>::digits + 1)
               )
            )
         );
   }

   static BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend my_value_min() noexcept
   {
      using std::ldexp;
#if defined(BOOST_MATH_USE_FLOAT128)
      using boost::multiprecision::ldexp;
#endif

      return cpp_double_fp_backend(ldexp(float_type(1), my_min_exponent));
   }

   static BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend my_value_eps() noexcept
   {
      using std::ldexp;
#if defined(BOOST_MATH_USE_FLOAT128)
      using boost::multiprecision::ldexp;
#endif

      // TBD: Need a better value here.
      return []() -> cpp_double_fp_backend {
         cpp_double_fp_backend result;

         eval_ldexp(result, cpp_double_fp_backend(1), 4 - my_digits);

         return result;
      }();
   }

   static BOOST_MP_CXX14_CONSTEXPR cpp_double_fp_backend my_value_nan() noexcept
   {
      return cpp_double_fp_backend(std::numeric_limits<float_type>::quiet_NaN());
   }

 private:
   rep_type data;

   template <typename OtherFloatingPointType,
             typename std::enable_if<((detail::is_floating_point_or_float128<OtherFloatingPointType>::value == true) && ((std::numeric_limits<FloatingPointType>::digits10 * 2) < 16))>::type const*>
   friend void eval_exp(cpp_double_fp_backend<OtherFloatingPointType>& result, const cpp_double_fp_backend<OtherFloatingPointType>& x);

   template <typename OtherFloatingPointType,
             typename std::enable_if<((detail::is_floating_point_or_float128<OtherFloatingPointType>::value == true) && (((std::numeric_limits<FloatingPointType>::digits10 * 2) >= 16) && ((std::numeric_limits<FloatingPointType>::digits10 * 2) <= 36)))>::type const*>
   friend void eval_exp(cpp_double_fp_backend<OtherFloatingPointType>& result, const cpp_double_fp_backend<OtherFloatingPointType>& x);

   template <typename OtherFloatingPointType,
             typename std::enable_if<((detail::is_floating_point_or_float128<OtherFloatingPointType>::value == true) && ((std::numeric_limits<FloatingPointType>::digits10 * 2) > 36))>::type const*>
   friend void eval_exp(cpp_double_fp_backend<OtherFloatingPointType>& result, const cpp_double_fp_backend<OtherFloatingPointType>& x);
};

template <typename FloatingPointType>
constexpr int cpp_double_fp_backend<FloatingPointType>::my_digits;
template <typename FloatingPointType>
constexpr int cpp_double_fp_backend<FloatingPointType>::my_digits10;
template <typename FloatingPointType>
constexpr int cpp_double_fp_backend<FloatingPointType>::my_max_digits10;
template <typename FloatingPointType>
constexpr int cpp_double_fp_backend<FloatingPointType>::my_max_exponent;
template <typename FloatingPointType>
constexpr int cpp_double_fp_backend<FloatingPointType>::my_min_exponent;
template <typename FloatingPointType>
constexpr int cpp_double_fp_backend<FloatingPointType>::my_max_exponent10;
template <typename FloatingPointType>
constexpr int cpp_double_fp_backend<FloatingPointType>::my_min_exponent10;

template <typename FloatingPointType>
inline cpp_double_fp_backend<FloatingPointType> operator+(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return cpp_double_fp_backend<FloatingPointType>(a) += b; }
template <typename FloatingPointType>
inline cpp_double_fp_backend<FloatingPointType> operator-(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return cpp_double_fp_backend<FloatingPointType>(a) -= b; }
template <typename FloatingPointType>
inline cpp_double_fp_backend<FloatingPointType> operator*(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return cpp_double_fp_backend<FloatingPointType>(a) *= b; }
template <typename FloatingPointType>
inline cpp_double_fp_backend<FloatingPointType> operator/(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return cpp_double_fp_backend<FloatingPointType>(a) /= b; }

template <typename FloatingPointType>
inline bool operator<(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return (a.compare(b) < 0); }
template <typename FloatingPointType>
inline bool operator<=(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return (a.compare(b) <= 0); }
template <typename FloatingPointType>
inline bool operator==(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return (a.compare(b) == 0); }
template <typename FloatingPointType>
inline bool operator!=(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return (a.compare(b) != 0); }
template <typename FloatingPointType>
inline bool operator>=(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return (a.compare(b) >= 0); }
template <typename FloatingPointType>
inline bool operator>(const cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return (a.compare(b) > 0); }

// -- Input/Output Streaming
template <typename FloatingPointType, typename char_type, typename traits_type>
std::basic_ostream<char_type, traits_type>&
operator<<(std::basic_ostream<char_type, traits_type>& os, const cpp_double_fp_backend<FloatingPointType>& f)
{
   const auto str_result = f.str(os.precision(), os.flags());

   return (os << str_result);
}

template <typename FloatingPointType, typename char_type, typename traits_type>
std::basic_istream<char_type, traits_type>&
operator>>(std::basic_istream<char_type, traits_type>& is, cpp_double_fp_backend<FloatingPointType>& f)
{
   std::string str;
   is >> str;
   boost::multiprecision::detail::convert_from_string(f, str.c_str());
   return is;
}

template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR void eval_add(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x) { result += x; }
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR void eval_subtract(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x) { result -= x; }
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR void eval_multiply(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x) { result *= x; }
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR void eval_divide(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x) { result /= x; }
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR bool eval_eq(cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return (a.compare(b) == 0); }
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR bool eval_lt(cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return (a.compare(b) == -1); }
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR bool eval_gt(cpp_double_fp_backend<FloatingPointType>& a, const cpp_double_fp_backend<FloatingPointType>& b) { return (a.compare(b) == 1); }
template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR bool eval_is_zero(cpp_double_fp_backend<FloatingPointType>& x) { return ((x.crep().first) == 0 && (x.crep().second == 0)); }

template <typename FloatingPointType>
void eval_fabs(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& a)
{
   result = a;

   if (a.is_neg())
   {
      result.negate();
   }
}

template <typename FloatingPointType>
void eval_frexp(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& a, int* v)
{
   using std::frexp;
   using std::ldexp;

   result.rep().first  = frexp(a.rep().first, v);
   result.rep().second = ldexp(a.rep().second, -*v);
}

template <typename FloatingPointType>
void eval_ldexp(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& a, int v)
{
   using std::ldexp;

   result.rep() =
      std::make_pair
      (
         ldexp(a.crep().first,  v),
         ldexp(a.crep().second, v)
      );

   using local_backend_type = cpp_double_fp_backend<FloatingPointType>;

   local_backend_type::arithmetic::normalize(result.rep());
}

template <typename FloatingPointType>
void eval_floor(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x)
{
   using double_float_type = cpp_double_fp_backend<FloatingPointType>;

   using std::floor;

   const typename double_float_type::float_type fhi = floor(x.rep().first);

   if (fhi != x.my_first())
   {
      result.rep().first  = fhi;
      result.rep().second = static_cast<typename double_float_type::float_type>(0.0F);
   }
   else
   {
      result.rep().first  = fhi;
      result.rep().second = floor(x.rep().second);

      double_float_type::arithmetic::normalize(result.rep());
   }
}

template <typename FloatingPointType>
void eval_ceil(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x)
{
   // Compute -floor(-x);
   eval_floor(result, -x);

   result.negate();
}

template <typename FloatingPointType>
BOOST_MP_CXX14_CONSTEXPR int eval_fpclassify(const cpp_double_fp_backend<FloatingPointType>& o)
{
   // The eval_fpclassify implementation is modelled after Matt Borland's work in <ccmath.hpp>.

   auto my_isinf = [](FloatingPointType x) -> bool { return ((x == std::numeric_limits<FloatingPointType>::infinity()) || (-x == std::numeric_limits<FloatingPointType>::infinity())); };
   auto my_isnan = [](FloatingPointType x) -> bool { return (x != x); };

   auto my_abs =
      [](FloatingPointType x) -> FloatingPointType
      {
         if (x != x)
         {
            return std::numeric_limits<FloatingPointType>::quiet_NaN();
         }
         else if (x == static_cast<FloatingPointType>(-0))
         {
            return static_cast<FloatingPointType>(0);
         }

         return ((x >= 0) ? x : -x);
      };

      return  my_isnan(o.crep().first) ? FP_NAN :
              my_isinf(o.crep().first) ? FP_INFINITE :
             (my_abs(o.crep().first) == FloatingPointType(0)) ? FP_ZERO :
             (my_abs(o.crep().first) > 0) && (my_abs(o.crep().first) < (std::numeric_limits<FloatingPointType>::min)()) ? FP_SUBNORMAL : FP_NORMAL;
}

template <typename FloatingPointType>
void eval_sqrt(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& o)
{
   using local_float_type = typename cpp_double_fp_backend<FloatingPointType>::float_type;

   using std::sqrt;

   const local_float_type c = sqrt(o.crep().first);

   constexpr int              MantissaBits = std::numeric_limits<local_float_type>::digits;
   constexpr int              SplitBits    = MantissaBits / 2 + 1;
   constexpr local_float_type Splitter     = local_float_type((1ULL << SplitBits) + 1);

   local_float_type p  = Splitter * c;
   local_float_type hx = (c - p);
                    hx = hx + p;
   local_float_type tx = c  - hx;
                    p  = hx * hx;
   local_float_type q  = hx * tx;
                    q  = q  + q;

   local_float_type u  = p  + q;
   local_float_type uu = p  - u;
                    uu = uu + q;
   local_float_type t1 = tx * tx;
                    uu = uu + t1;

   local_float_type cc = o.crep().first - u;
   cc = cc - uu;
   cc = cc + o.crep().second;
   t1 = c + c;
   cc = cc / t1;

   hx = c + cc;
   tx = c - hx;
   tx = tx + cc;

   result.rep().first  = hx;
   result.rep().second = tx;
}

template <typename FloatingPointType,
          typename std::enable_if<((detail::is_floating_point_or_float128<FloatingPointType>::value == true) && ((std::numeric_limits<FloatingPointType>::digits10 * 2) < 16))>::type const*>
void eval_exp(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x)
{
   const auto x_is_zero = x.is_zero();

   if ((eval_fpclassify(x) != static_cast<int>(FP_NORMAL)) && (x_is_zero == false))
   {
      result = x;
   }
   else
   {
      using double_float_type = cpp_double_fp_backend<FloatingPointType>;
      using local_float_type  = typename double_float_type::float_type;

      // Get a local copy of the argument and force it to be positive.
      const auto b_neg = x.is_neg();

      double_float_type xx;

      eval_fabs(xx, x);

      // Check the range of the input.
      static const double_float_type max_exp_input =
      []() -> double_float_type
      {
         using std::log;

         const double_float_type lg_x0 = log(double_float_type::my_value_max().crep().first);
         const double_float_type dx    =   double_float_type(double_float_type::my_value_max().crep().second)
                                         / double_float_type(double_float_type::my_value_max().crep().first);

         return lg_x0 + dx;
      }();

      static const double_float_type min_exp_input =
      []() -> double_float_type
      {
         using std::log;

         const double_float_type lg_x0 = log(double_float_type::my_value_min().crep().first);

         return lg_x0;
      }();

      if (x_is_zero)
      {
         result = double_float_type(1U);
      }
      else if (x < min_exp_input)
      {
         result = double_float_type(0U);
      }
      else if (xx > max_exp_input)
      {
         result = double_float_type(std::numeric_limits<local_float_type>::infinity());
      }
      else if (xx.is_one())
      {
         static const double_float_type constant_e1         (std::string("2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274"));
         static const double_float_type constant_one_over_e1(std::string("0.36787944117144232159552377016146086744581113103176783450783680169746149574489980335714727434591964375"));

         result = ((b_neg == false) ? constant_e1 : constant_one_over_e1);
      }
      else
      {
         // Use an argument reduction algorithm for exp() in classic MPFUN-style.
         static const double_float_type constant_ln2         (std::string("0.69314718055994530941723212145817656807550013436025525412068000949339362196969471560586332699641868754"));
         static const double_float_type constant_one_over_ln2(std::string("1.4426950408889634073599246810018921374266459541529859341354494069311092191811850798855266228935063445"));

         double_float_type nf;

         eval_floor(nf, xx * constant_one_over_ln2);

         // Prepare the scaled variables.
         const auto b_scale = (xx.order02() > -1);

         double_float_type r;

         if (b_scale)
         {
            eval_ldexp(r, xx - (nf * constant_ln2), -2);
         }
         else
         {
            r = xx;
         }

         // PadeApproximant[Exp[x] - 1, {x, 0, {6, 6}}]
         // FullSimplify[%]
         //   (84 x (7920 + 240 x^2 + x^4))
         // / (665280 + x (-332640 + x (75600 + x (-10080 + x (840 + (-42 + x) x)))))

         static const double_float_type n84(84);
         static const double_float_type n240(240);
         static const double_float_type n7920(7920);

         static const double_float_type n665280(665280);
         static const double_float_type n332640(332640);
         static const double_float_type n75600(75600);
         static const double_float_type n10080(10080);
         static const double_float_type n840(840);
         static const double_float_type n42(42);

         const double_float_type r2 = r * r;

         result = double_float_type(1U) + ((n84 * r) * (n7920 + r2 * (n240 + r2))) / (n665280 + r * (-n332640 + r * (n75600 + r * (-n10080 + r * (n840 + (-n42 + r) * r)))));

         // Use the small-argument Pade approximation having coefficients shown above.
         const double_float_type top = (n84 * r * (n7920 + (n240 + r2) * r2));
         const double_float_type bot = (n665280 + r * (-n332640 + r * (n75600 + r * (-n10080 + r * (n840 + (-n42 + r) * r)))));

         result = double_float_type(1U) + (top / bot);

         // Rescale the result.
         if (b_scale)
         {
            result *= result;
            result *= result;

            int n;

            eval_convert_to(&n, nf);

            if (n > 0)
            {
               eval_ldexp(result, double_float_type(result), n);
            }
         }

         if (b_neg)
         {
            result = double_float_type(1U) / result;
         }
      }
   }
}

template <typename FloatingPointType,
          typename std::enable_if<((detail::is_floating_point_or_float128<FloatingPointType>::value == true) && (((std::numeric_limits<FloatingPointType>::digits10 * 2) >= 16) && ((std::numeric_limits<FloatingPointType>::digits10 * 2) <= 36)))>::type const*>
void eval_exp(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x)
{
   const bool x_is_zero = x.is_zero();

   if ((eval_fpclassify(x) != (int)FP_NORMAL) && (x_is_zero == false))
   {
      result = x;
   }
   else
   {
      using double_float_type = cpp_double_fp_backend<FloatingPointType>;
      using local_float_type  = typename double_float_type::float_type;

      // Get a local copy of the argument and force it to be positive.
      const bool b_neg = x.is_neg();

      double_float_type xx;

      eval_fabs(xx, x);

      // Check the range of the input.
      static const double_float_type max_exp_input =
      []() -> double_float_type
      {
         using std::log;

         const double_float_type lg_x0 = log(double_float_type::my_value_max().crep().first);
         const double_float_type dx    =   double_float_type(double_float_type::my_value_max().crep().second)
                                         / double_float_type(double_float_type::my_value_max().crep().first);

         return lg_x0 + dx;
      }();

      static const double_float_type min_exp_input =
      []() -> double_float_type
      {
         using std::log;

         const double_float_type lg_x0 = log(double_float_type::my_value_min().crep().first);

         return lg_x0;
      }();

      if (x_is_zero)
      {
         result = double_float_type(1U);
      }
      else if (x < min_exp_input)
      {
         result = double_float_type(0U);
      }
      else if (xx > max_exp_input)
      {
         result = double_float_type(std::numeric_limits<local_float_type>::infinity());
      }
      else if (xx.is_one())
      {
         static const double_float_type constant_e1(std::string("2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274"));
         static const double_float_type constant_one_over_e1(std::string("0.36787944117144232159552377016146086744581113103176783450783680169746149574489980335714727434591964375"));

         result = ((b_neg == false) ? constant_e1 : constant_one_over_e1);
      }
      else
      {
         // Use an argument reduction algorithm for exp() in classic MPFUN-style.
         static const double_float_type constant_ln2(std::string("0.69314718055994530941723212145817656807550013436025525412068000949339362196969471560586332699641868754"));
         static const double_float_type constant_one_over_ln2(std::string("1.4426950408889634073599246810018921374266459541529859341354494069311092191811850798855266228935063445"));

         double_float_type nf;

         eval_floor(nf, xx * constant_one_over_ln2);

         // Prepare the scaled variables.
         const bool b_scale = (xx.order02() > -4);

         double_float_type r;

         if (b_scale)
         {
            eval_ldexp(r, xx - (nf * constant_ln2), -4);
         }
         else
         {
            r = xx;
         }

         // PadeApproximant[Exp[r], {r, 0, 8, 8}]
         // FullSimplify[%]

         static const double_float_type n144(144U);
         static const double_float_type n3603600(3603600UL);
         static const double_float_type n120120(120120UL);
         static const double_float_type n770(770U);

         static const double_float_type n518918400(518918400UL);
         static const double_float_type n259459200(259459200UL);
         static const double_float_type n60540480(60540480UL);
         static const double_float_type n8648640(8648640UL);
         static const double_float_type n831600(831600UL);
         static const double_float_type n55440(55440U);
         static const double_float_type n2520(2520U);
         static const double_float_type n72(72U);

         const double_float_type r2 = r * r;

         const double_float_type top = (n144 * r) * (n3603600 + r2 * (n120120 + r2 * (n770 + r2)));
         const double_float_type bot = (n518918400 + r * (-n259459200 + r * (n60540480 + r * (-n8648640 + r * (n831600 + r * (-n55440 + r * (n2520 + r * (-n72 + r))))))));

         result = double_float_type(1U) + (top / bot);

         // Rescale the result.
         if (b_scale)
         {
            result *= result;
            result *= result;
            result *= result;
            result *= result;

            int n;

            eval_convert_to(&n, nf);

            if (n > 0)
            {
               eval_ldexp(result, double_float_type(result), n);
            }
         }

         if (b_neg)
         {
            result = double_float_type(1U) / result;
         }
      }
   }
}

template <typename FloatingPointType,
          typename std::enable_if<((detail::is_floating_point_or_float128<FloatingPointType>::value == true) && ((std::numeric_limits<FloatingPointType>::digits10 * 2) > 36))>::type const*>
void eval_exp(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x)
{
   const bool x_is_zero = x.is_zero();

   if ((eval_fpclassify(x) != (int)FP_NORMAL) && (x_is_zero == false))
   {
      result = x;
   }
   else
   {
      using double_float_type = cpp_double_fp_backend<FloatingPointType>;
      using local_float_type  = typename double_float_type::float_type;

      // Get a local copy of the argument and force it to be positive.
      const bool b_neg = x.is_neg();

      double_float_type xx;

      eval_fabs(xx, x);

      // Check the range of the input.
      static const double_float_type max_exp_input =
      []() -> double_float_type
      {
         using std::log;

         const double_float_type lg_x0 = log(double_float_type::my_value_max().crep().first);
         const double_float_type dx    =   double_float_type(double_float_type::my_value_max().crep().second)
                                         / double_float_type(double_float_type::my_value_max().crep().first);

         return lg_x0 + dx;
      }();

      static const double_float_type min_exp_input =
      []() -> double_float_type
      {
         using std::log;

         const double_float_type lg_x0 = log(double_float_type::my_value_min().crep().first);

         return lg_x0;
      }();

      if (x_is_zero)
      {
         result = double_float_type(1U);
      }
      else if (x < min_exp_input)
      {
         result = double_float_type(0U);
      }
      else if (xx > max_exp_input)
      {
         result = double_float_type(std::numeric_limits<local_float_type>::infinity());
      }
      else if (xx.is_one())
      {
         static const double_float_type constant_e1         (std::string("2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274"));
         static const double_float_type constant_one_over_e1(std::string("0.36787944117144232159552377016146086744581113103176783450783680169746149574489980335714727434591964375"));

         result = ((b_neg == false) ? constant_e1 : constant_one_over_e1);
      }
      else
      {
         // Use an argument reduction algorithm for exp() in classic MPFUN-style.
         static const double_float_type constant_ln2         (std::string("0.69314718055994530941723212145817656807550013436025525412068000949339362196969471560586332699641868754"));
         static const double_float_type constant_one_over_ln2(std::string("1.4426950408889634073599246810018921374266459541529859341354494069311092191811850798855266228935063445"));

         double_float_type nf;

         eval_floor(nf, xx * constant_one_over_ln2);

         // Prepare the scaled variables.
         const bool b_scale = (xx.order02() > -4);

         double_float_type xh;

         if (b_scale)
         {
            eval_ldexp(xh, xx - (nf * constant_ln2), -4);
         }
         else
         {
            xh = xx;
         }

         double_float_type x_pow_n_div_n_fact(xh);

         result = double_float_type(1U) + x_pow_n_div_n_fact;
         double_float_type dummy;

         // Series expansion of hypergeometric_0f0(; ; x).
         // For this high(er) digit count, a scaled argument with subsequent
         // Taylor series expansion is actually more precise than Pade approximation.
         for (unsigned n = 2U; n < 64U; ++n)
         {
            x_pow_n_div_n_fact *= xh;
            x_pow_n_div_n_fact /= typename double_float_type::float_type(n);

            int n_tol;

            eval_frexp(dummy, x_pow_n_div_n_fact, &n_tol);

            if ((n > 4U) && (n_tol < -(double_float_type::my_digits - 6)))
            {
               break;
            }

            result += x_pow_n_div_n_fact;
         }

         // Rescale the result.
         if (b_scale)
         {
            result *= result;
            result *= result;
            result *= result;
            result *= result;

            int n;

            eval_convert_to(&n, nf);

            if (n > 0)
            {
               eval_ldexp(result, double_float_type(result), n);
            }
         }

         if (b_neg)
         {
            result = double_float_type(1U) / result;
         }
      }
   }
}

template <typename FloatingPointType>
void eval_log(cpp_double_fp_backend<FloatingPointType>& result, const cpp_double_fp_backend<FloatingPointType>& x)
{
   using double_float_type = cpp_double_fp_backend<FloatingPointType>;

   if (eval_fpclassify(x) != (int)FP_NORMAL)
   {
      result = x;
   }
   else if (x.is_neg())
   {
      result = double_float_type::my_value_nan();
   }
   else if (x.is_one())
   {
      result = double_float_type(0U);
   }
   else
   {
      using std::log;

      // Get initial estimate using the standard math function log.
      const double_float_type s(log(x.crep().first));
      double_float_type       E;

      eval_exp(E, s);

      // Do one single step of Newton-Raphson iteration
      result = s + ((x - E) / E);
   }
}

template <typename FloatingPointType,
          typename R>
typename std::enable_if<std::is_integral<R>::value == true>::type eval_convert_to(R* result, const cpp_double_fp_backend<FloatingPointType>& backend)
{
   using c_type = typename std::common_type<R, FloatingPointType>::type;

   using std::fabs;

   BOOST_CONSTEXPR const c_type my_max = static_cast<c_type>((std::numeric_limits<R>::max)());
   BOOST_CONSTEXPR const c_type my_min = static_cast<c_type>((std::numeric_limits<R>::min)());
   c_type                       ct     = fabs(backend.crep().first);

   static_cast<void>(my_min);

   if (ct > my_max)
      if (!std::is_unsigned<R>::value)
         *result = backend.crep().first >= typename cpp_double_fp_backend<FloatingPointType>::float_type(0U) ? (std::numeric_limits<R>::max)() : detail::minus_max<R>();
      else
         *result = (std::numeric_limits<R>::max)();
   else
   {
      *result  = static_cast<R>(backend.crep().first);
      *result += static_cast<R>(backend.crep().second);
   }
}

template <typename FloatingPointType,
          typename R>
typename std::enable_if<std::is_integral<R>::value == false>::type eval_convert_to(R* result, const cpp_double_fp_backend<FloatingPointType>& backend)
{
   *result = R(backend.crep().first);
   *result += R(backend.crep().second);
}

template <typename FloatingPointType>
cpp_double_fp_backend<FloatingPointType> fabs(const cpp_double_fp_backend<FloatingPointType>& a)
{
   using double_float_type = cpp_double_fp_backend<FloatingPointType>;

   double_float_type result;

   eval_fabs(result, a);

   return result;
}

template <typename FloatingPointType>
std::size_t hash_value(const cpp_double_fp_backend<FloatingPointType>& a)
{
   return a.hash();
}

} // namespace backends

using cpp_double_float       = number<backends::cpp_double_fp_backend<float>>;
using cpp_double_double      = number<backends::cpp_double_fp_backend<double>>;
using cpp_double_long_double = number<backends::cpp_double_fp_backend<long double>>;
#ifdef BOOST_MATH_USE_FLOAT128
using cpp_double_float128    = number<backends::cpp_double_fp_backend<float128>>;
#endif

}} // namespace boost::multiprecision

namespace boost { namespace math {

template <typename FloatingPointType>
int(fpclassify)(const boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>& o)
{
   using std::fpclassify;

   return (int)(fpclassify)(o.crep().first);
}

}} // namespace boost::math

namespace std {

// Specialization of numeric_limits for boost::multiprecision::number<cpp_double_fp_backend<>>
template <typename FloatingPointType,
          const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
class numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >
    : public std::numeric_limits<FloatingPointType>
{
 private:
   using base_class_type = std::numeric_limits<FloatingPointType>;

   using inner_self_type = boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>;

   using self_type =
       boost::multiprecision::number<inner_self_type, ExpressionTemplatesOption>;

 public:
   static constexpr bool is_specialized                = true;
   static constexpr bool is_signed                     = true;
   static constexpr bool is_integer                    = false;
   static constexpr bool is_exact                      = false;
   static constexpr bool is_bounded                    = true;
   static constexpr bool is_modulo                     = false;
   static constexpr bool is_iec559                     = false;
   static constexpr std::float_denorm_style has_denorm = std::denorm_absent;

   static constexpr int digits                         = inner_self_type::my_digits;
   static constexpr int digits10                       = inner_self_type::my_digits10;
   static constexpr int max_digits10                   = inner_self_type::my_max_digits10;

   static constexpr int max_exponent                   = inner_self_type::my_max_exponent;
   static constexpr int min_exponent                   = inner_self_type::my_min_exponent;
   static constexpr int max_exponent10                 = inner_self_type::my_max_exponent10;
   static constexpr int min_exponent10                 = inner_self_type::my_min_exponent10;

   static BOOST_MP_CXX14_CONSTEXPR self_type(min)         () noexcept { return self_type(inner_self_type::my_value_min()); }
   static BOOST_MP_CXX14_CONSTEXPR self_type(max)         () noexcept { return self_type(inner_self_type::my_value_max()); }
   static BOOST_MP_CXX14_CONSTEXPR self_type lowest       () noexcept { return self_type(-(max)()); }
   static BOOST_MP_CXX14_CONSTEXPR self_type epsilon      () noexcept { return self_type(inner_self_type::my_value_eps()); }
   static BOOST_MP_CXX14_CONSTEXPR self_type round_error  () noexcept { return self_type(base_class_type::round_error()); }
   static BOOST_MP_CXX14_CONSTEXPR self_type denorm_min   () noexcept { return self_type((min)()); }
   static BOOST_MP_CXX14_CONSTEXPR self_type infinity     () noexcept { return self_type(base_class_type::infinity()); }
   static BOOST_MP_CXX14_CONSTEXPR self_type quiet_NaN    () noexcept { return self_type(base_class_type::quiet_NaN()); }
   static BOOST_MP_CXX14_CONSTEXPR self_type signaling_NaN() noexcept { return self_type(base_class_type::signaling_NaN()); }
};

} // namespace std

template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr bool std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::is_specialized;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr bool std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::is_signed;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr bool std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::is_integer;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr bool std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::is_exact;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr bool std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::is_bounded;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr bool std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::is_modulo;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr bool std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::is_iec559;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr std::float_denorm_style std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::has_denorm;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr int std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::digits;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr int std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::digits10;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr int std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::max_digits10;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr int std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::max_exponent;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr int std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::min_exponent;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr int std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::max_exponent10;
template <typename FloatingPointType, const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
constexpr int std::numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_fp_backend<FloatingPointType>, ExpressionTemplatesOption> >::min_exponent10;

#endif // BOOST_MP_CPP_DOUBLE_FP_BACKEND_2021_06_05_HPP

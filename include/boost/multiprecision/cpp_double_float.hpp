///////////////////////////////////////////////////////////////////////////////
//  Copyright 2021 Fahad Syed.
//  Copyright 2021 Christopher Kormanyos.
//  Copyright 2021 Janek Kozicki.
//  Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_MP_CPP_DOUBLE_FLOAT_2021_06_05_HPP
#define BOOST_MP_CPP_DOUBLE_FLOAT_2021_06_05_HPP

#include <boost/config.hpp>

#include <type_traits>
#include <string>
#include <utility>
#include <limits>
#include <sstream>
#include <tuple>
#include <vector>

#include <boost/assert.hpp>
#include <boost/multiprecision/number.hpp>
#include <boost/multiprecision/detail/float_string_cvt.hpp>
#include <boost/multiprecision/detail/hash.hpp>
#include <boost/type_traits/common_type.hpp>

namespace boost { namespace multiprecision { namespace backends {

template <typename FloatingPointType>
class cpp_double_float;

template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator+(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b);
template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator-(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b);
template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator*(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b);
template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator/(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b);

template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator+(const cpp_double_float<FloatingPointType>& a, const FloatingPointType& b);
template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator-(const cpp_double_float<FloatingPointType>& a, const FloatingPointType& b);
template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator*(const cpp_double_float<FloatingPointType>& a, const FloatingPointType& b);
template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator/(const cpp_double_float<FloatingPointType>& a, const FloatingPointType& b);

template<typename FloatingPointType> inline bool operator< (const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b);
template<typename FloatingPointType> inline bool operator<=(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b);
template<typename FloatingPointType> inline bool operator==(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b);
template<typename FloatingPointType> inline bool operator!=(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b);
template<typename FloatingPointType> inline bool operator>=(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b);
template<typename FloatingPointType> inline bool operator> (const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b);

template<typename FloatingPointType> void eval_add     (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x);
template<typename FloatingPointType> void eval_subtract(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x);
template<typename FloatingPointType> void eval_multiply(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x);
template<typename FloatingPointType> void eval_divide  (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x);

template<typename FloatingPointType> void eval_fabs      (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& a);
template<typename FloatingPointType> void eval_frexp     (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& a, int* v);
template<typename FloatingPointType> void eval_ldexp     (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& a, int v);
template<typename FloatingPointType> void eval_floor     (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x);
template<typename FloatingPointType> void eval_ceil      (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x);
template<typename FloatingPointType> int  eval_fpclassify(const cpp_double_float<FloatingPointType>& o);
template<typename FloatingPointType> void eval_sqrt      (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& o);
template<typename FloatingPointType> void eval_exp       (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x);
template<typename FloatingPointType> void eval_log       (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x);

template<typename FloatingPointType,
         typename R>
typename std::enable_if<std::is_integral<R>::value == true>::type eval_convert_to(R* result, const cpp_double_float<FloatingPointType>& backend);

template<typename FloatingPointType,
         typename R>
typename std::enable_if<std::is_integral<R>::value == false>::type eval_convert_to(R* result, const cpp_double_float<FloatingPointType>& backend);

template<typename FloatingPointType,
         typename char_type,
         typename traits_type>
std::basic_ostream<char_type, traits_type>& operator<<(std::basic_ostream<char_type, traits_type>& os,
                                                       const cpp_double_float<FloatingPointType>& f);

template<typename FloatingPointType>
std::size_t hash_value(const cpp_double_float<FloatingPointType>& a);

template<typename FloatingPointType>
cpp_double_float<FloatingPointType> fabs(const cpp_double_float<FloatingPointType>& a);

} } } // namespace boost::multiprecision::backends

namespace boost { namespace math {

template<typename FloatingPointType>
int fpclassify(const boost::multiprecision::backends::cpp_double_float<FloatingPointType>& o);

} }

namespace std {

// Foward declarations of various specializations of std::numeric_limits

template <typename FloatingPointType>
class numeric_limits<boost::multiprecision::backends::cpp_double_float<FloatingPointType>>;

template <typename FloatingPointType,
          const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
class numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_float<FloatingPointType>, ExpressionTemplatesOption>>;

}

namespace boost { namespace multiprecision {

template<typename FloatingPointType>
struct number_category<backends::cpp_double_float<FloatingPointType>>
  : public std::integral_constant<int, number_kind_floating_point> { };

namespace backends {

namespace detail {

template <class T> struct is_arithmetic_or_float128
{
   static constexpr bool value = (   (std::is_arithmetic<T>::value == true)
#if defined(BOOST_MATH_USE_FLOAT128)
                                  || (std::is_same<typename std::decay<T>::type, boost::multiprecision::float128>::value == true)
#endif
                                 );
};

template <class T> struct is_floating_point_or_float128
{
   static constexpr bool value = (   (std::is_floating_point<T>::value == true)
#if defined(BOOST_MATH_USE_FLOAT128)
                                  || (std::is_same<typename std::decay<T>::type, boost::multiprecision::float128>::value == true)
#endif
                                 );
};

template<typename R>
typename std::enable_if<boost::is_unsigned<R>::value == false, R>::type minus_max()
{
   return boost::is_signed<R>::value ? (std::numeric_limits<R>::min)() : -(std::numeric_limits<R>::max)();
}

template<typename R>
typename std::enable_if<boost::is_unsigned<R>::value == true, R>::type minus_max()
{
   return 0;
}


}

// A cpp_double_float is represented by an unevaluated sum of two floating-point
// units (say a0 and a1) which satisfy |a1| <= (1 / 2) * ulp(a0).
// The type of the floating-point constituents should adhere to IEEE754.

template <typename FloatingPointType>
class cpp_double_float
{
 public:
   using float_type = FloatingPointType;
   using rep_type   = std::pair<float_type, float_type>;

  using   signed_types = std::tuple<  signed char,   signed short,   signed int,   signed long,   signed long long, std::intmax_t>;
  using unsigned_types = std::tuple<unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long, std::uintmax_t>;
  using float_types    = std::tuple<float, double, long double>;
  using exponent_type  = int;

   // Default constructor.
   cpp_double_float() { }

   // Copy constructor.
   constexpr cpp_double_float(const cpp_double_float&) = default;

   // Constructors from other floating-point types.
   template <typename FloatType,
             typename std::enable_if<    (detail::is_floating_point_or_float128<FloatType>::value == true)
                                      && (std::numeric_limits<FloatType>::digits <= std::numeric_limits<float_type>::digits)>::type const* = nullptr>
   constexpr cpp_double_float(const FloatType& f) : data(std::make_pair(f, (float_type)0)) {}

   template <typename FloatType,
             typename std::enable_if<(   (std::numeric_limits<FloatType>::is_iec559 == true)
                                      && (std::numeric_limits<FloatType>::digits > std::numeric_limits<float_type>::digits))>::type const* = nullptr>
   constexpr cpp_double_float(const FloatType& f)
       : data(std::make_pair(static_cast<float_type>(f),
                             static_cast<float_type>(f - (FloatType) static_cast<float_type>(f)))) {}

   // Constructor from other cpp_double_float<> objects.
   template <typename OtherFloatType,
             typename std::enable_if<(   (std::is_floating_point<OtherFloatType>::value == true)
                                      && (std::is_same<FloatingPointType, OtherFloatType>::value == false))>::type const* = nullptr>
   cpp_double_float(const cpp_double_float<OtherFloatType>& a)
      : cpp_double_float(a.first())
   {
      *this += a.second();
   }

   // Constructors from integers
   template <typename IntegralType,
             typename std::enable_if<(   (std::is_integral<IntegralType>::value == true)
                                      && (std::numeric_limits<IntegralType>::digits <= std::numeric_limits<FloatingPointType>::digits))>::type const* = nullptr>
   constexpr cpp_double_float(const IntegralType& f) : data(std::make_pair(static_cast<float_type>(f), (float_type)0)) {}

   // Constructors from integers which hold more information than *this can contain
   template <typename UnsignedIntegralType,
             typename std::enable_if<(    (std::is_integral<UnsignedIntegralType>::value == true)
                                       && (std::is_unsigned<UnsignedIntegralType>::value == true)
                                       && (std::numeric_limits<UnsignedIntegralType>::digits > std::numeric_limits<float_type>::digits))>::type const* = nullptr>
   cpp_double_float(UnsignedIntegralType u)
   {
      constexpr int MantissaBits = std::numeric_limits<FloatingPointType>::digits - 1;

      int bit_index = sizeof(UnsignedIntegralType) * 8;

      for (;;)
      {
         // Mask the maximum number of bits that can be stored without
         // precision loss in a single FloatingPointType, then sum and shift
         UnsignedIntegralType hi = u >> (std::max)(bit_index - MantissaBits, 0);
         u &= ~(hi << (std::max)(bit_index - MantissaBits, 0));

         *this += static_cast<FloatingPointType>(hi);  // sum

         bit_index -= MantissaBits;

         if (bit_index < 0)
            break;
         else // shift
            eval_ldexp(*this, *this, (std::min)(MantissaBits, bit_index));
      }
   }

   template <typename SignedIntegralType,
             typename std::enable_if<(   (std::is_integral<SignedIntegralType>::value == true)
                                      && (std::is_signed<SignedIntegralType>::value == true)
                                      && (std::numeric_limits<SignedIntegralType>::digits + 1 > std::numeric_limits<float_type>::digits))>::type const* = nullptr>
   cpp_double_float(SignedIntegralType n) : cpp_double_float(static_cast<typename std::make_unsigned<SignedIntegralType>::type>(std::abs(n)))
   {
      if (n < 0)
         *this = -*this;
   }

   constexpr cpp_double_float(const float_type& a, const float_type& b) : data(std::make_pair(a, b)) {}
   constexpr cpp_double_float(const std::pair<float_type, float_type>& p) : data(p) {}

   cpp_double_float(const std::string& str)
   {
      boost::multiprecision::detail::convert_from_string(*this, str.c_str());
   }

   cpp_double_float(const char* pstr)
   {
      boost::multiprecision::detail::convert_from_string(*this, pstr);
   }

   constexpr cpp_double_float(cpp_double_float&&) = default;

   ~cpp_double_float() = default;

   std::size_t hash() const
   {
      // Here we first convert to scientific string, then
      // hash the charactgers in the scientific string.
      // TBD: Is there a faster or more simple hash method?

      const std::string str_to_hash = str(std::numeric_limits<cpp_double_float>::digits10, std::ios::scientific);

      std::size_t result = 0;

      for (std::string::size_type i = 0U; i < str_to_hash.length(); ++i)
         boost::multiprecision::detail::hash_combine(result, str_to_hash.at(i));

      return result;
   }

   // Casts
   operator   signed char     () const { return (signed char)data.first; }
   operator   signed short    () const { return (signed short)data.first; }
   operator   signed int      () const { return (signed int)data.first + (signed int)data.second; }
   operator   signed long     () const { return (signed long)data.first + (signed long)data.second; }
   operator   signed long long() const { return (signed long long)data.first + (signed long long)data.second; }
   operator unsigned char     () const { return (unsigned char)data.first; }
   operator unsigned short    () const { return (unsigned short)data.first; }
   operator unsigned int      () const { return (unsigned int)((unsigned int)data.first + (signed int)data.second); }
   operator unsigned long     () const { return (unsigned long)((unsigned long)data.first + (signed long)data.second); }
   operator unsigned long long() const { return (unsigned long long)((unsigned long long)data.first + (signed long long)data.second); }
   operator float             () const { return (float)data.first + (float)data.second; }
   operator double            () const { return (double)data.first + (double)data.second; }
   operator long double       () const { return (long double)data.first + (long double)data.second; }
#ifdef BOOST_MATH_USE_FLOAT128
   explicit operator boost::multiprecision::float128() const { return static_cast<boost::multiprecision::float128>(data.first) + static_cast<boost::multiprecision::float128>(data.second); }
#endif

   // Methods
   constexpr bool is_neg() const { return (data.first < 0); }

   bool is_zero() const { return (compare(cpp_double_float(0U)) == 0); }
   bool is_one () const { return (compare(cpp_double_float(1U)) == 0); }

   void negate()
   {
      data.first  = -data.first;
      data.second = -data.second;
   }

   // Getters/Setters
   constexpr const float_type& first () const { return data.first; }
   constexpr const float_type& second() const { return data.second; }

         rep_type&  rep()       { return data; }
   const rep_type&  rep() const { return data; }
   const rep_type& crep() const { return data; }

   // Retrieve debug string.
   std::string get_raw_str() const
   {
      std::stringstream ss;
      ss << std::hexfloat << data.first << " + " << std::hexfloat << data.second;
      return ss.str();
   }

   // Assignment operators.
   cpp_double_float& operator=(const cpp_double_float&) = default;

   cpp_double_float& operator=(cpp_double_float&&) = default;

   // Non-member add/sub/mul/div with constituent type.
   friend inline cpp_double_float operator+(const cpp_double_float& a, const float_type& b)
   {
      rep_type s = exact_sum(a.first(), b);

      s.second += a.second();
      normalize_pair(s);

      return cpp_double_float(s);
   }

   friend inline cpp_double_float operator-(const cpp_double_float& a, const float_type& b)
   {
      rep_type s = exact_difference(a.first(), b);

      s.second += a.second();
      normalize_pair(s);

      return cpp_double_float(s);
   }

   friend inline cpp_double_float operator*(const cpp_double_float& a, const float_type& b)
   {
      rep_type p = exact_product(a.first(), b);

      using std::isfinite;

      if (!isfinite(p.first))
         return cpp_double_float(p);

      p.second += a.second() * b;

      normalize_pair(p);

      return cpp_double_float(p);
   }

   friend inline cpp_double_float operator/(const cpp_double_float& a, const float_type& b)
   {
      rep_type p, q, s;

      p.first = a.first() / b;

      q = exact_product(p.first, b);
      s = exact_difference(a.first(), q.first);
      s.second += a.second();
      s.second -= q.second;

      p.second = (s.first + s.second) / b;

      normalize_pair(p);

      return cpp_double_float(p);
   }

   // Unary add/sub/mul/div with constituent part.
   cpp_double_float& operator+=(const float_type& a) { *this = *this + a; return *this; }
   cpp_double_float& operator-=(const float_type& a) { *this = *this - a; return *this; }
   cpp_double_float& operator*=(const float_type& a) { *this = *this * a; return *this; }
   cpp_double_float& operator/=(const float_type& a) { *this = *this / a; return *this; }

   // Unary add/sub/mul/div.
   cpp_double_float& operator+=(const cpp_double_float& other)
   {
      const rep_type t = exact_sum(second(), other.second());

      data = exact_sum(first(),  other.first());

      using std::isfinite;

      if (!isfinite(first()))
         return *this;

      data.second += t.first;
      normalize_pair(data);
      data.second += t.second;
      normalize_pair(data);

      return *this;
   }

   cpp_double_float& operator-=(const cpp_double_float& other)
   {
      const rep_type t = exact_difference(second(), other.second());
      data = exact_difference(first(), other.first());

      using std::isfinite;

      if (!isfinite(first()))
         return *this;

      data.second += t.first;
      normalize_pair(data);

      data.second += t.second;
      normalize_pair(data);

      return *this;
   }

   cpp_double_float& operator*=(const cpp_double_float& other)
   {
      rep_type tmp = exact_product(data.first, other.data.first);

      tmp.second += (  data.first  * other.data.second
                     + data.second * other.data.first);

      data = tmp;

      return *this;
   }

   cpp_double_float& operator/=(const cpp_double_float& other)
   {
      rep_type p;

      // First approximation
      p.first = first() / other.first();

      using std::isfinite;

      if (!isfinite(p.first))
      {
         data = p;
         return *this;
      }

      cpp_double_float r = *this - (other * p.first);

      p.second = r.first() / other.first();
      r -= other * p.second;

      const FloatingPointType p_prime = r.first() / other.first();

      normalize_pair(p);

      data = p;

      operator+=(p_prime);

      return *this;
   }

   cpp_double_float  operator++(int) { cpp_double_float t(*this); ++*this; return t; }
   cpp_double_float  operator--(int) { cpp_double_float t(*this); --*this; return t; }
   cpp_double_float& operator++() { return *this += cpp_double_float<float_type>(float_type(1.0F)); }
   cpp_double_float& operator--() { return *this -= cpp_double_float<float_type>(float_type(1.0F)); }

   cpp_double_float  operator-() const { cpp_double_float v(*this); v.negate(); return v; }

   // Helper functions
   static cpp_double_float pown(const cpp_double_float& x, int p)
   {
      using local_float_type = cpp_double_float;

      local_float_type result;

      if      (p <  0) result = pown(local_float_type(1U) / x, -p);
      else if (p == 0) result = local_float_type(1U);
      else if (p == 1) result = x;
      else if (p == 2) result = local_float_type(x * x);
      else if (p == 3) result = local_float_type((x * x) * x);
      else
      {
         result = local_float_type(1U);

         local_float_type y(x);

         std::uint32_t p_local = (std::uint32_t) p;

         for (;;)
         {
            if (std::uint_fast8_t(p_local & 1U) != 0U) { result *= y; }

            p_local >>= 1U;

            if (p_local == 0U) { break; }
            else               { y *= y; }
         }
      }

      return result;
   }

   static void normalize_pair(rep_type& p, bool fast = true)
   {
      // Converts a pair of floats to standard form
      //BOOST_ASSERT(std::isfinite(p.first));
      p = (fast ? fast_exact_sum(p.first, p.second) : exact_sum(p.first, p.second));
   }

   void swap(cpp_double_float& other)
   {
      rep_type tmp = data;

      data = other.data;

      other.data = tmp;
   }

   constexpr int compare(const cpp_double_float& other) const
   {
     // Return 1 for *this > other, -1 for *this < other, 0 for *this = other.
     return (first () > other.first ()) ?  1 :
            (first () < other.first ()) ? -1 :
            (second() > other.second()) ?  1 :
            (second() < other.second()) ? -1 : 0;
   }

   std::string str(std::streamsize number_of_digits, const std::ios::fmtflags format_flags) const
   {
      if (number_of_digits == 0)
         number_of_digits = std::numeric_limits<cpp_double_float>::digits10;

      const std::string my_str = boost::multiprecision::detail::convert_to_string(*this, number_of_digits, format_flags);

      return my_str;
   }

 private:
   rep_type data;

   static rep_type split(const float_type& a)
   {
      // Split a floating point number in two (high and low) parts approximating the
      // upper-half and lower-half bits of the float
      //static_assert(std::numeric_limits<float_type>::is_iec559,
      //              "double_float<> invoked with non-native floating-point unit");

      // TODO Replace bit shifts with constexpr funcs or ldexpr for better compaitibility
      constexpr int        MantissaBits   = std::numeric_limits<float_type>::digits;
      constexpr int        SplitBits      = MantissaBits / 2 + 1;
      constexpr float_type Splitter       = FloatingPointType((1ULL << SplitBits) + 1);
      const     float_type SplitThreshold = (std::numeric_limits<float_type>::max)() / (Splitter*2);

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

   static rep_type fast_exact_sum(const float_type& a, const float_type& b)
   {
      // Exact addition of two floating point numbers, given |a| > |b|
      using std::fabs;
      using std::isnormal;

      rep_type out;
      out.first  = a + b;
      out.second = b - (out.first - a);

      return out;
   }

   static rep_type exact_sum(const float_type& a, const float_type& b)
   {
      // Exact addition of two floating point numbers
      rep_type out;

      out.first    = a + b;
      float_type v = out.first - a;
      out.second   = (a - (out.first - v)) + (b - v);

      return out;
   }

   static rep_type exact_difference(const float_type& a, const float_type& b)
   {
      // Exact subtraction of two floating point numbers
      rep_type out;

      out.first    = a - b;
      float_type v = out.first - a;
      out.second   = (a - (out.first - v)) - (b + v);

      return out;
   }

   static rep_type exact_product(const float_type& a, const float_type& b)
   {
      // Exact product of two floating point numbers
      const rep_type a_split = split(a);
      const rep_type b_split = split(b);

      const volatile float_type pf = a * b;

      return std::make_pair
      (
         (const float_type&) pf,
         (
            ((a_split.first  * b_split.first) - (const float_type&) pf)
          +  (a_split.first  * b_split.second)
          +  (a_split.second * b_split.first)
         )
         + (a_split.second * b_split.second)
      );
   }

   int  order10  () const { using std::log10; return static_cast<int>(log10(first()) + float_type(0.5F) * float_type(is_zero() ? 0 : (is_neg() ? -1 : 1))); }
   bool small_arg() const { return (order10() < (-std::numeric_limits<cpp_double_float>::digits10 / 6)); }
   bool near_one () const { return cpp_double_float(fabs(cpp_double_float(1U) - *this)).small_arg(); }

   template<typename OtherFloatingPointType>
   friend void eval_exp(cpp_double_float<OtherFloatingPointType>& result, const cpp_double_float<OtherFloatingPointType>& x);
};

template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator+(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b) { return cpp_double_float<FloatingPointType>(a) += b; }
template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator-(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b) { return cpp_double_float<FloatingPointType>(a) -= b; }
template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator*(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b) { return cpp_double_float<FloatingPointType>(a) *= b; }
template<typename FloatingPointType> inline cpp_double_float<FloatingPointType> operator/(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b) { return cpp_double_float<FloatingPointType>(a) /= b; }

template<typename FloatingPointType> inline bool operator< (const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b) { return (a.compare(b) <  0); }
template<typename FloatingPointType> inline bool operator<=(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b) { return (a.compare(b) <= 0); }
template<typename FloatingPointType> inline bool operator==(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b) { return (a.compare(b) == 0); }
template<typename FloatingPointType> inline bool operator!=(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b) { return (a.compare(b) != 0); }
template<typename FloatingPointType> inline bool operator>=(const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b) { return (a.compare(b) >= 0); }
template<typename FloatingPointType> inline bool operator> (const cpp_double_float<FloatingPointType>& a, const cpp_double_float<FloatingPointType>& b) { return (a.compare(b) >  0); }

// -- Input/Output Streaming
template <typename FloatingPointType, typename char_type, typename traits_type>
std::basic_ostream<char_type, traits_type>&
operator<<(std::basic_ostream<char_type, traits_type>& os, const cpp_double_float<FloatingPointType>& f)
{
   const std::string str_result = f.str(os.precision(), os.flags());

   return (os << str_result);
}

template <typename FloatingPointType, typename char_type, typename traits_type>
std::basic_istream<char_type, traits_type>&
operator>>(std::basic_istream<char_type, traits_type>& is, cpp_double_float<FloatingPointType>& f)
{
   std::string str;
   is >> str;
   boost::multiprecision::detail::convert_from_string(f, str.c_str());
   return is;
}

template<typename FloatingPointType> void eval_add     (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x) { result += x; }
template<typename FloatingPointType> void eval_subtract(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x) { result -= x; }
template<typename FloatingPointType> void eval_multiply(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x) { result *= x; }
template<typename FloatingPointType> void eval_divide  (cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x) { result /= x; }

template<typename FloatingPointType> void eval_fabs(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& a)
{
   if(a.is_neg())
   {
      result.rep().first  = -a.rep().first;
      result.rep().second = -a.rep().second;
   }
   else
   {
      result.rep().first  = a.rep().first;
      result.rep().second = a.rep().second;
   }
}

template<typename FloatingPointType> void eval_frexp(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& a, int* v)
{
   using std::frexp;
   using std::ldexp;

   result.rep().first  = frexp(a.rep().first,    v);
   result.rep().second = ldexp(a.rep().second, -*v);
}

template<typename FloatingPointType>
void eval_ldexp(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& a, int v)
{
   using std::ldexp;

   typename cpp_double_float<FloatingPointType>::rep_type z =
   std::make_pair
   (
      ldexp(a.crep().first,  v),
      ldexp(a.crep().second, v)
   );

   cpp_double_float<FloatingPointType>::normalize_pair(z);

   result.rep() = z;
}

template<typename FloatingPointType>
void eval_floor(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x)
{
   using double_float_type = cpp_double_float<FloatingPointType>;

   using std::floor;

   const typename double_float_type::float_type fhi = floor(x.rep().first);

   if(fhi != x.first())
   {
      result.rep().first  = fhi;
      result.rep().second = static_cast<typename double_float_type::float_type>(0.0F);
   }
   else
   {
      result.rep().first  = fhi;
      result.rep().second = floor(x.rep().second);

      double_float_type::normalize_pair(result.rep());
   }
}

template<typename FloatingPointType>
void eval_ceil(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x)
{
   // Compute -floor(-x);
   eval_floor(result, -x);

   result.negate();
}

template<typename FloatingPointType>
int eval_fpclassify(const cpp_double_float<FloatingPointType>& o)
{
   return (int) (boost::math::fpclassify)(o.crep().first);
}

template<typename FloatingPointType>
void eval_sqrt(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& o)
{
   using local_float_type = typename cpp_double_float<FloatingPointType>::float_type;

   using std::sqrt;

   local_float_type c = sqrt(o.crep().first);

   local_float_type p,q,hx,tx,u,uu,cc;
   local_float_type t1;

   constexpr int              MantissaBits = std::numeric_limits<local_float_type>::digits;
   constexpr int              SplitBits    = MantissaBits / 2 + 1;
   constexpr local_float_type Splitter     = local_float_type((1ULL << SplitBits) + 1);

   p = Splitter * c;
   hx = (c-p);
   hx = hx+p;
   tx = c-hx;
   p = hx*hx;
   q = hx*tx;
   q = q+q;

   u = p+q;
   uu = p-u;
   uu = uu+q;
   t1 = tx*tx;
   uu = uu+t1;

   cc = o.crep().first-u;
   cc = cc-uu;
   cc = cc+o.crep().second;
   t1 = c+c;
   cc = cc/t1;

   hx = c+cc;
   tx = c-hx;
   tx = tx+cc;

   result.rep().first  = hx;
   result.rep().second = tx;
}

template<typename FloatingPointType>
void eval_exp(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x)
{
   if(eval_fpclassify(x) != (int) FP_NORMAL)
   {
      result = x;
   }
   else
   {
      using double_float_type = cpp_double_float<FloatingPointType>;
      using local_float_type  = typename cpp_double_float<FloatingPointType>::float_type;

      // Get a local copy of the argument and force it to be positive.
      const bool b_neg = x.is_neg();

      double_float_type xx;

      eval_fabs(xx, x);

      // Check the range of the input. Will it overflow?
      using std::log;

      static const local_float_type max_exp_input = log((std::numeric_limits<local_float_type>::max)());
      static const local_float_type min_exp_input = log((std::numeric_limits<local_float_type>::min)());

      if(xx.is_zero() || xx.crep().first < min_exp_input)
      {
         result = double_float_type(1U);
      }
      else if(xx.crep().first > max_exp_input)
      {
         result = double_float_type(std::numeric_limits<local_float_type>::quiet_NaN());
      }
      else if(xx.is_one())
      {
         static const double_float_type constant_e         (std::string("2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274"));
         static const double_float_type constant_one_over_e(std::string("0.36787944117144232159552377016146086744581113103176783450783680169746149574489980335714727434591964375"));

         result = ((b_neg == false) ? constant_e : constant_one_over_e);
      }
      else
      {
         // Use an argument reduction algorithm for exp() in classic MPFUN-style.
         static const double_float_type constant_ln2         (std::string("0.69314718055994530941723212145817656807550013436025525412068000949339362196969471560586332699641868754"));
         static const double_float_type constant_one_over_ln2(std::string("1.4426950408889634073599246810018921374266459541529859341354494069311092191811850798855266228935063445"));

         double_float_type nf;

         eval_floor(nf, xx * constant_one_over_ln2);

         // Prepare the scaled variables.
         static const int p2        = 256;
         const bool b_scale         = xx.order10() > -4;
         const double_float_type r  = b_scale ? (xx - nf * constant_ln2) / double_float_type(p2) : xx;
         const double_float_type r2 = r * r;
         const double_float_type r4 = r2 * r2;

         // Use a Pade approximation of Order[6].
         // Pade[Exp[r], {r, 0, 6, 6}]
         // FullSimplify[%]

         static const double_float_type n84  (  84);
         static const double_float_type n240 ( 240);
         static const double_float_type n7920(7920);
  
         static const double_float_type n665280(665280);
         static const double_float_type n332640(332640);
         static const double_float_type n75600 ( 75600);
         static const double_float_type n10080 ( 10080);
         static const double_float_type n840   (   840);
         static const double_float_type n42    (    42);

         result = double_float_type(1U) +   (n84 * r * (n7920 + n240 * r2 + r4))
                                          / (n665280 + r * (-n332640 + r * (n75600 + r * (-n10080 + r * (n840 + (-n42 + r) * r)))));

         // Rescale the result.
         if(b_scale)
         {
            result *= result;
            result *= result;
            result *= result;
            result *= result;
            result *= result;
            result *= result;
            result *= result;
            result *= result;

            const int n = (int) nf;

            if(n > 0)
            {
               result *= double_float_type::pown(double_float_type(2U), n);
            }
         }

         if(b_neg)
         {
            result = double_float_type(1U) / result;
         }
      }
   }
}

template<typename FloatingPointType>
void eval_log(cpp_double_float<FloatingPointType>& result, const cpp_double_float<FloatingPointType>& x)
{
   using double_float_type = cpp_double_float<FloatingPointType>;

   if(eval_fpclassify(x) != (int) FP_NORMAL)
   {
      result = x;
   }
   else if(x.is_neg())
   {
      result = std::numeric_limits<double_float_type>::quiet_NaN();
   }
   else if(x.is_one())
   {
      result = double_float_type(0U);
   }
   else
   {
      using std::log;

      // Get initial estimate using the standard math function log.
      const double_float_type s(log(x.crep().first));
            double_float_type E;

      eval_exp(E, s);

      // Do one single step of Newton-Raphson iteration
      result = s + (x - E) / E;
   }
}

template<typename FloatingPointType,
         typename R>
typename std::enable_if<std::is_integral<R>::value == true>::type eval_convert_to(R* result, const cpp_double_float<FloatingPointType>& backend)
{
   // TBD: Does boost::common_type have a C++ 11 replacement?
   using c_type = typename boost::common_type<R, FloatingPointType>::type;

   using std::fabs;

   BOOST_CONSTEXPR const c_type my_max = static_cast<c_type>((std::numeric_limits<R>::max)());
   BOOST_CONSTEXPR const c_type my_min = static_cast<c_type>((std::numeric_limits<R>::min)());
   c_type                       ct     = fabs(backend.crep().first);

   (void) my_min;

   if (ct > my_max)
      if (!std::is_unsigned<R>::value)
         *result = backend.crep().first >= typename cpp_double_float<FloatingPointType>::float_type(0U) ? (std::numeric_limits<R>::max)() : detail::minus_max<R>();
      else
         *result = (std::numeric_limits<R>::max)();
   else
   {
      *result  = static_cast<R>(backend.crep().first);
      *result += static_cast<R>(backend.crep().second);
   }
}

template<typename FloatingPointType,
         typename R>
typename std::enable_if<std::is_integral<R>::value == false>::type eval_convert_to(R* result, const cpp_double_float<FloatingPointType>& backend)
{
   *result  = R(backend.crep().first);
   *result += R(backend.crep().second);
}

template<typename FloatingPointType>
cpp_double_float<FloatingPointType> fabs(const cpp_double_float<FloatingPointType>& a)
{
   using double_float_type = cpp_double_float<FloatingPointType>;

   double_float_type result;

   eval_fabs(result, a);

   return result;
}

template<typename FloatingPointType>
std::size_t hash_value(const cpp_double_float<FloatingPointType>& a)
{
   return a.hash();
}

} } } // namespace boost::multiprecision::backends

namespace boost { namespace math {

template<typename FloatingPointType>
int fpclassify(const boost::multiprecision::backends::cpp_double_float<FloatingPointType>& o)
{
   using std::fpclassify;

   return (int) (fpclassify)(o.crep().first);
}

} }


namespace std {

// Specialization of numeric_limits for cpp_double_float<>
template <typename FloatingPointType>
class numeric_limits<boost::multiprecision::backends::cpp_double_float<FloatingPointType>>
  : public std::numeric_limits<FloatingPointType>
{
private:
   using base_class_type = std::numeric_limits<FloatingPointType>;

   using self_type = boost::multiprecision::backends::cpp_double_float<FloatingPointType>;

public:
   static constexpr bool is_iec559   = false;
   static constexpr std::float_denorm_style has_denorm = std::denorm_absent;

   static constexpr int digits       = 2 * (base_class_type::digits - 1);
   static constexpr int digits10     = int(float(digits - 1) * 0.301F);
   static constexpr int max_digits10 = int(float(digits)     * 0.301F) + 2;

   static constexpr int max_exponent = std::numeric_limits<FloatingPointType>::max_exponent - base_class_type::digits;
   static constexpr int min_exponent = std::numeric_limits<FloatingPointType>::min_exponent + base_class_type::digits;

   //static constexpr self_type (min)         () noexcept { return self_type((base_class_type::min)()); } // FIXME
   //static constexpr self_type (max)         () noexcept { return self_type((base_class_type::max)()); } // FIXME
   //static constexpr self_type  lowest       () noexcept { return self_type( base_class_type::lowest()); } // FIXME
   //static constexpr self_type  epsilon      () noexcept { return boost::multiprecision::ldexp(self_type(1), -digits); } // FIXME
   //static constexpr self_type  epsilon() noexcept { return self_type(self_type::my_value_eps()); }
   //static constexpr self_type  round_error  () noexcept { return self_type( base_class_type::round_error()); }  // FIXME
   //static constexpr self_type  denorm_min   () noexcept { return self_type( base_class_type::denorm_min()); } // FIXME

   // TODO Are these values rigorous?
   static constexpr self_type (min)         () noexcept { return self_type( boost::multiprecision::ldexp(self_type(1), -min_exponent)); }
   static constexpr self_type (max)         () noexcept { return self_type( boost::multiprecision::ldexp(base_class_type::max, -base_class_type::digits)); }
   static constexpr self_type  lowest       () noexcept { return self_type(-max()); }
   static constexpr self_type  epsilon      () noexcept { return self_type( boost::multiprecision::ldexp(self_type(1), -digits)); }
   static constexpr self_type  round_error  () noexcept { return self_type( base_class_type::round_error()); } 
   static constexpr self_type  denorm_min   () noexcept { return self_type( min()); }
   
   static constexpr self_type  infinity     () noexcept { return self_type( base_class_type::infinity()); }
   static constexpr self_type  quiet_NaN    () noexcept { return self_type( base_class_type::quiet_NaN()); }
   static constexpr self_type  signaling_NaN() noexcept { return self_type( base_class_type::signaling_NaN()); }
};

// Specialization of numeric_limits for boost::multiprecision::number<cpp_double_float<>>
template <typename FloatingPointType,
          const boost::multiprecision::expression_template_option ExpressionTemplatesOption>
class numeric_limits<boost::multiprecision::number<boost::multiprecision::backends::cpp_double_float<FloatingPointType>, ExpressionTemplatesOption>>
   : public std::numeric_limits<FloatingPointType>
{
private:
   using base_class_type = std::numeric_limits<FloatingPointType>;

   using self_type =
      boost::multiprecision::number<boost::multiprecision::backends::cpp_double_float<FloatingPointType>, ExpressionTemplatesOption>;

public:
   static constexpr bool is_iec559                     = false;
   static constexpr std::float_denorm_style has_denorm = std::denorm_absent;

   static constexpr int digits       = (2 * base_class_type::digits) - 2;
   static constexpr int digits10     = int(float(digits - 1) * 0.301F);
   static constexpr int max_digits10 = int(float(digits)     * 0.301F) + 2;

   static constexpr int max_exponent = std::numeric_limits<FloatingPointType>::max_exponent - base_class_type::digits;
   static constexpr int min_exponent = std::numeric_limits<FloatingPointType>::min_exponent + base_class_type::digits;

   //static constexpr self_type (min)         () noexcept { return self_type((base_class_type::min)()); } // FIXME
   //static constexpr self_type (max)         () noexcept { return self_type((base_class_type::max)()); } // FIXME
   //static constexpr self_type  lowest       () noexcept { return self_type( base_class_type::lowest()); } // FIXME
   //static constexpr self_type  epsilon() noexcept { return self_type(boost::multiprecision::backends::cpp_double_float<FloatingPointType>::my_value_eps()); }
   //static constexpr self_type  round_error  () noexcept { return self_type( base_class_type::round_error()); }  // FIXME
   //static constexpr self_type  denorm_min   () noexcept { return self_type( base_class_type::denorm_min()); } // FIXME

   static const     self_type (min)         () noexcept { using std::ldexp; return self_type( ldexp(self_type(1), -min_exponent)); }
   static const     self_type (max)         () noexcept { using std::ldexp; return self_type( ldexp(base_class_type::max(), -base_class_type::digits)); }
   static const     self_type  lowest       () noexcept { return self_type(-(max)()); }
   static const     self_type  epsilon      () noexcept { using std::ldexp; return self_type( ldexp(self_type(1), -digits)); }
   static constexpr self_type  round_error  () noexcept { return self_type( base_class_type::round_error()); } 
   static const     self_type  denorm_min   () noexcept { return self_type( (min)()); }

   static constexpr self_type  infinity     () noexcept { return self_type( base_class_type::infinity()); }
   static constexpr self_type  quiet_NaN    () noexcept { return self_type( base_class_type::quiet_NaN()); }
   static constexpr self_type  signaling_NaN() noexcept { return self_type( base_class_type::signaling_NaN()); }
};

}

#endif // BOOST_MP_CPP_DOUBLE_FLOAT_2021_06_05_HPP

//
//                              libieeep1788
//
//   An implementation of the preliminary IEEE P1788 standard for
//   interval arithmetic
//
//
//   Copyright 2013
//
//   Marco Nehmeier (nehmeier@informatik.uni-wuerzburg.de)
//   Institute of Computer Science,
//   University of Wuerzburg, Germany
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#ifndef LIBIEEEP1788_P1788_FLAVOR_INFSUP_SETBASED_MPFR_BIN_IEEE754_FLAVOR_CLASS_IMPL_HPP
#define LIBIEEEP1788_P1788_FLAVOR_INFSUP_SETBASED_MPFR_BIN_IEEE754_FLAVOR_CLASS_IMPL_HPP


namespace p1788
{

namespace flavor
{

namespace infsup
{

namespace setbased
{

// Constructors

template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation
mpfr_bin_ieee754_flavor<T>::constructor()
{
    return empty();
}

template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::constructor_dec()
{
    return empty_dec();
}


template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation
mpfr_bin_ieee754_flavor<T>::constructor(T lower, T upper)
{
    // Comparison with NaN is always false!
    if (lower <= upper
    && lower != std::numeric_limits<T>::infinity()
    && upper != -std::numeric_limits<T>::infinity())
    {
        return representation(lower, upper);
    }
    else
    {
        return empty();
    }
}

template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::constructor_dec(T lower, T upper)
{
    // Comparison with NaN is always false!
    if (lower <= upper
    && lower != std::numeric_limits<T>::infinity()
    && upper != -std::numeric_limits<T>::infinity())
    {
        return constructor_dec(constructor(lower,upper));
    }
    else
    {
        return nai();
    }
}

template<typename T>
template<typename L_, typename U_>
typename mpfr_bin_ieee754_flavor<T>::representation
mpfr_bin_ieee754_flavor<T>::constructor(L_ lower, U_ upper)
{
    static_assert(std::numeric_limits<L_>::is_iec559, "Only IEEE 754 binary compliant types are supported!");
    static_assert(std::numeric_limits<U_>::is_iec559, "Only IEEE 754 binary compliant types are supported!");

    return constructor(convert_rndd(lower), convert_rndu(upper));
}

template<typename T>
template<typename L_, typename U_>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::constructor_dec(L_ lower, U_ upper)
{
    static_assert(std::numeric_limits<L_>::is_iec559, "Only IEEE 754 binary compliant types are supported!");
    static_assert(std::numeric_limits<U_>::is_iec559, "Only IEEE 754 binary compliant types are supported!");

    return constructor_dec(convert_rndd(lower), convert_rndu(upper));
}


template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation
mpfr_bin_ieee754_flavor<T>::constructor(std::string const& str)
{
    LIBIEEEP1788_NOT_IMPLEMENTED;

    std::string tmp = str;

    tmp.erase(remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);

    if (tmp == "[ENTIRE]")
        return entire();

    if (tmp == "[EMPTY]")
        return empty();

    return representation(0.0, 0.0);
}

template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::constructor_dec(std::string const& str)
{
    LIBIEEEP1788_NOT_IMPLEMENTED;

    std::string tmp = str;

    tmp.erase(remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);

    if (tmp == "[ENTIRE]")
        return entire_dec();

    if (tmp == "[EMPTY]")
        return empty_dec();

    return representation_dec(representation(0.0, 0.0), p1788::decoration::decoration::trv);
}


template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation
mpfr_bin_ieee754_flavor<T>::constructor(representation const& other)
{
    return other;
}

template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::constructor_dec(representation_dec const& other)
{
    return other;
}


template<typename T>
template<typename T_>
typename mpfr_bin_ieee754_flavor<T>::representation
mpfr_bin_ieee754_flavor<T>::constructor(representation_type<T_> const& other)
{
    mpfr_var::setup();

    mpfr_var lower(other.first, MPFR_RNDD);
    mpfr_var upper(other.second, MPFR_RNDU);

    return representation(lower.template get<T>(MPFR_RNDD), upper.template get<T>(MPFR_RNDU));
}

template<typename T>
template<typename T_>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::constructor_dec(representation_dec_type<T_> const& other)
{
    mpfr_var::setup();

    mpfr_var lower(other.first.first, MPFR_RNDD);
    mpfr_var upper(other.first.second, MPFR_RNDU);

    return representation_dec(representation(lower.template get<T>(MPFR_RNDD), upper.template get<T>(MPFR_RNDU)), other.second);
}



template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation
mpfr_bin_ieee754_flavor<T>::constructor(representation_dec const& other)
{
    return empty();
}

template<typename T>
template<typename T_>
typename mpfr_bin_ieee754_flavor<T>::representation
mpfr_bin_ieee754_flavor<T>::constructor(representation_dec_type<T_> const& other)
{
    static_assert(std::numeric_limits<T_>::is_iec559, "Only IEEE 754 binary compliant types are supported!");
        return empty();
}

template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::constructor_dec(representation const& other)
{
    if (is_empty(other)) {
        return representation_dec(other, p1788::decoration::decoration::trv);
    } else if (other.first == -std::numeric_limits<T>::infinity() || other.second == std::numeric_limits<T>::infinity()) {
        return representation_dec(other, p1788::decoration::decoration::dac);
    } else {
        return representation_dec(other, p1788::decoration::decoration::com);
    }
}

template<typename T>
template<typename T_>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::constructor_dec(representation_type<T_> const& other)
{
    static_assert(std::numeric_limits<T_>::is_iec559, "Only IEEE 754 binary compliant types are supported!");

    return constructor(convert_hull(other));
}


template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::constructor_dec(representation const& other, p1788::decoration::decoration dec)
{
    return empty_dec();
}

template<typename T>
template<typename T_>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::constructor_dec(representation_type<T_> const& other, p1788::decoration::decoration dec)
{
    return empty_dec();
}

// -----------------------------------------------------------------------------
// Interval constants
// -----------------------------------------------------------------------------

// empty bare interval
template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation
mpfr_bin_ieee754_flavor<T>::empty()
{
    return representation(std::numeric_limits<T>::quiet_NaN(),
                          std::numeric_limits<T>::quiet_NaN());
}

// empty decorated interval
template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::empty_dec()
{
    return representation_dec(representation(std::numeric_limits<T>::quiet_NaN(),
                          std::numeric_limits<T>::quiet_NaN()), p1788::decoration::decoration::trv);
}

// entire bare interval
template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation
mpfr_bin_ieee754_flavor<T>::entire()
{
    return representation(-std::numeric_limits<T>::infinity(),
                          std::numeric_limits<T>::infinity());
}

// entire decorated interval
template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::entire_dec()
{
    return representation_dec(representation(-std::numeric_limits<T>::infinity(),
                          std::numeric_limits<T>::infinity()), p1788::decoration::decoration::dac);
}

// nai decorated interval
template<typename T>
typename mpfr_bin_ieee754_flavor<T>::representation_dec
mpfr_bin_ieee754_flavor<T>::nai()
{
    return representation_dec(representation(std::numeric_limits<T>::quiet_NaN(),
                          std::numeric_limits<T>::quiet_NaN()), p1788::decoration::decoration::ill);
}


} // namespace setbased

} // namespace infsup

} // namespace flavor

} // namespace p1788


#endif // LIBIEEEP1788_P1788_FLAVOR_INFSUP_SETBASED_MPFR_BIN_IEEE754_FLAVOR_CLASS_IMPL_HPP

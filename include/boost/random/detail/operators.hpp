/* boost random/detail/operators.hpp header file
 *
 * Copyright Steven Watanabe 2010
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org for most recent version including documentation.
 *
 * $Id$
 */

#ifndef BOOST_RANDOM_DETAIL_OPERATORS_HPP
#define BOOST_RANDOM_DETAIL_OPERATORS_HPP

#include <boost/random/detail/config.hpp>

#if BOOST_WORKAROUND(BOOST_MSVC, <= 1310)

#define BOOST_RANDOM_DETAIL_OSTREAM_OPERATOR(os, T, t)                  \
    template<class CharT, class Traits>                                 \
    friend std::basic_ostream<CharT,Traits>&                            \
    operator<<(std::basic_ostream<CharT,Traits>& os, const T& t) {      \
        t.print(os, t);                                                 \
        return os;                                                      \
    }                                                                   \
    template<class CharT, class Traits>                                 \
    static std::basic_ostream<CharT,Traits>&                            \
    print(std::basic_ostream<CharT,Traits>& os, const T& t)

#define BOOST_RANDOM_DETAIL_ISTREAM_OPERATOR(is, T, t)                  \
    template<class CharT, class Traits>                                 \
    friend std::basic_istream<CharT,Traits>&                            \
    operator>>(std::basic_istream<CharT,Traits>& is, T& t) {            \
        t.read(is, t);                                                  \
        return is;                                                      \
    }                                                                   \
    template<class CharT, class Traits>                                 \
    static std::basic_istream<CharT,Traits>&                            \
    read(std::basic_istream<CharT,Traits>& is, T& t)

#endif

#ifndef BOOST_RANDOM_DETAIL_OSTREAM_OPERATOR
#define BOOST_RANDOM_DETAIL_OSTREAM_OPERATOR(os, T, t)                  \
    template<class CharT, class Traits>                                 \
    friend std::basic_ostream<CharT,Traits>&                            \
    operator<<(std::basic_ostream<CharT,Traits>& os, const T& t)
#endif

#ifndef BOOST_RANDOM_DETAIL_ISTREAM_OPERATOR
#define BOOST_RANDOM_DETAIL_ISTREAM_OPERATOR(is, T, t)                  \
    template<class CharT, class Traits>                                 \
    friend std::basic_istream<CharT,Traits>&                            \
    operator>>(std::basic_istream<CharT,Traits>& is, T& t)
#endif

#ifndef BOOST_RANDOM_DETAIL_EQUALITY_OPERATOR
#define BOOST_RANDOM_DETAIL_EQUALITY_OPERATOR(T, lhs, rhs)              \
    friend bool operator==(const T& lhs, const T& rhs)
#endif

#ifndef BOOST_RANDOM_DETAIL_INEQUALITY_OPERATOR
#define BOOST_RANDOM_DETAIL_INEQUALITY_OPERATOR(T)                      \
    friend bool operator!=(const T& lhs, const T& rhs)                  \
    { return !(lhs == rhs); }
#endif

#endif
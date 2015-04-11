#ifndef UTILITY_TEMPLATE_FUNCTIONS_HPP
#define UTILITY_TEMPLATE_FUNCTIONS_HPP

#include <limits>
#include <typeinfo>
#include <type_traits>

/*
 * Constraints	: T should be an unsigned integral type.
 * Functionality: Calculates the sum of all the multiples of a number (n),
 *				  smaller than or equal to the given number (target).
*/
template <typename T>
T sum_divisible_by(T n, T upper_limit) {

    if(std::is_floating_point<T>() || std::is_signed<T>()) {
        std::cerr << "sum_divisible_by() does not support floating point numbers and signed numbers"
                  << std::endl;
        return 0;
    }

    if(upper_limit > std::numeric_limits<T>::max()) {
        std::cerr << "upper_limit is greater than the max value of "
                  << typeid(T).name() << std::endl;
        return 0;
    }

    unsigned long long int p = upper_limit / n;
    return static_cast<unsigned long long int>(n)*(p*(p+1)/2);
}

#endif

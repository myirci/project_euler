#ifndef UTILITY_FUNCTIONS_HPP
#define UTILITY_FUNCTIONS_HPP

// Constraints	: T should be an unsigned integral type. 
// Functionality: Calculates the sum of all the multiples of a number (n),
//				  smaller than or equal to the given number (target).
template <typename T>
T sum_divisible_by(T target, T n) {
	T p = target / n;
	return n*(p*(p+1)/2);
}

#endif

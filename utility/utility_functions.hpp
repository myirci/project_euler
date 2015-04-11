#ifndef UTILITY_FUNCTIONS_HPP
#define UTILITY_FUNCTIONS_HPP

/*
 * returns the sum of the numbers which are
 * - divisible by n
 * - smaller than or equal to upper_limit
 */
long long int sum_divisible_by(int n, int upper_limit);

/*
 * returns the nth fibonacci number in the fibonacci sequence
 * - n starts from '0'.
 */
long long int fibonacci(int n);

/*
 * print min max values of integrals,
 * fundamental integral types: bool, char, char16_t, char32_t, wchar_t, signed char,
 * short int, int, long int, long long int, unsigned char, unsigned short int,
 * unsigned int, unsigned long int, unsigned long long int
 */
void print_min_max_values();


#endif

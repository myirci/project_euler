#include "utility_functions.hpp"
#include <iostream>
#include <limits>

long long int sum_divisible_by(int n, int upper_limit) {

    unsigned long long int p = upper_limit / n;
    return static_cast<unsigned long long int>(n)*(p*(p+1)/2);
}

long long int fibonacci(int n) {

    if(n < 2) return 1;
    else      return fibonacci(n-1) + fibonacci(n-2);
}

void print_min_max_values() {

    std::cout << "bool \t\t : < "
              << std::numeric_limits<bool>::min() << ", "
              << std::numeric_limits<bool>::max() << " > " << std::endl;

    std::cout << "char \t\t : < "
              << static_cast<int>(std::numeric_limits<char>::min()) << ", "
              << static_cast<int>(std::numeric_limits<char>::max()) << " > "
              << std::endl;

    std::cout << "unsigned char \t : < "
              << static_cast<int>(std::numeric_limits<unsigned char>::min()) << ", "
              << static_cast<int>(std::numeric_limits<unsigned char>::max()) << " > "
              << std::endl;

    std::cout << "char16_t \t\t : < "
              << std::numeric_limits<char16_t>::min() << ", "
              << std::numeric_limits<char16_t>::max() << " > " << std::endl;

    std::cout << "char32_t \t\t : < "
              << std::numeric_limits<char32_t>::min() << ", "
              << std::numeric_limits<char32_t>::max() << " > " << std::endl;

    std::cout << "wchar_t \t\t : < "
              << std::numeric_limits<wchar_t>::min() << ", "
              << std::numeric_limits<wchar_t>::max() << " > " << std::endl;

    std::cout << "signed char \t : < "
              << static_cast<int>(std::numeric_limits<signed char>::min()) << ", "
              << static_cast<int>(std::numeric_limits<signed char>::max()) << " > "
              << std::endl;

    std::cout << "short int \t\t : < "
              << std::numeric_limits<short int>::min() << ", "
              << std::numeric_limits<short int>::max() << " > " << std::endl;

    std::cout << "unsigned short int \t : < "
              << std::numeric_limits<unsigned short int>::min() << ", "
              << std::numeric_limits<unsigned short int>::max() << " > " << std::endl;

    std::cout << "int \t\t : < "
              << std::numeric_limits<int>::min() << ", "
              << std::numeric_limits<int>::max() << " > " << std::endl;

    std::cout << "unsigned int \t : < "
              << std::numeric_limits<unsigned int>::min() << ", "
              << std::numeric_limits<unsigned int>::max() << " > " << std::endl;

    std::cout << "long int \t\t : < "
              << std::numeric_limits<long int>::min() << ", "
              << std::numeric_limits<long int>::max() << " > " << std::endl;

    std::cout << "unsigned long int \t : < "
              << std::numeric_limits<unsigned long int>::min() << ", "
              << std::numeric_limits<unsigned long int>::max() << " > " << std::endl;

    std::cout << "long long int \t : < "
              << std::numeric_limits<long long int>::min() << ", "
              << std::numeric_limits<long long int>::max() << " > " << std::endl;

    std::cout << "unsigned long long int : < "
              << std::numeric_limits<unsigned long long int>::min() << ", "
              << std::numeric_limits<unsigned long long int>::max() << " > " << std::endl;
}

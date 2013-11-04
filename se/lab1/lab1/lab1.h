#ifndef LAB1_H
#define LAB1_H

#include <cmath>

const double PHI = (1+sqrt(5))/2;

double mean(const double &val1, const double &val2);

double min(const double &val1, const double &val2);

double max(const double &val1, const double &val2);

double factorial(const unsigned short &n);

double combinations(const unsigned short &n, const unsigned short &k);

double combinations_rep(const unsigned short &n, const unsigned short &k);

double permutations(const unsigned short &n, const unsigned short &k);

void fibonacci_print(const unsigned short &n);

int golden_ratio(const double &eps);

void pascalTriangle(const unsigned short &n);

void stringSample();

#endif // LAB1_H

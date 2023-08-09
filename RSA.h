#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

#ifndef RSA_H
#define RSA_H

bool isPrime(unsigned long long n);
unsigned long long getPrime(unsigned long long min, unsigned long long max);
unsigned long long gcd(unsigned long long x, unsigned long long y);
unsigned long long lcm(unsigned long long x, unsigned long long y);
unsigned long long modInverse(unsigned long long e, unsigned long long lam);
unsigned long long modExp(unsigned long long base, unsigned long long exp,unsigned long long n);
unsigned long long brute(unsigned long long c, unsigned long long e, unsigned long long n);

#endif //RSA_H


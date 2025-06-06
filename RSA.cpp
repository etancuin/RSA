#include "RSA.h"
using namespace std;

bool isPrime(unsigned long long n) {
  for (size_t i = 2; i <= sqrt(n); ++i)
  {
    if (n % i == 0) 
      return false;
  }
  return true;
}

unsigned long long getPrime(unsigned long long min, unsigned long long max) {
  unsigned long long n;
  do
  {
    n = rand() % (max + 1 - min) + min;
  } while (isPrime(n) == false);
  return n;
}

unsigned long long gcd(unsigned long long x, unsigned long long y) {
  unsigned long long r;
  while (y != 0)
  {
    r = y;
    y = x % y;
    x = r;
  }
  return x;
}

unsigned long long lcm(unsigned long long x, unsigned long long y) {
  return (x * y) / gcd(x, y);
}

unsigned long long modInverse(unsigned long long e, unsigned long long lam)
{
  for(size_t i = 1; i < lam; ++i)
  {
    if((i * e) % lam == 1) 
      return i;
  }
  return 0;
}

unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long n)
{
  unsigned long long x = 1;
  for(unsigned long long i = 0; i < exp; ++i) 
    x = (x * base) % n;
  return x;
}

unsigned long long brute(unsigned long long c, unsigned long long e, unsigned long long n)
{
  unsigned long long p = floor(sqrt(n));
  while(p >= 2)
  {
    if(isPrime(p) && n % p == 0)
      break;
    --p;
  }
  unsigned long long q = n / p;
  unsigned long long lambda = lcm((p - 1), (q - 1));
  unsigned long long d = modInverse(e, lambda);
  if(d != 0)
  {
    return modExp(c, d, n); 
  }
  return 0;
}

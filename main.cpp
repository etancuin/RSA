#include "RSA.h"
using namespace std;

int main() {
  unsigned long long p, q, n, lambda, d, e, m, c;
  unsigned int seed;

  cout << "Enter a seed: ";
  cin >> seed;
  srand(seed);

  p = getPrime(UCHAR_MAX, USHRT_MAX);
  cout << "p: " << p << endl;

  q = getPrime(UCHAR_MAX, USHRT_MAX);
  cout << "q: " << q << endl;

  n = p * q;
  cout << "n: " << n << endl;
  
  lambda = lcm(p - 1, q - 1);
  cout << "lambda: " << lambda << endl;
  
  do
    {
      e = getPrime(2, lambda - 1);
    } while(lambda % e == 0);
  cout << "e: " << e << endl;

  d = modInverse(e, lambda);
  cout << "d: " << d << endl;
  
  cout << "Public key: n = " << n << " e = " << e << endl << "Private key: n = " << n << " d = " << d << endl;

  cout << "Enter a positive number less than " << n << ": ";
  cin >> m;

  c = modExp(m, e, n);
  cout << "Cipher: " << c << endl;

  cout << "Decrypted cipher: " << modExp(c, d, n) << endl;

  return 1;
}

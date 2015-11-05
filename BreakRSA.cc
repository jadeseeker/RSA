// Grad student portion of the RSA assignment
// Fall 2015 ECE6122

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "RSA_Algorithm.h"

using namespace std;

void breakKey(mpz_class& p, mpz_class& q, mpz_class& n, mpz_class& d, mpz_class& e, int sz)
{
  //mpz_class temp;
  mpz_class phi = (p - 1) * (q - 1);
  
  mpz_invert(d.get_mpz_t(), e.get_mpz_t(), phi.get_mpz_t());

}

void enCipher(mpz_class& output, mpz_class& input, mpz_class& key, mpz_class& n)
{
  
  mpz_powm(output.get_mpz_t(), input.get_mpz_t(), key.get_mpz_t(), n.get_mpz_t());
}


int main(int argc, char** argv)
{ 


  RSA_Algorithm rsa;

  mpz_class d,q,m;

  mpz_class n(atol(argv[1]));
  
  mpz_class e(atol(argv[2]));

  //cout << ' calling';
  //cout << n;
  //cout << '\n' << e;

  mpz_class sqn = sqrt(n);
  mpz_class p;

  //cout << '\n' << sqn << '\n' << p;
  
  while (sqn > 1)
    {
      if (n % sqn == 0){
        p = sqn;
        break;
      }
      sqn -= 1;
    }

  q = n/p;

  breakKey(p, q, n, d, e, 32);

  mpz_class c(argv[3]);

  
  rsa.n = n;
  rsa.e = e;
  rsa.d = d;
  rsa.PrintNDE();

  cout << 'M ';
  for (int i = 3; i < 13; ++i)
    { 

      mpz_class c(argv[i]);
      enCipher(m, c, d, n);
      //  use the get_ui() method in mpz_class to get the lower 48 bits of the m
      unsigned long ul = m.get_ui();

      while(ul > 0){
        int ch;
        ch = ul % 100;
        ul = ul / 100;

        cout << char(ch);
      }
    }
  cout << endl;
}


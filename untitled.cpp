// Grad student portion of the RSA assignment
// Fall 2015 ECE6122

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "RSA_Algorithm.h"

using namespace std;
gmp_randclass rng(gmp_randinit_default);  



void breakKey(mpz_class& p, mpz_class& q, mpz_class& n, mpz_class& d, mpz_class& e, int sz)
{
  mpz_class temp;
  mpz_class phi = (p - 1) * (q - 1);
  
  mpz_invert(d.get_mpz_t(), e.get_mpz_t(), phi.get_mpz_t());

  }



void enCipher(mpz_class& output, mpz_class& input, mpz_class& key, mpz_class& n)
{
  
  mpz_powm(output.get_mpz_t(), input.get_mpz_t(), key.get_mpz_t(), n.get_mpz_t());
}


int main(int argc, char** argv)
{ 

  //argv[3] = first 6 characters of encrypted message
  //argv[4] = next 6 characters .. up to argv[12] are the lsat 6 characters

  RSA_Algorithm rsa;
  //rho = 1;

  mpz_class d,e,q,m,c, sqn;

  //n = mpz_class(argv[1]);

  mpz_class n(atol(argv[1]));
  //mpz_class p(1);
  
  e = atol(argv[2]);
  
  //c = mpz_class(argv[3]);

  cout << ' calling';

  mpz_class p = 2;
  mpz_class temp1, temp2;

  for(mpz_class s = 1; s < n; s++)
    {
      step = s;
      mpz_powm(temp1.get_mpz_t(), p.get_mpz_t(), s.get_mpz_t(), n.get_mpz_t());
      p = temp1;
      temp2 = p - 1;
      mpz_gcd(q.get_mpz_t(), n.get_mpz_t(), temp2.get_mpz_t());
      if(1 < q && q < n)
      {
        break;
      }
    }

  cout << p;
/*
  breakKey(p, q, n, d, e, 32);

  cout << 'd :' << d << endl;

  //enCipher(m, c, e, n);

  //rsa.PrintM();
  
  rsa.n = n;
  rsa.e = e;
  rsa.d = d;

  rsa.PrintNDE();

  // Set rsa.d to the calculated private key d
  // rsa.d = mpz_class(// broken d value here) 

  /*
  for (int i = 3; i < 13; ++i)
    { // Decrypt each set of 6 characters
      //char* buff;
      mpz_class c(argv[i]);
      enCipher(m, c, e, n);
      //  use the get_ui() method in mpz_class to get the lower 48 bits of the m
      unsigned long ul = m.get_ui();
      // Now print the 6 ascii values in variable ul.  As stated above the 6 characters
      // are in the low order 48 bits of ui.
      cout << ul << endl;
      //sprintf(buff,'%ld',ul);
      //printf('%s',buff);
    }*/
  cout << endl;
}


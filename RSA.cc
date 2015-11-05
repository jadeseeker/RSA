// ECE4122/6122 RSA Encryption/Decryption assignment
//Author: Yash Shah
// Fall Semester 2015

#include <iostream>
#include "RSA_Algorithm.h"

using namespace std;
gmp_randclass rng(gmp_randinit_default); 


void computeD(mpz_class& d, mpz_class& phi, int sz)
{
  while(true)
  {
    d = rng.get_z_bits(sz);
    mpz_class gcd;
    mpz_gcd(gcd.get_mpz_t(), d.get_mpz_t(), phi.get_mpz_t());
    if(d < phi && gcd == 1)
    {
      break;
    }
  }
}

void generateKey(mpz_class& p, mpz_class& q, mpz_class& n, mpz_class& d, mpz_class& e, int sz)
{

  n = p * q;
  mpz_class phi = (p - 1) * (q - 1);
  computeD(d, phi, sz * 2); 
  mpz_invert(e.get_mpz_t(), d.get_mpz_t(), phi.get_mpz_t());
}

void generatePrime(mpz_class& p, int sz, unsigned long reps)
{
  while(true)
  {
    p = rng.get_z_bits(sz);
    if(mpz_probab_prime_p(p.get_mpz_t(), reps) == 1)
    {
      return;
    }
  }
} 

void enCipher(mpz_class& output, mpz_class& input, mpz_class& key, mpz_class& n)
{
  // c = (m ^ k)mod(n)
  mpz_powm(output.get_mpz_t(), input.get_mpz_t(), key.get_mpz_t(), n.get_mpz_t());
}

int main()
{

  RSA_Algorithm rsa;



  for (int sz = 32; sz <= 1024; sz = sz * 2)
  {
  //int sz=32;
  //mpz_class p,q,n[10],d[10],e[10];
    for( int i = 0; i<10; i++)
    {

      mpz_class p,q,n,d,e;

      generatePrime(p, sz, 100);
      generatePrime(q, sz, 100);
      generateKey(p,q,n,d,e,sz);
      
      rsa.n = n;
      rsa.d = d;
      rsa.e = e;
      rsa.PrintNDE();
      //cout << i << '\t' << sz << endl;


      for(int j=0; j<1;j++)
      {
        
        mpz_class m = rng.get_z_bits(sz);
        mpz_class c,mp;

        enCipher(c,m,e,n);
        enCipher(mp,c,d,n);

        /*if(mp == m){
          cout<< 'success ' << endl;
        }*/

        
        rsa.PrintM(m);
        rsa.PrintC(c);
        //rsa.PrintM(mp);

  
      }
    }
  }
}
  

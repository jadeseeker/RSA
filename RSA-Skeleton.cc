// ECE4122/6122 RSA Encryption/Decryption assignment
// Fall Semester 2015

#include <iostream>
#include "RSA_Algorithm.h"

using namespace std;

int main()
{
  // Instantiate the one and only RSA_Algorithm object
  RSA_Algorithm rsa;
  gmp_randclass rng(gmp_randinit_default); 

  //rsa.rng = rng;
  
  // Loop from sz = 32 to 1024 inclusive

  for(int sz = 32; sz<=1024; sz*=2)
  {
    for( int i=0; i<1; i++)
    {
      rsa.GenerateRandomKeyPair(size_t(sz));
      rsa.PrintNDE();
    }
  }
  // for each size choose 10 different key pairs
  // For each key pair choose 10 differnt plaintext 
  // messages making sure it is smaller than n.
  // If not smaller then n then choose another
  // For eacm message encrypt it using the public key (n,e).
  // After encryption, decrypt the ciphertext using the private
  // key (n,d) and verify it matches the original message.

  // your code here
}
  

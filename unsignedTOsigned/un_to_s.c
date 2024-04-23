#include <stdio.h>


#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int main(int argc, char const *argv[])
{
   int A = 128;
   char B = 0;
   printf("%x %x\n", A, B);

   B = A;
   printf("%x %x\n", A, B);

   B++;
   B++;
   B++;
   B++;
   B++;
   A++; 
   A++;
   B = 0;
   B--;
   B--;
   B--;
   printf("%x %x\n", A, B);
   B--;
   printf("%x %x\n", A, B);
   B--;
   printf("%x %x\n", A, B);
   A = B;
   printf("%x %x\n", A, B);
   return 0;
}

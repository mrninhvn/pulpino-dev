#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "ghash.h"

void print(char* c, size_t len){
 for(int i = 0; i < 16; ++i){
    printf("%02X", c[i] & 0xff);
  }
  printf("\n");
}

#ifdef BR_MUL32
#define GHASH_MUL br_ghash_ctmul32
#elif BR_MUL64
#define GHASH_MUL br_ghash_ctmul64
#else
#define GHASH_MUL br_ghash_ctmul
#endif

int main(){
  // test case 2
  char h[16] = {0x66, 0xe9, 0x4b, 0xd4, 0xef, 0x8a, 0x2c, 0x3b, 
		0x88, 0x4c, 0xfa, 0x59, 0xca, 0x34, 0x2b, 0x2e};
  char c[32] = {// ciphertext
		0x03, 0x88, 0xda, 0xce, 0x60, 0xb6, 0xa3, 0x92,
		0xf3, 0x28, 0xc2, 0xb9, 0x71, 0xb2, 0xfe, 0x78,
		// len(A) || len(C)
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80};
  char y[16] = {};
  GHASH_MUL(&y, &h, &c, 32);
  // expected: f38cbb1ad69223dcc3457ae5b6b0f885
  printf("Test Case #2\n");
  printf("Expected: f38cbb1ad69223dcc3457ae5b6b0f885\n");
  printf("Real:     ");
  print(y, 16);
  // test case 3
  char h3[16] = { 0xb8, 0x3b, 0x53, 0x37, 0x08, 0xbf, 0x53, 0x5d,
		  0x0a, 0xa6, 0xe5, 0x29, 0x80, 0xd5, 0x3b, 0x78 };
  char c3[16*5] = {
		   // ciphertext
		   0x42, 0x83, 0x1e, 0xc2, 0x21, 0x77, 0x74, 0x24,
		   0x4b, 0x72, 0x21, 0xb7, 0x84, 0xd0, 0xd4, 0x9c,
		   0xe3, 0xaa, 0x21, 0x2f, 0x2c, 0x02, 0xa4, 0xe0,
		   0x35, 0xc1, 0x7e, 0x23, 0x29, 0xac, 0xa1, 0x2e,
		   0x21, 0xd5, 0x14, 0xb2, 0x54, 0x66, 0x93, 0x1c,
		   0x7d, 0x8f, 0x6a, 0x5a, 0xac, 0x84, 0xaa, 0x05,
		   0x1b, 0xa3, 0x0b, 0x39, 0x6a, 0x0a, 0xac, 0x97,
		   0x3d, 0x58, 0xe0, 0x91, 0x47, 0x3f, 0x59, 0x85,
		   // len(A) || len(C)
		   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
  char y3[16] = {};
  printf("Test Case #3:\n");
  printf("Expected: 7f1b32b81b820d02614f8895ac1d4eac\n");
  GHASH_MUL(&y3, &h3, &c3, 16*5);
  printf("Real:     ");
  print(y3,16);

  printf("Test Case #4:\n");
  printf("Expected: 698e57f70e6ecc7fd9463b7260a9ae5f\n");
  printf("Real:     ");
  char c4[7*16] = {
	     // A
	     0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef,
	     0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef,
	     0xab, 0xad, 0xda, 0xd2,
	     // padding zeros,
	     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	     0x00, 0x00, 0x00, 0x00,
	     // ciphertext
	     0x42, 0x83, 0x1e, 0xc2, 0x21, 0x77, 0x74, 0x24,
	     0x4b, 0x72, 0x21, 0xb7, 0x84, 0xd0, 0xd4, 0x9c,
	     0xe3, 0xaa, 0x21, 0x2f, 0x2c, 0x02, 0xa4, 0xe0,
	     0x35, 0xc1, 0x7e, 0x23, 0x29, 0xac, 0xa1, 0x2e,
	     0x21, 0xd5, 0x14, 0xb2, 0x54, 0x66, 0x93, 0x1c,
	     0x7d, 0x8f, 0x6a, 0x5a, 0xac, 0x84, 0xaa, 0x05,
	     0x1b, 0xa3, 0x0b, 0x39, 0x6a, 0x0a, 0xac, 0x97,
	     0x3d, 0x58, 0xe0, 0x91,
	     // padding zeros
	     0x00, 0x00, 0x00, 0x00,
	     // len(A) & len(c)
	     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0,
	     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0};
  char h4[16] = {0xb8, 0x3b, 0x53, 0x37, 0x08, 0xbf, 0x53, 0x5d,
		 0x0a, 0xa6, 0xe5, 0x29, 0x80, 0xd5, 0x3b, 0x78};
  char y4[16] = {};
  GHASH_MUL(&y4, &h4, &c4, 7*16);
  print(y4,16);
  printf("\n");
  return 0;
}

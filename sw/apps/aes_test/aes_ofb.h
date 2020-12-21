
#ifndef AES_OFB_H
#define AES_OFB_H
//#define OFB_DATA_SIZE 64
#define OFB_DATA_SIZE 16
//#define OFB_KEY_SIZE 16
#define OFB_KEY_SIZE 24
/* unsigned char ofb_key[OFB_KEY_SIZE] = {0x3d, 0x05, 0xc3, 0x6b, 0x00, 0x43, 0xfe, 0x8b, 0x3b, 0x53, 0xbb, 0x8f, 0xbf, 0x90, 0xbd, 0xbe}; */
/* unsigned char ofb_plaintext[OFB_DATA_SIZE] = {0x67, 0x1c, 0x93, 0x4d, 0x9b, 0x53, 0x6a, 0xc9, 0x5a, 0x1f, 0xe7, 0xb2, 0x06, 0x5d, 0xf7, 0xf1, 0xb2, 0xf1, 0xa9, 0xea, 0xdb, 0x94, 0x66, 0x0d, 0xf0, 0x86, 0x62, 0x42, 0x5e, 0xea, 0x01, 0x95, 0xcb, 0x94, 0x8d, 0xf2, 0xb2, 0x63, 0x86, 0x70, 0x28, 0x2c, 0x60, 0x3e, 0x01, 0xf2, 0x8f, 0xa3, 0x8e, 0x8a, 0x7d, 0xcc, 0xfc, 0xa6, 0xcc, 0x62, 0x3a, 0x48, 0x8a, 0xa8, 0x28, 0x92, 0x10, 0xd2}; */
/* unsigned char ofb_iv[OFB_KEY_SIZE] = {0x42, 0xb6, 0x9d, 0x7e, 0x45, 0x0f, 0xf0, 0xec, 0x75, 0x5a, 0x88, 0x51, 0x52, 0xa0, 0x2e, 0x5c}; */
/* unsigned char ofb_ciphertext[OFB_DATA_SIZE] = {0x77, 0x4a, 0x61, 0x5f, 0xe0, 0xc5, 0x2b, 0x64, 0xed, 0xbe, 0xba, 0x5e, 0x49, 0xee, 0x20, 0xc9, 0xe1, 0x27, 0xff, 0xa8, 0xab, 0x54, 0x88, 0x55, 0x51, 0xa1, 0x5b, 0xf7, 0xa7, 0x3f, 0x1a, 0x4b, 0x92, 0x54, 0xa4, 0xba, 0x04, 0xab, 0xf9, 0x6e, 0xaf, 0x26, 0x76, 0x3b, 0x49, 0x11, 0xb8, 0x1f, 0x18, 0x15, 0xaf, 0x64, 0x44, 0x9f, 0xa0, 0x58, 0x18, 0x89, 0x77, 0x01, 0x33, 0xfc, 0x9e, 0x5c}; */

unsigned char ofb_key[OFB_KEY_SIZE] = {0x8e, 0x73, 0xb0, 0xf7,
				       0xda, 0x0e, 0x64, 0x52,
				       0xc8, 0x10, 0xf3, 0x2b,
				       0x80, 0x90, 0x79, 0xe5,
				       0x62, 0xf8, 0xea, 0xd2,
				       0x52, 0x2c, 0x6b, 0x7b};

unsigned char ofb_plaintext[OFB_DATA_SIZE] = {0x6b, 0xc1, 0xbe, 0xe2,
					      0x2e, 0x40, 0x9f, 0x96,
					      0xe9, 0x3d, 0x7e, 0x11,
					      0x73, 0x93, 0x17, 0x2a};

unsigned char ofb_iv[16] = {0x00, 0x01, 0x02, 0x03,
			    0x04, 0x05, 0x06, 0x07,
			    0x08, 0x09, 0x0a, 0x0b,
			    0x0c, 0x0d, 0x0e, 0x0f};

unsigned char ofb_ciphertext[OFB_DATA_SIZE] = {0xcd, 0xc8, 0x0d, 0x6f,
					       0xdd, 0xf1, 0x8c, 0xab,
					       0x34, 0xc2, 0x59, 0x09,
					       0xc9, 0x9a, 0x41, 0x74};
  
#endif
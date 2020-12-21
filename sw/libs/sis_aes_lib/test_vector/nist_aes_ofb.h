#ifndef NIST_AES_OFB_H
#define NIST_AES_OFB_H

int OFB_KEY_SIZE[3]    = {16, 24, 32};
int OFB_PLAIN_SIZE[3]  = {64, 64, 64};
int OFB_IV_SIZE[3]     = {16, 16, 16};
int OFB_CIPHER_SIZE[3] = {64, 64, 64};

unsigned char ofb_key_128[16] = {0x2b, 0x7e, 0x15, 0x16,
				 0x28, 0xae, 0xd2, 0xa6,
				 0xab, 0xf7, 0x15, 0x88,
				 0x09, 0xcf, 0x4f, 0x3c};

unsigned char ofb_key_192[24] = {0x8e, 0x73, 0xb0, 0xf7,
				 0xda, 0x0e, 0x64, 0x52,
				 0xc8, 0x10, 0xf3, 0x2b,
				 0x80, 0x90, 0x79, 0xe5,
				 0x62, 0xf8, 0xea, 0xd2,
				 0x52, 0x2c, 0x6b, 0x7b};

unsigned char ofb_key_256[32] = {0x60, 0x3d, 0xeb, 0x10,
				 0x15, 0xca, 0x71, 0xbe,
				 0x2b, 0x73, 0xae, 0xf0,
				 0x85, 0x7d, 0x77, 0x81,
				 0x1f, 0x35, 0x2c, 0x07,
				 0x3b, 0x61, 0x08, 0xd7,
				 0x2d, 0x98, 0x10, 0xa3,
				 0x09, 0x14, 0xdf, 0xf4};      

unsigned int ofb_key[3] = {(int) &ofb_key_128,
			   (int) &ofb_key_192,
			   (int) &ofb_key_256};

unsigned char ofb_iv_128[16] = {0x00, 0x01, 0x02, 0x03,
				0x04, 0x05, 0x06, 0x07,
				0x08, 0x09, 0x0a, 0x0b,
				0x0c, 0x0d, 0x0e, 0x0f};

unsigned char ofb_iv_192[16] = {0x00, 0x01, 0x02, 0x03,
				0x04, 0x05, 0x06, 0x07,
				0x08, 0x09, 0x0a, 0x0b,
				0x0c, 0x0d, 0x0e, 0x0f};

unsigned char ofb_iv_256[16] = {0x00, 0x01, 0x02, 0x03,
				0x04, 0x05, 0x06, 0x07,
				0x08, 0x09, 0x0a, 0x0b,
				0x0c, 0x0d, 0x0e, 0x0f};

unsigned int ofb_iv[3] = {(int) &ofb_iv_128,
			  (int) &ofb_iv_192,
			  (int) &ofb_iv_256};

unsigned char ofb_plaintext_128[64] = {0x6b, 0xc1, 0xbe, 0xe2,
				       0x2e, 0x40, 0x9f, 0x96,
				       0xe9, 0x3d, 0x7e, 0x11,
				       0x73, 0x93, 0x17, 0x2a,
				       0xe2, 0xd8, 0xa5, 0x71,
				       0x9e, 0x03, 0xac, 0x9c,
				       0x9e, 0xb7, 0x6f, 0xac,
				       0x45, 0xaf, 0x8e, 0x51,
				       0x30, 0xc8, 0x1c, 0x46,
				       0xa3, 0x5c, 0xe4, 0x11,
				       0xe5, 0xfb, 0xc1, 0x19,
				       0x1a, 0x0a, 0x52, 0xef,
				       0xf6, 0x9f, 0x24, 0x45,
				       0xdf, 0x4f, 0x9b, 0x17,
				       0xad, 0x2b, 0x41, 0x7b,
				       0xe6, 0x6c, 0x37, 0x10};

unsigned char ofb_plaintext_192[64] = {0x6b, 0xc1, 0xbe, 0xe2,
				       0x2e, 0x40, 0x9f, 0x96,
				       0xe9, 0x3d, 0x7e, 0x11,
				       0x73, 0x93, 0x17, 0x2a,
				       0xae, 0x2d, 0x8a, 0x57,
				       0x1e, 0x03, 0xac, 0x9c,
				       0x9e, 0xb7, 0x6f, 0xac,
				       0x45, 0xaf, 0x8e, 0x51,
				       0x30, 0xc8, 0x1c, 0x46,
				       0xa3, 0x5c, 0xe4, 0x11,
				       0xe5, 0xfb, 0xc1, 0x19,
				       0x1a, 0x0a, 0x52, 0xef,
				       0xf6, 0x9f, 0x24, 0x45,
				       0xdf, 0x4f, 0x9b, 0x17,
				       0xad, 0x2b, 0x41, 0x7b,
				       0xe6, 0x6c, 0x37, 0x10};

unsigned char ofb_plaintext_256[64] = {0x6b, 0xc1, 0xbe, 0xe2,
				       0x2e, 0x40, 0x9f, 0x96,
				       0xe9, 0x3d, 0x7e, 0x11,
				       0x73, 0x93, 0x17, 0x2a,
				       0xae, 0x2d, 0x8a, 0x57,
				       0x1e, 0x03, 0xac, 0x9c,
				       0x9e, 0xb7, 0x6f, 0xac,
				       0x45, 0xaf, 0x8e, 0x51,
				       0x30, 0xc8, 0x1c, 0x46,
				       0xa3, 0x5c, 0xe4, 0x11,
				       0xe5, 0xfb, 0xc1, 0x19,
				       0x1a, 0x0a, 0x52, 0xef,
				       0xf6, 0x9f, 0x24, 0x45,
				       0xdf, 0x4f, 0x9b, 0x17,
				       0xad, 0x2b, 0x41, 0x7b,
				       0xe6, 0x6c, 0x37, 0x10};

unsigned int ofb_plaintext[3] = {(int) &ofb_plaintext_128,
				 (int) &ofb_plaintext_192,
				 (int) &ofb_plaintext_256};

unsigned char ofb_ciphertext_128[64] = {0x3b, 0x3f, 0xd9, 0x2e,
					0xb7, 0x2d, 0xad, 0x20,
					0x33, 0x34, 0x49, 0xf8,
					0xe8, 0x3c, 0xfb, 0x4a,
					0x77, 0x89, 0x50, 0x8d,
					0x16, 0x91, 0x8f, 0x03,
					0xf5, 0x3c, 0x52, 0xda,
					0xc5, 0x4e, 0xd8, 0x25,
					0x97, 0x40, 0x05, 0x1e,
					0x9c, 0x5f, 0xec, 0xf6,
					0x43, 0x44, 0xf7, 0xa8,
					0x22, 0x60, 0xed, 0xcc,
					0x30, 0x4c, 0x65, 0x28,
					0xf6, 0x59, 0xc7, 0x78,
					0x66, 0xa5, 0x10, 0xd9,
					0xc1, 0xd6, 0xae, 0x5e};

unsigned char ofb_ciphertext_192[64] = {0xcd, 0xc8, 0x0d, 0x6f,
					0xdd, 0xf1, 0x8c, 0xab,
					0x34, 0xc2, 0x59, 0x09,
					0xc9, 0x9a, 0x41, 0x74,
					0xfc, 0xc2, 0x8b, 0x8d,
					0x4c, 0x63, 0x83, 0x7c,
					0x09, 0xe8, 0x17, 0x00,
					0xc1, 0x10, 0x04, 0x01,
					0x8d, 0x9a, 0x9a, 0xea,
					0xc0, 0xf6, 0x59, 0x6f,
					0x55, 0x9c, 0x6d, 0x4d,
					0xaf, 0x59, 0xa5, 0xf2,
					0x6d, 0x9f, 0x20, 0x08,
					0x57, 0xca, 0x6c, 0x3e,
					0x9c, 0xac, 0x52, 0x4b,
					0xd9, 0xac, 0xc9, 0x2a};

unsigned char ofb_ciphertext_256[64] = {0xdc, 0x7e, 0x84, 0xbf,
					0xda, 0x79, 0x16, 0x4b,
					0x7e, 0xcd, 0x84, 0x86,
					0x98, 0x5d, 0x38, 0x60,
					0x4f, 0xeb, 0xdc, 0x67,
					0x40, 0xd2, 0x0b, 0x3a,
					0xc8, 0x8f, 0x6a, 0xd8,
					0x2a, 0x4f, 0xb0, 0x8d,
					0x71, 0xab, 0x47, 0xa0,
					0x86, 0xe8, 0x6e, 0xed,
					0xf3, 0x9d, 0x1c, 0x5b,
					0xba, 0x97, 0xc4, 0x08,
					0x01, 0x26, 0x14, 0x1d,
					0x67, 0xf3, 0x7b, 0xe8,
					0x53, 0x8f, 0x5a, 0x8b,
					0xe7, 0x40, 0xe4, 0x84};

unsigned int ofb_ciphertext[3] = {(int) &ofb_ciphertext_128,
				  (int) &ofb_ciphertext_192,
				  (int) &ofb_ciphertext_256};


#endif
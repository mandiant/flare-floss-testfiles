#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


// via: http://bradconte.com/rc4_c
// Key Scheduling Algorithm
// Input: state - the state used to generate the keystream
//        key - Key to use to initialize the state
//        len - length of key in bytes
__attribute__((always_inline))
static inline void ksa(unsigned char state[], const unsigned char key[], int len)
{
   int i,j=0,t;

   for (i=0; i < 256; ++i)
      state[i] = i;
   for (i=0; i < 256; ++i) {
      j = (j + state[i] + key[i % len]) % 256;
      t = state[i];
      state[i] = state[j];
      state[j] = t;
   }
}

// via: http://bradconte.com/rc4_
// Pseudo-Random Generator Algorithm
// Input: state - the state used to generate the keystream
//        out - Must be of at least "len" length
//        len - number of bytes to generate
__attribute__((always_inline))
static inline void prga(unsigned char state[], unsigned char out[], int len)
{
   int i=0,j=0,x,t;
   unsigned char key;

   for (x=0; x < len; ++x)  {
      i = (i + 1) % 256;
      j = (j + state[i]) % 256;
      t = state[i];
      state[i] = state[j];
      state[j] = t;
      out[x] = state[(state[i] + state[j]) % 256];
   }
}

struct OBFUSCATED_STRING {
    unsigned char key[0x4];
    unsigned int string_len;
    unsigned char string[0x100]; // variable size, use 0x100 to avoid warnings
};

char *decode(struct OBFUSCATED_STRING *in) {
    if (in == NULL) {
        return NULL;
    }
    unsigned char *out = malloc(in->string_len);
    if (out == NULL) {
        return NULL;
    }

    unsigned char state[0x100];
    ksa(state, in->key, 0x4);
    prga(state, out, in->string_len);
    for (unsigned int i = 0; i < in->string_len; i++) {
        ((unsigned char *)out)[i] ^= ((unsigned char *)&in->string)[i];
    }
    return (char *)out;
}

int main(int argc, char **argv) {
    // In [12]: a = ARC4.new(b"\x00\x01\x02\x03")
    // In [13]: a.encrypt(b"Hello world\x00").encode("hex")
    // Out[13]: '054596da5ae3b2242f9f0256'
    struct OBFUSCATED_STRING in = {
        {0x00, 0x01, 0x02, 0x03},
        12,
        {0x05, 0x45, 0x96, 0xda, 0x5a, 0xe3, 0xb2, 0x24, 0x2f, 0x9f, 0x02, 0x56},
    };

    char *out = decode(&in);
    if (out == NULL) {
        perror("failed to decode.\n");
        return -1;
    }

    printf("%s\n", out);
    return 0;
}

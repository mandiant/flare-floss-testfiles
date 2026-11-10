#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// "hello wide world" as UTF-16LE, each character xor 0x55.
// the decoder writes into zeroed memory, so the high byte of each character
// is zero before and after decoding: only every other byte changes.
uint16_t encoded[] = {
    'h' ^ 0x55, 'e' ^ 0x55, 'l' ^ 0x55, 'l' ^ 0x55, 'o' ^ 0x55, ' ' ^ 0x55,
    'w' ^ 0x55, 'i' ^ 0x55, 'd' ^ 0x55, 'e' ^ 0x55, ' ' ^ 0x55,
    'w' ^ 0x55, 'o' ^ 0x55, 'r' ^ 0x55, 'l' ^ 0x55, 'd' ^ 0x55,
};

int decode(uint16_t *out, const uint16_t *in, size_t len) {
    for (size_t i = 0; i < len; i++) {
        out[i] = in[i] ^ 0x55;
    }
    return 0;
}

int main(int argc, char **argv) {
    size_t len = sizeof(encoded) / sizeof(encoded[0]);
    uint16_t *out = calloc(len + 1, sizeof(uint16_t));
    if (!out) {
        perror("failed to allocate.\n");
        return -1;
    }

    if (decode(out, encoded, len)) {
        perror("failed to decode.\n");
        return -1;
    }
    for (size_t i = 0; i < len; i++) {
        putchar(out[i]);
    }
    putchar('\n');
    free(out);
    return 0;
}

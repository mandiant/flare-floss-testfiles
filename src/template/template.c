#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


int decode(void *out, size_t out_len, const void *in, size_t in_len) {
    memcpy(out, in, out_len);
    return 0;
}

char in[] = "hello world!";

int main(int argc, char **argv) {
    char out[sizeof(in) + 1];

    if (decode(out, sizeof(in) + 1, in, sizeof(in))) {
        perror("failed to decode.\n");
        return -1;
    }
    printf("%s\n", out);
    return 0;
}

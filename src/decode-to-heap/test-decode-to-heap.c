#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


char *decode(const void *in_buf, size_t in_len, unsigned char key) {
    char *out_buf = malloc(in_len);
    if (out_buf == NULL) {
        return NULL;
    }

    for (unsigned int i = 0; i < in_len; i++) {
        ((char *)out_buf)[i] = ((char *)in_buf)[i] ^ key;
    }
    if (in_len > 0) {
        ((char *)out_buf)[in_len - 1] = 0;
    }

    return out_buf;
}


int main(int argc, char **argv) {
    char in[] = "idmmn!vnsme";
    char *out = NULL;
    unsigned char key = 0x1;

    out = decode(in, sizeof(in), 0x1);
    if (out == NULL) {
        perror("failed to decode.\n");
        return -1;
    }
    printf("%s\n", out);
    return 0;
}

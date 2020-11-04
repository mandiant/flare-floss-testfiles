#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "base64.h"


char in[] = "aGVsbG8gd29ybGQ=";

int main(int argc, char **argv) {
    char out[sizeof(in) + 1];
    Base64decode(out, in);
    printf("%s\n", out);
    return 0;
}

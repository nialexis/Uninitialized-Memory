#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *a = malloc(64);
    strcpy(a, "password=hunter2_this_is_a_long_secret_value");
    free(a);

    char *b = malloc(64);  // likely the same chunk
    for (int i = 0; i < 64; i++)
        putchar(b[i] >= 32 && b[i] < 127 ? b[i] : '.');
    putchar('\n');
    printf("a=%p b=%p\n", (void*)a, (void*)b);
    free(b);
    return 0;
}
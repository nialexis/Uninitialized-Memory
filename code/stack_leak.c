#include <stdio.h>
#include <string.h>
#include <stdint.h>

static uintptr_t saved_addr;

__attribute__((noinline)) void write_secret(void) {
    char buf[64];
    strcpy(buf, "SECRET_PASSWORD_123");
    saved_addr = (uintptr_t)buf;
    (void)buf;
}

__attribute__((noinline)) void read_uninit(void) {
    char buf[64];  // never initialized
    printf("write_secret buf: %p\nread_uninit buf: %p\n",
       (void *)saved_addr, (void *)buf);
    for (int i = 0; i < 64; i++)
        putchar(buf[i] >= 32 && buf[i] < 127 ? buf[i] : '.');
    putchar('\n');
}

int main(void) {
    write_secret();
   read_uninit();
    return 0;
}
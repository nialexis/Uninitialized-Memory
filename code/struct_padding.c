#include <stdio.h>
#include <string.h>

struct S { char a; int b; };

__attribute__((noinline)) void dirty_stack(void) {
    unsigned char junk[128];
    memset(junk, 0xAA, sizeof junk);
    __asm__ volatile("" : : "r"(junk) : "memory");
}

__attribute__((noinline)) void show_struct(void) {
    struct S s1;              
    s1.a = 'X'; 
    s1.b = 42;
    unsigned char *p = (unsigned char *)&s1;
    printf("no memset: ");
    for (size_t i = 0; i < sizeof s1; i++) printf("%02x ", p[i]);
    printf("\n");

    struct S s2;
    memset(&s2, 0, sizeof s2); // padding zeroed
    s2.a = 'X'; 
    s2.b = 42;
    p = (unsigned char *)&s2;
    printf("memset   : ");
    for (size_t i = 0; i < sizeof s2; i++) printf("%02x ", p[i]);
    printf("\n");
}

int main(void) {
    dirty_stack();
    show_struct();
    return 0;
}
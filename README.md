# Uninitialized Memory in C

## Introduction
I explored what happens when a C program reads memory it never initialized, and why that is an issue. I created two demos (a stack leak and a struct padding leak) and compared their outputs. 

## Background Information
In C, local variables are not cleared when they are created. When a function returns, its stack frame is released but the bytes are not erased, so the function that gets that stack space can access that old data. Reading a variable before writing to it can cause undefined behavior.

## Experiment 1: Stack Leak
**write_secret()** copies "SECRET_PASSWORD123" into a local buffer and returns. 

**read_unit()** then declares its own 64-byte buffer without initializing it and prints every byte. Both functions are marked **noinline*** so the compiler keeps them as real function calls with their own stack frames.

After running the program, thhe program printed 
    SECRET_PASSWORD_123.....................p.<..... ..n............
The secret leaked along with other leftover bytes I never wrote.


## Experiement 2: Struct Padding
**struct S { char a; int b; }** needs 5 bytes of data but takes up 8, the compiler adds 3 bytes of padding after *a* so the *int* stays aligned. The padding is never written by my code. I filled the stack with **0xAA** bytes in **dirty_stack()**, then created the string in **show_struct()** and printed its byes, with and without **memset**.

**Final output:**

no memset: 58 00 9e 4a 2a 00 00 00

memset   : 58 00 00 00 2a 00 00 00

Bytes 1 to 3 are padding. Without **memset**, bytes 2 and 3 held 9e 4a,
values my code never wrote. With **memset**, the padding was all zeros. If a
program sent or saved this whole struct, those stray bytes would go with it.




## Most interesting discoveries

My first struct demo showed no leak. Moving the struct into its own
   function, after the function that dirtied the stack, made the leak appear.
   This showed me that leftover memory depends on where each function's
   stack frame lands.
   
   I expected to see aa bytes from **dirty_stack()** but did not. My guess is
that the struct overlapped a different part of the stack than the junk array.

## How to run

    gcc -Wall -Wextra -g -O0 code/stack_leak.c -o stack_leak_O0
    ./stack_leak_O0
    gcc -Wall -Wextra -g -O2 code/stack_leak.c -o stack_leak_O2
    ./stack_leak_O2

    gcc -Wall -Wextra -g -O0 code/struct_padding.c -o struct_padding_O0
    ./struct_padding_O0
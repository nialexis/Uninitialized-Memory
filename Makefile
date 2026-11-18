CFLAGS = -Wall -Wextra -g
all: stack_leak heap_reuse struct_padding
%: code/%.c
	gcc $(CFLAGS) -O0 $< -o $@_O0
	gcc $(CFLAGS) -O2 $< -o $@_O2
clean:
	rm -f *_O0 *_O2

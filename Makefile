all:
	gcc hello.c -o hello
	gcc -std=c99 pointer_main.c pointer_functions.c -o pointer

clean:
	rm -rf hello
	rm -rf pointer

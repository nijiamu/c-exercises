all:
	gcc -Wall hello.c -o hello
	gcc -std=c99 -Wall pointer_main.c pointer_functions.c -o pointer
	gcc -std=c99 -Wall str_main.c str_functions.c -o str

clean:
	rm -rf *.exe
	rm -rf *.stackdump

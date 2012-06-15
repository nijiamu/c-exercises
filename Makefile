all:
	gcc -Wall hello.c -o hello
	gcc -std=c99 -Wall pointer_main.c pointer_functions.c -o pointer
	gcc -std=c99 -Wall str_main.c str_functions.c -o str
	gcc -std=c99 -Wall vector_main.c vector.c -o vector

clean:
	rm -rf *.exe
	rm -rf *.stackdump

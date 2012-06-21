all:
	gcc -Wall hello.c -o hello
	gcc -std=c99 -pedantic -Wall -Wextra -g -o pointer pointer_main.c pointer_functions.c
	gcc -std=c99 -pedantic -Wall -Wextra -g -o str str_main.c str_functions.c
	gcc -std=c99 -pedantic -Wall -Wextra -g -o skeleton skeleton_main.c skeleton.c joint.c

clean:
	rm -rf *.exe
	rm -rf *.stackdump

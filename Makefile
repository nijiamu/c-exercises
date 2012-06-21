all:
	gcc -Wall hello.c -o hello
	gcc -std=c99 -pedantic -Wall -Wextra -g -o pointer pointer_main.c pointer_functions.c
	gcc -std=c99 -pedantic -Wall -Wextra -g -o str str_main.c str_functions.c
	gcc -std=c99 -pedantic -Wall -Wextra -g -o skeleton skeleton_main.c skeleton.c joint.c
	gcc -std=c99 -pedantic -Wall -Wextra -g -o bookings bookingstest.c bookings.c
	gcc -std=c99 -pedantic -Wall -Wextra -g -o transcript transcript_test.c transcript.c course.c

clean:
	rm -rf *.exe
	rm -rf *.stackdump

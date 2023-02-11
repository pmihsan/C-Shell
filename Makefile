run:
	gcc -Wall -Wextra -Werror -pedantic main.c -o shell -w 

compile:
	gcc -Wall -Wextra -Werror -pedantic main.c execmd.c -o shell -w

ishell:
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell -w 

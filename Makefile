build:	
	mkdir -p bin
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 src/*.c -o bin/shell -w 

run:
	gcc -Wall -Wextra -Werror -pedantic src/main.c -o shell -w 

test:
	gcc -Wall -Wextra -Werror -pedantic src/main.c src/execmd.c -o shell -w

ishell:
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 src/*.c -o shell -w 

compile:
	mkdir -p test
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 src/*.c -o test/shell -w 

clean:
	rm -rf bin test

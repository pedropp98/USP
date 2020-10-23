objects = list.o pepelib.o main.o 
flags = -Wall -Wextra -Wpedantic -O3 -Wunused-result

all : $(objects)
	gcc -o main $(objects) $(flags)

compile:
	gcc -g *.c -o main $(flags)

pepelib.o: pepelib.h

list.o : list.h

main.o : list.h pepelib.h

run : 
	./main

tio_val:
	valgrind --leak-check=full --track-origins=yes ./main
	
clean :
	rm *.o main
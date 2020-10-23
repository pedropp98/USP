objects = fila.o pepelib.o main.o 
flags = -Wall -Wextra -Wpedantic -O3 -Wunused-result

all : $(objects)
	gcc -o main $(objects) 

compile:
	gcc -g *.c -o main $(flags)

pepelib.o: pepelib.h

fila.o : fila.h

main.o : fila.h pepelib.h

run : 
	./main

tio_val:
	valgrind --leak-check=full --track-origins=yes ./main
	
clean :
	rm *.o main
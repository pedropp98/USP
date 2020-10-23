objects = cartas.o main.o

all : $(objects)
	gcc -o main $(objects)

compile:
	gcc -g *.c -o main

cartas.o : cartas.h

main.o : cartas.h

run : 
	./main
tio_val:
	valgrind --leak-check=full --track-origins=yes ./main
clean :
	rm *.o main
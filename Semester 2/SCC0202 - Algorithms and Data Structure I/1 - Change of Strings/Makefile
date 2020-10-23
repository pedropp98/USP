objects = pepelib.o sub.o

all : $(objects)
	gcc -o sub $(objects)

compile:
	gcc -g *.c -o sub

pepelib.o : pepelib.h
sub.o : pepelib.h
run : 
	./sub
tio_val:
	valgrind --leak-check=full --track-origins=yes ./sub
clean :
	rm *.o sub
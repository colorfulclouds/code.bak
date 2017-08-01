main : main.o server.o
	gcc -o main main.o server.o
main.o : main.c head.h server.h const_value.h
	gcc -c main.c
server.o : server.c server.h
	gcc -c server.c
clean:
	rm *.o

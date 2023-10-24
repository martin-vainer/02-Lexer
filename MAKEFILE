all: main.exe test

test: mainTest
	mainTest

main.exe: main.o reconocedor_automata.o 
	gcc main.o reconocedor_automata.o  -o main.exe

main.o: main.c reconocedor.h
	gcc -c main.c -o main.o

reconocedor_automata.o: reconocedor_automata.c reconocedor.h
	gcc -c reconocedor_automata.c -o reconocedor_automata.o

mainTest: Test.o reconocedor_automata.o 
	gcc Test.o reconocedor_automata.o -o mainTest

Test.o: Test.c reconocedor.h
	gcc -c Test.c -o Test.o
# reconocedor_control.o: reconocedor_control.c reconocedor.h
# 	gcc -c reconocedor_control.c -o reconocedor_control.o
clean:
	rm -f main.o reconocedor_automata.o main.exe Test.o test.exe mainTest.exe salida.txt

# /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
# CC = gcc
# CFLAGS = -Wall -g

# all: main test

# main: main.c reconocedor.c
#     $(CC) $(CFLAGS) -o main main.c reconocedor.c

# test: test.c reconocedor.c
#     $(CC) $(CFLAGS) -o test test.c reconocedor.c

# clean:
#     rm -f main test



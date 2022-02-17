
CC = g++
CFLAGS = -I.
OUTPUT = statSem
CLEANCOMM = rm -f

%.o: %.cpp
	$(CC) -std=c++11 -c -o $@ $< $(CFLAGS)

$(OUTPUT): main.o parser.o scanner.o
	$(CC) -std=c++11 -Wall -g -o $(OUTPUT) main.o parser.o scanner.o
	make clean

clean:
	$(CLEANCOMM) *.o

outclean:
	$(CLEANCOMM) $(OUTPUT) *.o

run:
	$(OUTPUT) input.fs

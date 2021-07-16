# Going to make a make file
#

LIBS= -lraylib -lm -lGL -lpthread -ldl -lrt 
all: compile main.o mb.o c.o
	g++ main.o mb.o c.o -o output -L ./lib/ $(LIBS) 
	@rm *.o
compile: ./src/main.cpp
	g++ -c include/MandelBrot.c -o mb.o 
	g++ -c include/Complex.c -o c.o
	g++ -c ./src/main.cpp -Wall -g -Wpedantic

clean:
	rm *.o output

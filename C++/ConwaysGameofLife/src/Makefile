CFLAGS = -Wall -g 

CC = g++

LIBS =  -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

VER = -std=c++11
default:
	$(CC) -c main.cpp 
	$(CC) main.o $(VER) $(CFLAGS) $(LIBS) -o ../bin/output
	$(RM) main.o 

ext: 
	$(CC) CGL.cpp  $(LIBS)  -o ../bin/CGL

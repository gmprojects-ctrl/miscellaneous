all: MandelBrot.c
	clang -Wall -Wpedantic -lm MandelBrot.c Complex.c -o MandelBrot
	./MandelBrot
	convert image*.ppm image.png
	rm MandelBrot image*.ppm

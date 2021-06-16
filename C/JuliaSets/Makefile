all: Julia.c
	clang -Wall -Wpedantic -lm Julia.c Complex.c -o Julia
	./Julia
	convert image*.ppm image.png
	rm Julia image*.ppm

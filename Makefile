CC =g++
CFLAGS=-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
LIBS=/usr/local/lib/libglfw.3.dylib

default: main

%.o: src/%.cpp
	$(CC) -c  $<

main: draw.o food.o mathCompare.o snake.o snakePart.o
	$(CC) -Wall -o main src/main.cpp draw.o food.o mathCompare.o snake.o snakePart.o $(LIBS) $(CFLAGS)


clean:
	rm -f *.o 
	rm main

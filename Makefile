all: main.c
	gcc -g main.c -o main -I/opt/homebrew/Cellar/raylib/5.5/include -L/opt/homebrew/Cellar/raylib/5.5/lib -lraylib -lm

clean: main.c
	rm -f main

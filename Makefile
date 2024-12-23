all:
	gcc -o src/prog.exe src/main.c src/arbre.c src/minimax.c  -I include -L lib -lmingw32 -lSDL2main -lSDL2


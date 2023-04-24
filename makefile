prog:main.o ennemie.o
	gcc main.o  ennemie.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c 
	gcc -c main.c -g
ennemie.o:ennemie.c
	gcc -c ennemie.c -g
 

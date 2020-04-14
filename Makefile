all: build run clean
build: lab5z1v4.c lab5z2v4.c MainFile.c MyLib.c
	gcc -Wall -O0 -g3 -DDEBUG -pedantic-errors -std=c89 lab5z1v4.c lab5z2v4.c MainFile.c MyLib.c -o programm
	
run: programm.exe
	./programm.exe
	
clean: 
	rm -rf *.o programm	

all: dirInfo.c
	gcc -o dirInfo dirInfo.c 

clean:
	rm *.o
	rm *~

run: all
	./dirInfo

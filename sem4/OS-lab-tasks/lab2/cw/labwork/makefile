outputfile: main.o function.o
	gcc main.c function.c -o outputfile
main.o: main.c
	gcc -c main.c
function.o: function.c
	gcc -c function.c
clean:
	rm -f *.o outputfile
run: outputfile
	./outputfile 

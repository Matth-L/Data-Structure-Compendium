all :
	mkdir -p bin
	make test

test : 
	g++ -Wall -Wextra -I include/ -c src/Dictionnaire.cpp -o bin/Dictionnaire.o
	g++ -Wall -Wextra -I include/ -c src/main.cpp -o bin/main.o
	g++ bin/Dictionnaire.o bin/main.o -o test 

clean : 
	rm -f bin/*.o test
	rm -rf bin
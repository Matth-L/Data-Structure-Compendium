all :
	mkdir -p bin
	make factory

factory : 
	g++ -Wall -Wextra -I include/ -c src/Piece.cpp -o bin/Piece.o
	g++ -Wall -Wextra -I include/ -c src/Machine.cpp -o bin/Machine.o
	g++ -Wall -Wextra -I include/ -c src/Main.cpp -o bin/Main.o
	g++ bin/Piece.o bin/Machine.o bin/Main.o -o factory


clean : 
	rm -f bin/*.o factory
	rm -rf bin
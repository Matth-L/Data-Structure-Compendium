all :
	mkdir -p bin
	make war_game 
	make test

war_game : 
	g++ -Wall -Wextra -I include/ -c src/Card.cxx -o bin/Card.o
	g++ -Wall -Wextra -I include/ -c src/Player.cxx -o bin/Player.o
	g++ -Wall -Wextra -I include/ -c src/main.cxx -o bin/main.o
	g++ bin/Card.o bin/Player.o bin/main.o -o war_game 

clean : 
	rm -f bin/*.o war_game
	rm -rf bin
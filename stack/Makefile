all :
	mkdir -p bin
	make war_game 
	make test_pile

war_game : 
	g++ -Wall -Wextra -I include/ -c src/Card.cxx -o bin/Card.o
	g++ -Wall -Wextra -I include/ -c src/Player.cxx -o bin/Player.o
	g++ -Wall -Wextra -I include/ -c src/Main.cxx -o bin/Main.o
	g++ bin/Card.o bin/Player.o bin/Main.o -o war_game 

test_pile:
	cxxtestgen --error-printer -o test/test_pile.cxx test/Piletest.hxx
	g++ -I include/ -o test_pile test/test_pile.cxx

clean : 
	rm -f bin/*.o war_game
	rm -rf bin
	rm -f test/test_pile.cxx test_pile
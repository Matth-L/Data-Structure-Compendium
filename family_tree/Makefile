all : 
	mkdir -p bin 
	g++ -Wall -Wextra -I include/ -c src/Person.cpp -o bin/Person.o
	g++ -Wall -Wextra -I include/ -c src/Main.cpp -o bin/Main.o
	g++ bin/Person.o bin/Main.o -o ./arbre


test_f:
	mkdir -p bin 
	g++ -Wall -Wextra -I include/ -c src/Person.cpp -o bin/Person.o
	cxxtestgen --error-printer -o test/test_family_tree.cpp test/FamilyTreeTest.hpp
	g++ -I include/ -o test_family_tree test/test_family_tree.cpp bin/Person.o
	./test_family_tree
	make clean

clean :
	rm -rvf bin	
	rm -vf test_family_tree
	rm -vf arbre
	rm -vf ./test/test_family_tree.cpp

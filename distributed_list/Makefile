all:
	mkdir -p bin
	g++ -Wall -Wextra -I include/ -c src/main.cpp -o bin/main.o
	g++ bin/main.o -o distributed_list

clean:
	rm -rf bin distributed_list

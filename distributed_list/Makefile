all:
	mkdir -p bin
	make  distributed_list

distributed_list:
	g++ -Wall -Wextra -I include/ -fopenmp -c src/main.cpp -o bin/main.o
	g++ bin/main.o -o distributed_list -fopenmp 

clean:
	rm -f bin/*.o distributed_list
	rm -rf bin
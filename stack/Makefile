CXX = g++
CXXFLAGS = -Wall -Wextra -g
SRCDIR = src
BINDIR = bin

SRC = $(SRCDIR)/main.cxx
OBJ = $(BINDIR)/main.o
EXEC = war_game

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ)

$(BINDIR)/main.o: $(SRCDIR)/main.cxx
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.cxx -o $(BINDIR)/main.o

clean:
	rm -f $(BINDIR)/*.o $(EXEC)

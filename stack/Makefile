CXX = g++
CXXFLAGS = -Wall -Wextra  -g
SRCDIR = src
BINDIR = bin
SRC = $(SRCDIR)/main.cxx
OBJ = $(BINDIR)/main.o
EXEC = war_game test

all: $(EXEC)

war_game: $(OBJ)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

$(BINDIR)/%.o: $(SRCDIR)/%.cxx
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(SRCDIR)/Piletest.h $(SRCDIR)/Pile.hxx
	@mkdir -p $(BINDIR)
	cxxtestgen --error-printer -o $(SRCDIR)/test.cpp $(SRCDIR)/Piletest.h
	$(CXX) $(CXXFLAGS) -o $@ $(SRCDIR)/test.cpp $(SRCDIR)/Pile.hxx

clean:
	rm -f $(BINDIR)/*.o $(EXEC) $(SRCDIR)/test.cpp

.PHONY: all clean
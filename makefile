DIR=terminal
OBJS=$(DIR)/Tree.o $(DIR)/main.o
CXXFLAGS=-O2 -std=c++11

terminal: $(OBJS)
	g++ -o $(DIR)/terminal $(OBJS)
main.o: $(DIR)/main.cpp
	g++ -c $(DIR)/main.cpp $(CXXFLAGS)
Tree.o: $(DIR)/Tree.cpp
	g++ -c $(DIR)/Tree.cpp $(CXXFLAGS)
clean:
	rm -f *.o
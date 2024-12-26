CXX = g++
CXXFLAGS = -Wall

OBJECTS = bst.o wordrange.o

wordrange: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o wordrange $(OBJECTS)

bst.o: bst.cpp bst.h
	$(CXX) -g $(CXXFLAGS) -c bst.cpp

wordrange.o: wordrange.cpp bst.h
	$(CXX) -g $(CXXFLAGS) -c wordrange.cpp

clean:
	rm -f *.o
	rm -f wordrange

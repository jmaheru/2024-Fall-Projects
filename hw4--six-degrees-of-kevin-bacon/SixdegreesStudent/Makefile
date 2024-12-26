CXX = g++
CXXFLAGS = -Wall

OBJECTS = bfs.o sixdegrees.o

sixdegrees: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o sixdegrees $(OBJECTS)

bfs.o: bfs.cpp bfs.h
	$(CXX) -g $(CXXFLAGS) -c bfs.cpp

sixdegrees.o: sixdegrees.cpp bfs.h
	$(CXX) -g $(CXXFLAGS) -c sixdegrees.cpp

clean:
	rm -f *.o
	rm -f sixdegrees

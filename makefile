CXX=g++
CXXFLAGS=-std=c++11

CPM: Graph.o CPM.o
	$(CXX) $(CXXFLAGS) Graph.o CPM.o -o CPM

CPM.o: Graph.o
	$(CXX) $(CXXFLAGS) -c CPM.cpp -o CPM.o

Graph.o: Graph.hpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp -o Graph.o

clean:
	rm *.o CPM

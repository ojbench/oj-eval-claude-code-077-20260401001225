CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

all: code

code: main.cpp CrossArray.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o code

clean:
	rm -f code *.o

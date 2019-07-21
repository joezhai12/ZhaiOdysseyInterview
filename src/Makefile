CXX = g++
CXXFLAGS = -Wall -g -std=c++17

all : matrix.test.o matrix.o
		$(CXX) $(CXXFLAGS) -o matrix_test matrix.test.o matrix.o

matrix.test.o : matrix.test.cpp matrix.h
			$(CXX) $(CXXFLAGS) -c matrix.test.cpp

matrix.o : matrix.h

clean : 
	rm matrix_test *.o
CXX = g++
CXXFLAGS = -Wall -g -std=c++17

all : test.o matrix.o
		$(CXX) $(CXXFLAGS) -o test test.o matrix.o

test.o : test.cpp matrix.h
			$(CXX) $(CXXFLAGS) -c test.cpp

matrix.o : matrix.h

# matrix.test.o : matrix.test.cpp matrix.test.h
# 					cc -c matrix.test.cpp

clean : 
	rm test *.o
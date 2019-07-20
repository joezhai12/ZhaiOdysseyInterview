CXX = g++
CXXFLAGS = -Wall -g -std=c++17

all : main.o matrix.o
		$(CXX) $(CXXFLAGS) -o main main.o matrix.o

main.o : main.cpp matrix.h
			$(CXX) $(CXXFLAGS) -c main.cpp

matrix.o : matrix.h

# matrix.test.o : matrix.test.cpp matrix.test.h
# 					cc -c matrix.test.cpp

clean : 
	rm main *.o
matrixtest: matrix.cpp matrixtest.cpp matrix.h
	g++ -g -Wall -pedantic -std=c++11 -Werror matrix.cpp matrixtest.cpp -o matrixtest -lm
clean:
	-rm matrixtest

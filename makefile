matrixtest: matrix.cpp matrixtest.cpp matrix.h rcmatrix.cpp proxy.cpp
	g++ -g -Wall -pedantic -std=c++11 -Werror matrix.cpp matrixtest.cpp rcmatrix.cpp proxy.cpp -o matrixtest -lm
clean:
	-rm matrixtest

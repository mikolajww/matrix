matrixtest: matrix.cpp matrixtest.cpp matrix.h rcmatrix.cpp proxy.cpp incompatibleSizes.cpp indexOutOfRange.cpp
	g++ -g -Wall -pedantic -std=c++11 -Werror *.cpp -o matrixtest -lm
clean:
	-rm matrixtest

#include "matrix.h"

matrix::rcmatrix::rcmatrix(unsigned int i, unsigned int j) {
	count = 1;
	row = i;
	col = j;
	m = new double*[col];
	for(unsigned c = 0; c < col; ++c) {
		m[c] = new double[row]();
	}
}

matrix::rcmatrix::~rcmatrix() {
	for (unsigned c = 0; c < col; ++c) {
		delete[] m[c];
	}
	delete[] m;
}

double matrix::rcmatrix::read(unsigned int i, unsigned int j) const {
	if(i >= 0 && i < row) {
		if(j >=0 && j < col) {
			return m[i][j];
		}
	}
	else throw indexOutOfRange();
	return 0;
}

void matrix::rcmatrix::write(unsigned int i, unsigned int j, double val) {
	if(i >= 0 && i < row) {
		if(j >=0 && j < col) {
			m[i][j] = val;
		}
	}
	else throw indexOutOfRange();
}

#include "matrix.h"

matrix::rcmatrix::rcmatrix(unsigned int i, unsigned int j) {
	count = 1;
	row = i;
	col = j;
	m = new double*[row];
	for(unsigned c = 0; c < row; ++c) {
		m[c] = new double[col]();
	}
}

matrix::rcmatrix::rcmatrix(unsigned int i, unsigned int j, double** p) {
	count = 1;
	row = i;
	col = j;
	m = new double*[row];
	for(unsigned c = 0; c < row; ++c) {
		m[c] = new double[col];
		for(unsigned j_ = 0; j_ < col ; ++j_) {
			m[c][j_] = p[c][j_];
		}
	}
}

matrix::rcmatrix::~rcmatrix() {
	for (unsigned r = 0; r < row; ++r) {
		delete[] m[r];
	}
	delete[] m;
}


matrix::rcmatrix* matrix::rcmatrix::detach() {
	if(count == 1) {
		return this;
	}
	auto* t = new rcmatrix(row,col,m);
	count--;
	return t;
}


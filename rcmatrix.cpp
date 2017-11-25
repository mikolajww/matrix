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

matrix::rcmatrix::rcmatrix(unsigned int i, unsigned int j, double** p) {
	count = 1;
	row = i;
	col = j;
	m = new double*[col];
	for(unsigned c = 0; c < col; ++c) {
		m[c] = new double[row];
		m[c] = p[c];
	}

}

matrix::rcmatrix::~rcmatrix() {
	for (unsigned c = 0; c < col; ++c) {
		delete[] m[c];
	}
	delete[] m;
}


matrix::rcmatrix* matrix::rcmatrix::detach() {
	if(count == 1) {
		return this;
	}
	matrix::rcmatrix* t = new rcmatrix(row,col,m);
	count--;
	return t;
}


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
	}
	for(unsigned i_ = 0; i_ < col; ++i_) {
		for(unsigned j_ = 0; j_ < row ; ++j_) {
			m[i_][j_] = p[i_][j_];
		}
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
		cout<<"count 1"<<endl;
		return this;
	}
	matrix::rcmatrix* t = new rcmatrix(row,col,m);
	count--;
	return t;
}


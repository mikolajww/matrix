#include "matrix.h"
#include <string>
#include <vector>
using namespace std;

matrix::matrix(int row, int col) {
	data = new rcmatrix(row,col);
}
matrix::~matrix() {
	if(--(data->count) == 0) {
		delete data;			
	}
}
matrix::matrix(const matrix& m) {
	m.data->count++;
	data = m.data;
}
void matrix::debugInfo() {
	cerr << "Original matrix at [ " << data->m << " ]" << endl;
	cerr << "Size : " << data->row << " x " << data->col << endl;
	cerr << "Reference count : " << data->count << endl;
}

double matrix::read(unsigned int i, unsigned int j) const {
	check(i,j);
	return data->m[i][j];
}

void matrix::write(unsigned int i, unsigned int j, double val) {
	check(i,j);
	data = data->detach();
	data->m[i][j] = val;
}

inline void matrix::check(unsigned int i, unsigned int j) const {
	if ( (i < 0 || i > data->row) || (j < 0 || j > data->col) ) {
		throw indexOutOfRange();
	}
}

ostream& operator<< (ostream& o, const matrix& m) {
	for(unsigned r = 0; r < m.data->row; ++r) {
		for(unsigned c = 0; c < m.data->col; ++c) {
			o << m.read(r,c) << " ";
		}
		o << endl;
	}
	o << endl;
	return o;
}

istream& operator>> (istream& i, matrix& m) {
	double temp = 0;
	for(unsigned c = 0; c < m.data->col; ++c) {
		for (unsigned r = 0; r < m.data->row; ++r) {
			cout << "Input element [" << c << "][" << r << "]" << endl;
			cin >> temp;
			m.write(c,r,temp);
		}
	}
	return i;
}

matrix::proxy matrix::operator() (unsigned int i, unsigned int j) {
	return proxy(*this,i,j);
}

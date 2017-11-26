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
	checkRange(i,j);
	return data->m[i][j];
}

void matrix::write(unsigned int i, unsigned int j, double val) {
	checkRange(i,j);
	data = data->detach();
	data->m[i][j] = val;
}

inline void matrix::checkRange(unsigned int i, unsigned int j) const {
	if ( (i < 0 || i > data->row) || (j < 0 || j > data->col) ) {
		throw indexOutOfRange(i,j);
	}
}
inline void matrix::checkSize(const matrix& a, const matrix& b) {
	if(a.data->row != b.data->row || a.data->col != b.data->col) {
		throw incompatibleSizes(a.data->row, a.data->col, b.data->row, b.data->col);
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
	cout << m.data->row << "x" << m.data->col << endl;
	for (unsigned r = 0; r < m.data->row; r++) {
		for(unsigned c = 0; c < m.data->col; c++) {
			cout << "Input element [" << r << "][" << c << "]" << endl;
			cin >> temp;
			m.write(r,c,temp);
		}
	}
	return i;
}

matrix::proxy matrix::operator() (unsigned int i, unsigned int j) {
	return proxy(*this,i,j);
}

matrix& matrix::operator= (matrix& a) {
	a.data->count++;
	if(--data->count == 0) {
		delete data;
	}
	data = a.data;
	return *this;
}

bool matrix::operator== (const matrix& a) const {
	checkSize(*this,a);
	for (unsigned r = 0; r < data->row; ++r)	{
		for (unsigned c = 0; c < data->col; ++c)	{
			if(data->m[r][c] != a.data->m[r][c]) {
				return false;
			}
		}
	}
	return true;
}

matrix operator+ (const matrix& a, const matrix& b) {
	checkSize(a,b);
	matrix t(a);
	t += b;
	return t;
}

matrix operator- (const matrix& a, const matrix& b) {
	matrix::checkSize(a,b);
	matrix t(a.data->row, a.data->col);
	for (unsigned r = 0; r < a.data->row; ++r)	{
		for (unsigned c = 0; c < a.data->col; ++c)	{
			t.write(r,c,(a.data->m[r][c] - b.data->m[r][c]));
		}
	}
	return t;
}

/*
matrix operator* (const matrix& a, const matrix& b) {
	if (a.data->columns != b.data->rows) {
        throw incompatibleSizes(a.data->rows, a.data->columns, b.data->rows, b.data->columns);
	}
	matrix t(a.data->col, b.data->row);


}*/

matrix& matrix::operator+= (const matrix& a) {
	matrix::checkSize(a,*this);
	for (unsigned r = 0; r < a.data->row; ++r)	{
		for (unsigned c = 0; c < a.data->col; ++c)	{
			write(r,c,(a.data->m[r][c] + data->m[r][c]));
		}
	}
	return *this;
}
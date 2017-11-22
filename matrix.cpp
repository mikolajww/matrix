#include "matrix.h"
#include <string>
#include <vector>
using namespace std;

matrix::matrix(int row, int col) {
	data = new rcmatrix(row,col);
}

matrix::~matrix() {
	delete data;
}

ostream& operator<< (ostream& o, const matrix& m) {
	for(unsigned r = 0; r < m.data->row; ++r) {
		for(unsigned c = 0; c < m.data->col; ++c) {
			o << m.data->read(r,c) << " ";
		}
		o << endl;
	}
	o << endl;
	return o;
}

istream& operator>> (istream& i, matrix& m) {
	int rows = 0, cols = 0;
	bool valid = false;
	while (!valid){
		valid = true;
		cout << "Number of rows: ";
		i >> rows;
		if(i.fail() || rows <=0) {
			i.clear(); 
			i.ignore( 1000, '\n' );
			cout << "\nPlease enter a integer value greater than 0." << endl;
			valid = false;
		}
	}
	valid = false;
	while (!valid){
		valid = true;
		cout << "Number of columns: ";
		i >> cols;
		if(i.fail() || rows <=0) {
			i.clear(); 
			i.ignore( 1000, '\n' );
			cout << "\nPlease enter a integer value greater than 0." << endl;
			valid = false;
		}
	}
	for(int r = 0; r < rows; ++r) {

	}

	return i;
}

matrix::proxy matrix::operator() (unsigned int i, unsigned int j) {
	return proxy(*this,i,j);
}

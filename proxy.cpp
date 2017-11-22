#include "matrix.h"

matrix::proxy::operator double() const {
	cout << "proxy read" << endl;
	return parent.data->read(row,col);
}

matrix::proxy& matrix::proxy::operator= (double val) {
	cout << "proxy write" << endl;
	parent.data->write(row,col,val);
	return *this;

}
matrix::proxy& matrix::proxy::operator= (const proxy& ref) {
	return operator= ((double)ref);
}
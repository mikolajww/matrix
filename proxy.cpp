#include "matrix.h"

matrix::proxy::operator double() const {
	return parent.read(row,col);
}

matrix::proxy& matrix::proxy::operator= (double val) {
	parent.write(row,col,val);
	return *this;

}
matrix::proxy& matrix::proxy::operator= (const proxy& ref) {
	return operator= ((double)ref);
}
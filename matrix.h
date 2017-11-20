#include <iostream>


class rcmatrix {
	private:
		class Matrix;
		Matrix* data;
	public:
		class proxy;
		rcmatrix();
		~rcmatrix();
		rcmatrix(const rcmatrix& a);
		rcmatrix(FILE* file);
		rcmatrix& operator= (const rcmatrix& a);
		friend ostream& operator<< (const ostream& o, const rcmatrix& m);
		friend istream& operator>> (const istream& o, const rcmatrix& m);
		friend rcmatrix operator+ (const rcmatrix& a, const rcmatrix& b);
		friend rcmatrix operator- (const rcmatrix& a, const rcmatrix& b);
		friend rcmatrix operator* (const rcmatrix& a, const rcmatrix& b);
		rcmatrix& operator+= (const rcmatrix& a);
		rcmatrix& operator-= (const rcmatrix& a);
		rcmatrix& operator*= (const rcmatrix& a);
		bool operator== (const rcmatrix& a) const;
		proxy operator() (unsigned int i, unsigned int j)

};

class rcmatrix::Matrix {
	double** m;
	unsigned int row;
	unsigned int col;
	unsigned int count;

	Matrix(unsigned int i, unsigned int j) {
		n = 1;
		row = i;
		col = j;
		m = new double[col];
		for(unsigned c = 0; c < col; ++c) {
			m[c] = new double[row];
		}



	}





};



class rcmatrix::proxy {
	public:
		proxy();
		~proxy();
	
};
#include <iostream>


using namespace std;
class matrix {
	private:
		class rcmatrix;
		rcmatrix* data;
	public:
		class proxy;
		class indexOutOfRange {};
		//class incompatibleSizes;
		matrix(int row = 0, int col = 0);
		~matrix();
		// matrix(const matrix& a);
		// matrix(FILE* file);
		// matrix& operator= (const matrix& a);
		friend ostream& operator<< (ostream& o, const matrix& m);
		friend istream& operator>> (istream& i, matrix& m);
		// friend matrix operator+ (const matrix& a, const matrix& b);
		// friend matrix operator- (const matrix& a, const matrix& b);
		// friend matrix operator* (const matrix& a, const matrix& b);
		// matrix& operator+= (const matrix& a);
		// matrix& operator-= (const matrix& a);
		// matrix& operator*= (const matrix& a);
		// bool operator== (const matrix& a) const;
		proxy operator() (unsigned int i, unsigned int j);

};

class matrix::rcmatrix {
	private:
		double** m;
		unsigned int count;
	public:
		unsigned int row;
		unsigned int col;
		rcmatrix(unsigned int i, unsigned int j);
		~rcmatrix();
		double read(unsigned int i, unsigned int j) const;
		void write(unsigned int i, unsigned int j, double val);
};

class matrix::proxy {
	private:
		friend class matrix;
		matrix& parent;
		unsigned int row;
		unsigned int col;
	public:
		proxy(matrix& m, int r, int c) : parent(m), row(r), col(c) {};
		operator double () const;
		proxy& operator= (double val);
		proxy& operator= (const proxy& ref);
};
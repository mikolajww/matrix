#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;
class matrix {
	private:
		class rcmatrix;
		rcmatrix* data;
		double read(unsigned int i, unsigned int j) const;
		void write(unsigned int i, unsigned int j, double val);
		inline void checkRange(unsigned int i, unsigned int j) const;
		inline static void checkSize(const matrix& a, const matrix& b);
	public:
		class proxy;
		class indexOutOfRange;
		class incompatibleSizes;
		matrix(int row = 0, int col = 0);
		matrix(const matrix& m);
		~matrix();
		matrix& operator= (matrix& a);
		friend ostream& operator<< (ostream& o, const matrix& m);
		friend istream& operator>> (istream& i, matrix& m);
		friend matrix operator+ (const matrix& a, const matrix& b);
		friend matrix operator- (const matrix& a, const matrix& b);
		friend matrix operator* (const matrix& a, const matrix& b);
		matrix& operator+= (const matrix& a);
		matrix& operator-= (const matrix& a);
		matrix& operator*= (const matrix& a);
		bool operator== (const matrix& a) const;
		proxy operator() (unsigned int i, unsigned int j);
		void debugInfo();

};

class matrix::rcmatrix {
	public:
		double** m;
		unsigned int count;
		unsigned int row;
		unsigned int col;
		
		rcmatrix(const rcmatrix& r) = delete;
		rcmatrix& operator=(const rcmatrix&) = delete;
		rcmatrix(unsigned int i, unsigned int j);
		rcmatrix(unsigned int i, unsigned int j, double** p);
		~rcmatrix();
		rcmatrix* detach();
		void assign(unsigned int i, unsigned int j, double** m);
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

class matrix::incompatibleSizes : public runtime_error {
	public:
		incompatibleSizes(unsigned aR, unsigned aC, unsigned bR, unsigned bC) : runtime_error(prepareMessage(aR, aC, bR, bC)) {};

	private:
		static string prepareMessage(unsigned aR, unsigned aC, unsigned bR, unsigned bC);
};	

class matrix::indexOutOfRange : public runtime_error {
	public:
		indexOutOfRange(unsigned r, unsigned c) : runtime_error(prepareMessage(r,c)) {};

	private:
		static string prepareMessage(unsigned r, unsigned c);
};		

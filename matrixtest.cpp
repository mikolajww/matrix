#include "matrix.h"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
	//Constructors
	matrix m(3,4);
	matrix m1(4,3);
	matrix m2;
	matrix m3(m1);
	//Reference counting
	cout << "Matrix m1" << endl;
	m1.debugInfo();
	cout << "Matrix m3 constructed from m1" << endl;
	m3.debugInfo();
	//Proxy class
	cout << "Matrix m at [0,0] = " << m(0,0) << endl;
	m(0,0) = 1;
	cout << "Matrix m at [0,0] = " << m(0,0) << endl;
	//Stream operators
	cout << "Matrix m" << endl;
	cout << m;
	cout << "Input matrix m1" << endl;
	cin >> m1;
	fstream f("matrix.txt");
	f >> m3;
	cout << m;
	f.close();
	//Exceptions
	//Invalid index
	try {
		cout << m(5,5);
	}
	catch(const exception& e) {
		cerr << e.what() << '\n';
	}
	//Incompatible sizes
	try {
		cout << m1 + m2;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	//Comparison
	try {
		(m3 == m1)?(cout << "m3 == m"<< endl):(cout << "m3 != m" << endl); 
		(m == m1)?(cout << "m == m1"<< endl):(cout << "m != m1" << endl); 
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}
	//Addition
	try {
		cout << "Addition" << endl;
		cout << m1 << endl;
		cout << m3 << endl;
		cout << "Result" << endl;
		cout << (m1 + m3) << endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}

	try {
		cout << "Subtraction" << endl;
		cout << m1 << endl;
		cout << m3 << endl;
		cout << "Result" << endl;
		cout << (m1 - m3) << endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}

	try {
		cout << "Addition +=" << endl;
		cout << m1 << endl;
		cout << m3 << endl;
		m1 +=m3;
		cout << "Result" << endl;
		cout << m1 << endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}
	try {
		cout << "SUBTRACT -=" << endl;
		cout << m1 << endl;
		cout << m3 << endl;
		m1 -=m3;
		cout << "Result" << endl;
		cout << m1 << endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}

	try {
		cout << "Multiplication " << endl;
		cout << m1 << endl;
		cout << m << endl;
		cout << "Result" << endl;
		cout << (m1 * m) << endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}

	try {
		cout << "Multiplication *=" << endl;
		cout << m1 << endl;
		cout << m << endl;
		m1 *= m;
		cout << "Result" << endl;
		cout << m1 << endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}

	
	return 0;
}
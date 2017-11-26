#include "matrix.h"
using namespace std;

int main(int argc, char const *argv[]) {
	
	matrix m(3,4);
	try {
		cout << m(4,4) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	m(0,0) = 1;
	//cout << m(0,0) << endl;
	//cout << m << endl;
	//m.debugInfo();
	matrix m1(4,3);
	//m.debugInfo();
	//m1.debugInfo();
	m1(0,1) = 5;
	
	//cin >> m1;
	cout << m1;
	m = m1;
	m1(1,0) = 4;
	//cout << m;
	//m.debugInfo();
	//m1.debugInfo();
	//m.debugInfo();
	try {
		cout << (m1 == m) << endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}

	try {
		cout << "ADD" << endl;
		cout << m1 << endl;
		cout << m << endl;
		cout << (m1 + m) << endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}

	try {
		cout << "SUBTRACT" << endl;
		cout << m1 << endl;
		cout << m << endl;
		cout << (m1 - m) << endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}

	try {
		cout << "ADD +=" << endl;
		cout << m1 << endl;
		cout << m << endl;
		m1 +=m;
		cout << m1 << endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}


	
	return 0;
}
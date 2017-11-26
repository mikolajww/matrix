#include "matrix.h"
using namespace std;

int main(int argc, char const *argv[]) {
	
	matrix m(3,4);
	try {
		cout << m(4,4) << endl;
	}
	catch (...) {
		cout << "exception caught" << endl;
	}
	m(0,0) = 1;
	cout << m(0,0) << endl;
	cout << m << endl;
	m.debugInfo();
	matrix m1(4,3);
	m.debugInfo();
	m1.debugInfo();
	m1(0,1) = 5;
	m1(1,0) = 4;
	cin >> m1;
	cout << m1;
	matrix m2;
	cin >> m2;
	cout << m2;
	m.debugInfo();
	m1.debugInfo();
	m.debugInfo();
	return 0;
}
#include "matrix.h"

string matrix::indexOutOfRange::prepareMessage(unsigned r, unsigned c){
	std::string s;
	s.append("Index out of range : (");
	s.append(std::to_string(r));
	s.append(",");
	s.append(std::to_string(c));
	s.append(")");
	return s;
}
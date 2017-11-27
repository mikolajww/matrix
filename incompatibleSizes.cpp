#include "matrix.h"

string matrix::incompatibleSizes::prepareMessage(unsigned aR, unsigned aC, unsigned bR, unsigned bC){
	std::string s;
	s.append("Incompatible sizes : ");
	s.append(std::to_string(aR));
	s.append("x");
	s.append(std::to_string(aC));
	s.append(" and ");
	s.append(std::to_string(bR));
	s.append("x");
	s.append(std::to_string(bC));
	return s;
}
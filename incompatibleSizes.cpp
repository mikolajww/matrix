#include "matrix.h"

matrix::incompatibleSizes::incompatibleSizes(unsigned aR, unsigned aC, unsigned bR, unsigned bC) :
											 runtime_error(""), aRows(aR), aCols(aC), bRows(bR), bCols(bC) {
			s.append("Incompatible sizes : ");
			s.append(std::to_string(aRows));
			s.append("x");
			s.append(std::to_string(aCols));
			s.append(" and ");
			s.append(std::to_string(bRows));
			s.append("x");
			s.append(std::to_string(bCols));
}
const char* matrix::incompatibleSizes::what() const noexcept {
	return (s.c_str());
}
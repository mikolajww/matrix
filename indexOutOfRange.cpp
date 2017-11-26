#include "matrix.h"

matrix::indexOutOfRange::indexOutOfRange(unsigned r, unsigned c) : runtime_error(""), rows(r), cols(c) {
	s.append("Index out of range : (");
	s.append(std::to_string(rows));
	s.append(",");
	s.append(std::to_string(cols));
	s.append(")");
}

const char* matrix::indexOutOfRange::what() const noexcept {
	return (s.c_str());
}
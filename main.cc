#include "vector.h"
#include <iostream>

int main(void) {
	ndr::Vec v;
	v.append(3);
	v.append(5);
	v.append(-12321312);
	std::cout << v[0] << ' ' << v[-1] << ' ' << v.get_size() << std::endl;
}

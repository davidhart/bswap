#include <iostream>
#include "util.h"

int main()
{
	short int s = 0xa0;
	Util::BSwap(s);
	Util::BSwap(s);
	std::cout << s << std::endl;
	std::cout.fill('0');
	std::cout.width(4);
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout << s << std::endl;

	std::cout.width(0);
	std::cout.setf(std::ios::dec, std::ios::basefield);
	int i = 10;
	Util::BSwap(i);
	Util::BSwap(i);
	std::cout << i << std::endl;

	std::cout.width(8);
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout << i << std::endl;

	std::cout.width(0);
	std::cout.setf(std::ios::dec, std::ios::basefield);
	__int64 l = 0x0123456789ABCDEF;
	Util::BSwap(l);
	Util::BSwap(l);
	std::cout << l << std::endl;
	std::cout.width(16);
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout << l << std::endl;

	return 0;
}
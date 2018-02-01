#include <iostream>
#include "BankersAlgorithm.h"

int main(int argc, char** argv) {
	try {
		BankersAlgorithm ba(4, 2, argv, argc);
		ba.safeSequence();
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
	std::cin.get();
	return 0;
}
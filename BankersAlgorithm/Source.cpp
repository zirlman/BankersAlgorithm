#include <iostream>
#include "BankersAlgorithm.h"

int main(int argc, char** argv) {
	BankersAlgorithm ba(4, 2, argv, argc);
	ba.safeSequence();
	std::cin.get();
	return 0;
}
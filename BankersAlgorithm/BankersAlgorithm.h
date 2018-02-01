#pragma once
#include <vector>

class BankersAlgorithm {
public:
	BankersAlgorithm(int processes, int resources, char** argv, int argc);
	~BankersAlgorithm();
	void safeSequence();
	bool isAvailable(int i);
private:
	int** maxMatrix;
	int** allocationMatrix;
	int** needMatrix;
	int* availableVector;
	int* marked;
	int P;
	int R;
	std::vector<int> safe;
};
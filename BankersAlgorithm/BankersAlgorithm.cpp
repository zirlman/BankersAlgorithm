#include "BankersAlgorithm.h"
#include <string>
#include <iostream>

BankersAlgorithm::BankersAlgorithm(int processes, int resources, char ** argv, int argc) : R(resources), P(processes), safeSeqCount(0)
{
	if (argc < 19)
		throw std::range_error("Potrebno je unijeti 8 resursa za alokaciju, 8 za potrebu i 2 resursa za slobodan vektor!\n");
	allocationMatrix = new int*[processes]();
	maxMatrix = new int*[processes]();
	needMatrix = new int*[processes]();
	availableVector = new int[resources]();
	marked = new int[processes]();

	int k = 0;
	for (int i = 0; i < 2 * P;)
	{
		allocationMatrix[k] = new int[R]();
		maxMatrix[k] = new int[R]();
		needMatrix[k] = new int[R]();
		std::string tmp1(argv[i + 1]);
		int a = std::stoi(tmp1);
		std::string tmp2(argv[i + 2]);
		int b = std::stoi(tmp2);
		allocationMatrix[k][0] = a;
		allocationMatrix[k++][1] = b;
		i += 2;
	}
	k = 0;
	for (int i = 2 * P; i < 4 * P;)
	{
		std::string tmp1(argv[i + 1]);
		int a = std::stoi(tmp1);
		std::string tmp2(argv[i + 2]);
		int b = std::stoi(tmp2);
		needMatrix[k][0] = a;
		needMatrix[k++][1] = b;
		i += 2;
	}

	for (int i = 0; i < P; ++i)
	{
		maxMatrix[i][0] = allocationMatrix[i][0] + needMatrix[i][0];
		maxMatrix[i][1] = allocationMatrix[i][1] + needMatrix[i][1];
	}
	k = 0;
	--argc;
	for (int i = 4 * P; i < argc; ++i) {
		std::string tmp(argv[i + 1]);
		availableVector[k++] = std::stoi(tmp);
	}
}

BankersAlgorithm::~BankersAlgorithm()
{
	if (safeSeqCount == 0)
		std::cout << "Sistem nije u bezbijednom stanju" << std::endl;
	for (int i = 0; i < P; ++i)
	{
		delete[] allocationMatrix[i];
		delete[] needMatrix[i];
		delete[] maxMatrix[i];
	}

	delete[] allocationMatrix;
	allocationMatrix = nullptr;
	delete[] needMatrix;
	needMatrix = nullptr;
	delete[] maxMatrix;
	maxMatrix = nullptr;
	delete[] availableVector;
	availableVector = nullptr;

}

void BankersAlgorithm::safeSequence()
{
	for (int i = 0; i < P; ++i)
	{
		if (!marked[i] && isAvailable(i))
		{
			marked[i] = true;
			for (int j = 0; j < R; ++j)
				availableVector[j] += allocationMatrix[i][j];
			safe.push_back(i);
			safeSequence();
			safe.pop_back();
			marked[i] = false;
			for (int j = 0; j < R; ++j)
				availableVector[j] -= allocationMatrix[i][j];
		}
	}

	if (safe.size() == P)
	{
		++safeSeqCount;
		for (int i = 0; i < P; ++i)
		{
			std::cout << "P" << safe[i] + 1;
			if (i != P - 1)
				std::cout << "-->";
		}
		std::cout << std::endl;
	}
}

bool BankersAlgorithm::isAvailable(int i)
{
	for (int j = 0; j < R; ++j)
		// Ukoliko proces trazi vise resursa nego sto je slobodno, stanje nije sigurno
		if (availableVector[j] < needMatrix[i][j])
			return false;
	return true;
}

#include <iostream>
#include <vector>
#include "randNumListGen.h"
#include "insertSort.h"
#include "selectSort.h"
#include "quickSort.h"
#include "sortCheck.h"


void coutVectInt(std::vector<int> vInt);

void main() {

	std::vector<int> vInt;
	vInt = randomizedList(100, 0, 99);

	coutVectInt(vInt);

	quickSort(vInt, vInt.begin(), vInt.end()-1);

	std::cout << "===============" << '\n';

	coutVectInt(vInt);

	if (isSorted(vInt)) {
		std::cout << "this list is sorted" << std::endl;
	}
	else {
		std::cout << "this list is not sorted!" << std::endl;
	}
	std::cin.get();
	std::cin.get();
}

void coutVectInt(std::vector<int> vInt) {
	for (std::vector<int>::iterator it = vInt.begin(); it != vInt.end(); it++) {
		std::cout << *it << std::endl;
	}
}

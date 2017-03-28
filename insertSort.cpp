#include "insertSort.h"



template<typename ElumType>
void insertionSort(std::vector<ElumType> &vT){
	for (std::vector<ElumType>::iterator itOne = std::next(vT.begin()); itOne != vT.end(); itOne++) {
		std::vector<ElumType>::reverse_iterator ritOne(itOne + 1);
		std::vector<ElumType>::reverse_iterator ritOth(ritOne + 1);
		while ((*ritOne < *ritOth) && (ritOth != vT.rend())) {
			swap(*ritOne, *ritOth);
			ritOne = ritOth;
			++ritOth;
			if (ritOth == vT.rend()) {
				break;
			}
		}
	}
};

#include "quickSort.h"

template<typename ElumType>
void quickSort(std::vector<ElumType> &vT, typename std::vector<ElumType>::iterator indL, typename std::vector<ElumType>::iterator indR) {

	int part;
	if (vT.size() < 1) {
		return;
	}
	else {
		coutQSBounds(vT, indL, indR);
		part = partition(vT, indL, indR);
	}
	std::vector<ElumType>::iterator p = (vT.begin() + part);

	std::cout << "checkpoint D - part: " << part << std::endl;
	if (p >= vT.begin()+1) {
		if (indL < p - 1) {
			std::cout << "p-1" <<std::endl;
			coutQSBounds(vT, indL, p - 1);
			quickSort(vT, indL, p - 1);
		}
	}
	if (p < vT.end()-1) {
		if (p + 1 < indR) {
			std::cout << "p+1" <<std::endl;
			coutQSBounds(vT, p + 1, indR);
			quickSort(vT, p + 1, indR);
		}
	}
	
}


template<typename ElumType>
void coutQSBounds(std::vector<ElumType> &vT, typename std::vector<ElumType>::iterator indL, typename std::vector<ElumType>::iterator indR) {
	std::cout << "QS: " << std::distance(vT.begin(), indL) << " - " << std::distance(vT.begin(), indR) << std::endl;


	for (std::vector<ElumType>::iterator it = indL; it < indR; it++) {
		std::cout << *it << ",";
	}
	std::cout << *indR << std::endl;
}


template<typename ElumType>
void quickSortSub(std::vector<ElumType> &vT) {
	selectPivot();
}

template<typename ElumType>
int partition(std::vector<ElumType> &vT,typename std::vector<ElumType>::iterator l,typename std::vector<ElumType>::iterator r) {
	
	std::vector<ElumType>::iterator i(l);
	std::vector<ElumType>::iterator j(r);
	int pivLoc = selectPivot(vT,l,r);

	ElumType pivot = vT[pivLoc]; 
	std::vector<ElumType>::iterator p(vT.begin() + pivLoc);
	std::cout << "pivot: " << pivLoc << "=" << pivot << std::endl;
	swap(*p, *l);
	while (i <= j) {
		//find the location of th
		while (*i <= pivot && i != vT.end()-1 && i <=j ) { // because i <= j , this is incrementing.
			std::cout << "i++: " << std::distance(vT.begin(), i) << std::endl;
			i++;
		}
		while (*j >= pivot && j != vT.begin() && i <=j ) { // does this need && i < j
			std::cout << "j--: " << std::distance(vT.begin(), j) << std::endl;
			j--;

		}
		if (i < j) {
			std::cout << "swapping " << std::distance(vT.begin(), i) << ":" << *i << " - " << std::distance(vT.begin(), j) << ":" << *j << std::endl;
			swap(*i, *j);
			//i++;
			//j--;
		}
	}
	std::cout << "checkpoint A" << std::endl;

	if (i >= vT.begin()+1) {
		std::cout << "checkpoint B" << std::endl;
		swap(*(i - 1), *l);
		std::cout << "checkpoint C" << std::endl;
		return std::distance(vT.begin(), i - 1);
	}

	else {
		std::cout << "checkpoint C" << std::endl;

		return 0;

	}

}

template<typename ElumType>
int selectPivot(std::vector<ElumType> &vT,typename std::vector<ElumType>::iterator l,typename std::vector<ElumType>::iterator r) {
	ElumType L = *l;
	ElumType R = *r;
	int lDist = std::distance(vT.begin(), l);
	int rDist = std::distance(vT.begin(), r);
	int mDist = ((rDist - lDist) / 2) + lDist;
	ElumType M = vT[mDist];

	if (checkIfMid(L, M, R) ){
		return mDist;
	}
	if (checkIfMid(M, L, R)) {
		return lDist;
	}
	if (checkIfMid(L, R, M)) {
		return rDist;
	}
	else return 0;
}

template<typename ElumType>
bool checkIfMid(ElumType L, ElumType M, ElumType R) {
	if (L < M && M < R) {
		return true;
	}
	else if (R < M && M < L) {
		return true;
	}
	else if (R == M || M == L) {
		return true;
	}
	return false;

}
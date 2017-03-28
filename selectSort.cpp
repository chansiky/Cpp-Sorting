#include "selectSort.h"

template<typename ElumType>
void selectionSort(std::vector<ElumType> &v_T) {
	//starting from 0
	// search every item in the list for the lowest number.  keep a marker on the lowest number
	// when the lowest is found, 
	for (std::vector<ElumType>::iterator itPos = v_T.begin(); itPos != v_T.end(); itPos++) {
		std::vector<ElumType>::iterator itMin = itPos;
		//increment itSearch and find and keep the value of the lowest number;
		for (std::vector<ElumType>::iterator itSearch = itPos; itSearch != v_T.end(); itSearch++) {
			if (*itSearch < *itMin) {
				itMin = itSearch;
			}
		}
		swap(*itPos, *itMin);
	}
};
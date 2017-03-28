#include "sortCheck.h"
#include <vector>


template<typename _T>
bool isSorted(std::vector<_T> v_T){
	_T a = v_T[0];
	_T b = v_T[1];

	for (std::vector<_T>::iterator it = v_T.begin(); it != v_T.end()-1; it++) {
		if (*it > *(it + 1)) {
			return false;
		}
	}
	return true;
}
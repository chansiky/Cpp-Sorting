#pragma once
#include <vector>
#include <random>
#include <time.h>
#include "swap.h"
#include <queue>

///quickSort Algorithm
template<typename ElumType>
void quickSort(std::vector<ElumType> &vT,typename std::vector<ElumType>::iterator indL,typename std::vector<ElumType>::iterator indR);

///quickSort partitioning
template<typename ElumType>
int partition(std::vector<ElumType> &vT,typename std::vector<ElumType>::iterator l, typename std::vector<ElumType>::iterator r);

///selects a random pivot
int selectPivot(int L, int R);

///selects the median of three pivot
template<typename ElumType>
int selectPivot(std::vector<ElumType> &vT,typename std::vector<ElumType>::iterator l,typename std::vector<ElumType>::iterator r);

///subroutine for selecting pivot: check for finding out if a pivot is the lesser of the two;
template<typename ElumType>
bool checkIfMid(ElumType L, ElumType M, ElumType R);

#include "quickSort.cpp"
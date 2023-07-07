#pragma once
#include "NumArray.h"

template <typename T, template <typename> class _Sorter>
class Sorter {
public:
    //sort method sorting the NumArray vector of T values by a _Sorter algorithm
    void sort(NumArray<T>& data);
};

template <typename T, template <typename> class _Sorter>
void Sorter<T, _Sorter>::sort(NumArray<T>& data) {
    _Sorter<T>::sort(data.GetVec());
}
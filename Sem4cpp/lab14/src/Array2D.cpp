#include "Array2D.h"

Array2D::Array2D(int a,int b): nx(a),ny(b){
    arr = new int[nx*ny];
    for(int i=0;i<nx*ny;i++){
        arr[i]=i+1;
    }
}

Array2D::~Array2D(){
    delete[] arr;
}

int* Array2D::operator[](int i){
    return arr+i*ny;
}

int& Array2D::at(int i,int j) const{
    if(i>=nx){
        throw std::out_of_range("std::out_of_range caught: out of range at i="+std::to_string(i));
    }
    else if(j>=ny){
        throw std::out_of_range("std::out_of_range caught: out of range at j="+std::to_string(j));
    }
    return arr[i*ny+j];
}

int& Array2D::at(int i,int j){
    return const_cast<int&>(static_cast<const Array2D&>(*this).at(i,j));
}

std::ostream& operator<<(std::ostream& os, const Array2D& arr){
    for(int i=0;i<arr.nx;i++){
        for(int j=0;j<arr.ny;j++){
            os<<arr.arr[i*arr.ny+j]<<" ";
        }
        os<<std::endl;
    }
    return os;
}
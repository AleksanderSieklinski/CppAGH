#ifndef LAB03_H
#define LAB03_H
#include <iostream>
#include <cstring>
#include <cstdio>
// Adding a new element to list of years and list of names
void AddStudent(int*,char***,int**,const char*,int);
// Printing all names from the list
void Cat(int,char**);
// Printing all years from the list
void Cat(int,int*);
// Frees memory allocated to the nameslist
void ClearList(int,char***);
// Frees memory allocated to the yearslist
void ClearList(int,int**);
#endif
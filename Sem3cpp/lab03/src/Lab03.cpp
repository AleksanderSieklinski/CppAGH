#include "Lab03.h"
using namespace std;
void AddStudent(int*numberofstudent,char***nameslist,int**yearslist,const char*name,int wiek){
    (*numberofstudent)++;
    char **temp1= new char*[*numberofstudent];
    int *temp=new int[*numberofstudent];
    if(*numberofstudent>1) {
        for(int i=0;i<(*numberofstudent)-1;i++) {
            temp1[i] = new char[strlen((*nameslist)[i])+1];
            strcpy(temp1[i],(*nameslist)[i]);
            delete [](*nameslist)[i];
            temp[i]=(*yearslist)[i];
        }
        delete [] *nameslist;
        delete [] *yearslist;
    }
    temp1[*numberofstudent-1] = new char[strlen(name)+1];
    temp[*numberofstudent-1]=wiek;
    strcpy(temp1[*numberofstudent-1],name);
    *nameslist=temp1;
    *yearslist=temp;
}
void Cat(int numberofstudent,int*yearslist) {
    for(int i=0;i<numberofstudent;i++) {
        cout<<yearslist[i]<<endl;
    }
}
void Cat(int numberofstudent,char**nameslist) {
    for(int i=0;i<numberofstudent;i++) {
        cout<<nameslist[i]<<endl;
    }
}
void ClearList(int numberofstudent,char***nameslist) {
    for(int i=0;i<numberofstudent;i++) {
        delete [] (*nameslist)[i];
    }
    delete [] *nameslist;
    *nameslist=NULL;
}
void ClearList(int numberofstudent,int**yearslist) {
    delete [] *yearslist;
    *yearslist=NULL;
}
#pragma once
#include <iostream>
#include <vector>
#include <typeindex>
#include <memory>

class MyArray{
public:
  // default constructor
  MyArray() = default;
  // destructor
  ~MyArray();
  // template method for adding data of type T
  template<typename T>
  void add(const T& data);
  // template method for removing data of type T
  template<typename T>
  void remove();
  // friend operator for printing data of type T
  friend void operator<<(const char* str, const MyArray& arr);
  // template method for removing data of type T if it is equal to data in parameter
  template<typename T>
  void remove_if(const T& data);
  // template method for inserting data of type T at index
  template<typename T>
  void insert(const T& data, const int& index);
  // method for transferring data from arr to this
  void transfer(MyArray& arr);
private:
  // abstract base class
  struct Base{
    // virtual destructor
    virtual ~Base() = default;
    // pure virtual method for printing data of type T
    virtual std::ostream& toString() const = 0;
    // pure virtual method for returning type of data
    virtual std::type_index type() const = 0;
  };
  // derived class for storing data of type T in a vector of unique pointers to Base class objects
  template<typename T>
  struct BoxofBase: public Base{
    // constructor
    BoxofBase(const T& data): _data(data){}
    // method for printing data of type T
    std::ostream& toString() const override;
    // method for returning type of data
    std::type_index type() const override;
    // data of type T
    T _data;
  };
  std::vector<std::unique_ptr<Base>> _data;
};

template<typename T>
void MyArray::add(const T& data){
  _data.push_back(std::make_unique<BoxofBase<T>>(data));
}

template<typename T>
void MyArray::remove(){
  _data.erase(std::remove_if(_data.begin(), _data.end(), [](const auto& ptr)
  {return typeid(T) == ptr->type();}
  ), _data.end());
}

void operator<<(const char* str, const MyArray& arr){
  for(const auto& ptr: arr._data){
    ptr->toString();
    if(ptr != arr._data.back())
      std::cout << str;
  }
  if(!arr._data.empty()){
    std::cout << std::endl;
  }
}

template<typename T>
std::ostream& MyArray::BoxofBase<T>::toString() const{
  return std::cout << _data;
}

template<typename T>
std::type_index MyArray::BoxofBase<T>::type() const{
  return typeid(T);
}

template<typename T>
void MyArray::remove_if(const T& data){
  _data.erase(std::remove_if(_data.begin(), _data.end(), [&data](const auto& ptr)
  {return typeid(T) == ptr->type() && dynamic_cast<BoxofBase<T>*>(ptr.get())->_data == data;}
  ), _data.end());
}

void MyArray::transfer(MyArray& arr){
  for(const auto& ptr: arr._data){
    _data.push_back(ptr);
  }
  arr._data.clear();
}

template<typename T>
  void MyArray::insert(const T& data, const int& index){
    _data.insert(_data.begin() + index, std::make_unique<BoxofBase<T>>(data));
  }

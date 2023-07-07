#include "MapPoint.h"
MTH::Point::Point(double a,double b): _x{a}, _y{b} {}

double MTH::Point::GetX() const{
    return _x;
}
double MTH::Point::GetY() const{
    return _y;
}
double MP::Point::GetLA() const{
    return _latitude;
}
double MP::Point::GetLO() const{
    return _longitude;
}
std::string MP::Point::GetLab() const {
    return _label;
}
void MTH::Print(const Point &q) {
    std::cout<<"[MTH::Point] X="<<q.GetX()<<" Y="<<q.GetY()<<std::endl;
}

MP::Point::Point(std::string label,double latitude,double longitude): _label{label},_longitude{longitude},_latitude{latitude} {}

MP::Point::Point(std::string label,const MTH::Point& other): _label{label}, _longitude{other.GetY()},_latitude{other.GetX()}{}

void MP::Print(const Point &q) {
    std::cout<<"[MP::Point] "<<q.GetLab()<<": Lattitude="<<q.GetLA()<<" Longitude="<<q.GetLO()<<std::endl;
}

MP::Point& MP::Point::operator=(const MTH::Point&other) {
    this->_longitude = other.GetY();
    this->_latitude = other.GetX();
    return *this;
}

MP::Point& MP::Point::operator=(Point&other) {
    if(this==&other){
        std::cout<<"[MP::Warning] Discarding self alignment"<<std::endl;
    }
    this->_longitude = other.GetLO();
    this->_latitude = other.GetLA();
    return *this;
}
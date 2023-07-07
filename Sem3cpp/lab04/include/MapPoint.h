#ifndef MapPoint_h
#define MapPoint_h
#include <iostream>
#include <cmath>
class MapPoint{
    public:
    //setting the x(latitude) private value in class
    void set_latitude(double);
    //setting the y(longitude) private value in class
    void set_longitude(double);
    //displaying latitude and longitude of a class member
    void print();
    //setting both x and y(latitude and longitude) private values in class
    void set_coordinates(double,double);
    //searching for the closest from current class member to cities in arguments
    MapPoint closest(MapPoint,MapPoint);
    //searching for the midway point between current class member and city in argument
    MapPoint half_way_to(MapPoint);

    private:
    double _longitude;
    double _latitude;
};
#endif
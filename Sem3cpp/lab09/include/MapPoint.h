#ifndef MapPoint_h
#define MapPoint_h
#include <iostream>
#include <string>
namespace MTH {
    class Point {
        public:
        //constructor from two double values
        Point(double,double);
        //returning value of X
        double GetX() const;
        //returning value of Y
        double GetY() const;
        private:
        double _x,_y;
    };
    //Printing the values of X and Y
    void Print(const Point &);
}
namespace MP {
    class Point {
        public:
        //constructor from two double values and one string
        Point(std::string,double,double);
        //constructor from a string and Point class member from MTH namespace
        Point(std::string,const MTH::Point&);
        //constructor from a string and Point class member from same namespace
        Point(std::string,Point&);
        //returning value of Latitude
        double GetLA() const;
        //returning value of Longitude
        double GetLO() const;
        //returning value of a string
        std::string GetLab() const;
        //assignment operator definiton for MTH namespace Point member
        Point& operator=(const MTH::Point&other);
        //assignment operator definition for same namespace Point members
        Point& operator=(Point&other);
        private:
        double _longitude,_latitude;
        std::string _label;
    };
    //Printing the label string and values of latitude and longitude
    void Print(const Point &);
}
#endif
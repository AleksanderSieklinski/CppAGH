#include "MapPoint.h"
using namespace std;
void MapPoint::set_latitude(double lat) {
    _latitude=lat;
}
void MapPoint::set_longitude(double lot) {
    _longitude=lot;
}
void MapPoint::print() {
    cout<<"Point: ("<<_latitude<<","<<_longitude<<")"<<endl;
}
void MapPoint::set_coordinates(double lat,double lon) {
    _latitude=lat;
    _longitude=lon;
}
MapPoint MapPoint::closest(MapPoint a,MapPoint b) {
    double v1 = _latitude-a._latitude;
    double v2 = _latitude-b._latitude;
    double v3 = _longitude-a._longitude;
    double v4 = _longitude-b._longitude;
    MapPoint r;
    if(sqrt(pow(v1,2)+pow(v3,2))>=sqrt(pow(v2,2)+pow(v4,2))) {
        return b;
    }
    return a;
}
MapPoint MapPoint::half_way_to(MapPoint a){
    MapPoint r;
    double x=(_latitude+a._latitude)/2;
    double y=(_longitude+a._longitude)/2;
    r.set_coordinates(x,y);
    return r;
}
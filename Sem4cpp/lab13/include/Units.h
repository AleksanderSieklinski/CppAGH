#pragma once
#include <iostream>

template <typename T>
class Length;

template <typename T>
class Area;

template <typename T>
class Time;

template <typename T>
class Velocity;

template <typename T>
class Acceleration;

template <typename T>
class Weigh;

using m = Length<double>;
using s = Time<double>;
using kg = Weigh<double>;

template <typename T>
class Length{
    public:
    T value;
    Length(T value) : value(value) {}
    operator T() const {
        return value;
    }
};

template <typename T>
class Area{
    public:
    T value;
    Area(T value) : value(value) {}
    operator T() const {
        return value;
    }
};

template <typename T>
class Time{
    public:
    T value;
    Time(T value) : value(value) {}
    operator T() const {
        return value;
    }
};

template <typename T>
class Velocity{
    public:
    T value;
    Velocity(T value) : value(value) {}
    operator T() const {
        return value;
    }
};

template <typename T>
class Acceleration{
    public:
    T value;
    Acceleration(T value) : value(value) {}
    operator T() const {
        return value;
    }
};

template <typename T>
class Weigh{
    public:
    T value;
    Weigh(T value) : value(value) {}
    operator T() const {
        return value;
    }
};
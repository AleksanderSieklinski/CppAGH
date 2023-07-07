#ifndef line_h
#define line_h
#include <iostream>
    class Line {
        public:
        //befriending class LPrint
        friend class LPrint;
        //befriending class LArray
        friend class LArray;
        //default constructor
        Line();
        //constructor/conversion constructor from one double value
        Line(double);
        //constructor taking two values for a&b
        Line(double,double);
        //defining () operator to return a*x+b
        double operator()(double) const;
        //function returning x0=-(b/a)
        int X0() const;
        private: 
        double _a,_b;
    };
    class LPrint{
        public:
        //defining () operator to print out the function and x0
        void operator()(const Line&) const;
    };
    class LArray{
        public:
        //default constructor
        LArray();
        //constructor/conversion constructor setting the size of array
        LArray(size_t);
        //destructor deleting the dynamic array
        ~LArray();
        //function adding an element to the array assigning argument as a&b
        void Add(int);
        //overloaded previous function adding object from the argument to the array
        void Add(Line&);
        //defining [] operator to return the tab[i] element 
        Line& operator[](int) const;
        private:
        size_t _size;
        Line *_tab;
        int _count;
    };
#endif
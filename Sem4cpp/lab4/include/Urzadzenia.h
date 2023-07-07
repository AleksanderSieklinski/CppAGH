#include <iostream>
class Rozdzielczosc {
public:
    //constructor setting values of x and y
    Rozdzielczosc(int,int);
    //returning value of x
    int x() const;
    //returning value of y
    int y() const;
    private:
    int x_,y_;
};
class Urzadzenie {
public:
    //constructor setting res
    Urzadzenie(Rozdzielczosc res);
    //destructor
    virtual ~Urzadzenie();
    //turning _wlaczone true
    virtual void wlacz();
    //turning _wlaczone false
    virtual void wylacz();
    //showing resolution of an obj
    std::string rozdzielczosc() const;
    bool _wlaczone;
    Rozdzielczosc _res;
};
class Skaner : public Urzadzenie {
public:
    //constructor setting res
    Skaner(Rozdzielczosc);
    //destructor
    virtual ~Skaner();
    //turning _wlaczone true
    virtual void wlacz();
    //turning _wlaczone false
    virtual void wylacz();
    bool _wlaczone;
    Rozdzielczosc _res;
};
class Papierozerne : public Urzadzenie {
public:
    //constructor setting res
    Papierozerne(Rozdzielczosc);
    //destructor
    virtual ~Papierozerne();
    //turning _wlaczone true
    virtual void wlacz();
    //turning _wlaczone false
    virtual void wylacz();
    bool _wlaczone;
    Rozdzielczosc _res;
};
class Drukarka : public Papierozerne {
public:
    //constructor setting res
    Drukarka(Rozdzielczosc res);
    //destructor
    virtual ~Drukarka();
    //turning _wlaczone true
    virtual void wlacz();
    //turning _wlaczone false
    virtual void wylacz();
    bool _wlaczone;
    Rozdzielczosc _res;
};
class Ksero : public Papierozerne {
public:
    //constructor setting res
    Ksero(Rozdzielczosc res);
    //destructor
    virtual ~Ksero();
    //turning _wlaczone true
    virtual void wlacz();
    //turning _wlaczone false
    virtual void wylacz();
    bool _wlaczone;
    Rozdzielczosc _res;
};
//stworz klase Kserokopiarka, aby linijka 36 w main.cpp sie nie kompilowala ale 35 i 37 tak
class Kserokopiarka : public Ksero, public Drukarka {
public:
    //constructor setting res
    Kserokopiarka(Rozdzielczosc res);
    //destructor
    virtual ~Kserokopiarka();
    //turning _wlaczone true
    virtual void wlacz();
    //turning _wlaczone false
    virtual void wylacz();
    bool _wlaczone;
    Rozdzielczosc _res;
};

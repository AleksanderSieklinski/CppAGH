#include "Urzadzenia.h"
Rozdzielczosc::Rozdzielczosc(int x,int y): x_(x), y_(y) {}
int Rozdzielczosc::x() const { return x_; }
int Rozdzielczosc::y() const { return y_; }
Urzadzenie::Urzadzenie(Rozdzielczosc res) : _res(res) {
    std::cout<<"Urzadzenie "<<res.x()<<"x"<<res.y()<<std::endl;
 }
void Urzadzenie::wlacz(){
        if (_wlaczone) {
            std::cout << "Urzadzenie juz wlaczone" << std::endl;
        } else {
            _wlaczone = true;
            std::cout << "wlaczam urzadzenie" << std::endl;
        }
    }
void Urzadzenie::wylacz(){
        if (_wlaczone) {
            _wlaczone = false;
            std::cout << "wylaczam urzadzenie" << std::endl;
        } else {
            std::cout << "Urzadzenie juz wylaczone" << std::endl;
        }
    }
std::string Urzadzenie::rozdzielczosc() const{
        return std::to_string(_res.x())+"x"+std::to_string(_res.y());
    }
Skaner::Skaner(Rozdzielczosc res) : Urzadzenie(res), _res(Urzadzenie::_res) {
        std::cout<<"Skaner "<<res.x()<<"x"<<res.y()<<std::endl;
    }
void Skaner::wlacz(){
        if (_wlaczone) {
            std::cout << "Urzadzenie juz wlaczone" << std::endl;
        } else {
            _wlaczone = true;
            std::cout << "wlaczam skaner" << std::endl;
        }
    }
void Skaner::wylacz(){
        if (_wlaczone) {
            _wlaczone = false;
            std::cout << "wylaczam skaner" << std::endl;
        } else {
            std::cout << "Skaner juz wylaczony" << std::endl;
        }
    }
Papierozerne::Papierozerne(Rozdzielczosc res) : Urzadzenie(res), _res(Urzadzenie::_res) {
        std::cout<<"Papierozerne "<<res.x()<<"x"<<res.y()<<std::endl;
    }
void Papierozerne::wlacz(){
        if (_wlaczone) {
            std::cout << "Urzadzenie juz wlaczone" << std::endl;
        } else {
            _wlaczone = true;
            std::cout << "wlaczam paperozerne" << std::endl;
        }
    }
void Papierozerne::wylacz(){
        if (_wlaczone) {
            _wlaczone = false;
            std::cout << "wylaczam papierozerne" << std::endl;
        } else {
            std::cout << "Papierozerne juz wylaczony" << std::endl;
        }
    }
Ksero::Ksero(Rozdzielczosc res) : Papierozerne(res), _res(Urzadzenie::_res) {
        std::cout<<"Ksero"<<res.x()<<"x"<<res.y()<<std::endl;
    }
void Ksero::wlacz(){
        if (_wlaczone) {
            std::cout << "Urzadzenie juz wlaczone" << std::endl;
        } else {
            _wlaczone = true;
            std::cout << "wlaczam urzadzenie" << std::endl;
        }
    }
void Ksero::wylacz(){
        if (_wlaczone) {
            _wlaczone = false;
            std::cout << "wylaczam urzadzenie" << std::endl;
        } else {
            std::cout << "Urzadzenie juz wylaczone" << std::endl;
        }
    }
Drukarka::Drukarka(Rozdzielczosc res) : Papierozerne(res), _res(Urzadzenie::_res) {
        std::cout<<"Drukarka "<<res.x()<<"x"<<res.y()<<std::endl;
    }
void Drukarka::wlacz(){
        if (_wlaczone) {
            std::cout << "Urzadzenie juz wlaczone" << std::endl;
        } else {
            _wlaczone = true;
            std::cout << "wlaczam urzadzenie" << std::endl;
        }
    }
void Drukarka::wylacz(){
        if (_wlaczone) {
            _wlaczone = false;
            std::cout << "wylaczam urzadzenie" << std::endl;
        } else {
            std::cout << "Urzadzenie juz wylaczona" << std::endl;
        }
    }
Urzadzenie::~Urzadzenie() {
    std::cout<<"~Urzadzenie"<<std::endl;
}
Skaner::~Skaner() {
    std::cout<<"~Skaner"<<std::endl;
}
Papierozerne::~Papierozerne() {
    std::cout<<"~Papierozerne"<<std::endl;
}
Drukarka::~Drukarka() {
    std::cout<<"~Drukarka"<<std::endl;
}
Ksero::~Ksero() {
    std::cout<<"~Ksero"<<std::endl;
}
Kserokopiarka::Kserokopiarka(Rozdzielczosc res) : Ksero(res), Drukarka(res), _res(Ksero::_res) {
        std::cout<<"Kserokopiarka "<<res.x()<<"x"<<res.y()<<std::endl;
    }
void Kserokopiarka::wlacz(){
        if (_wlaczone) {
            std::cout << "Urzadzenie juz wlaczone" << std::endl;
        } else {
            _wlaczone = true;
            std::cout << "wlaczam urzadzenie" << std::endl;
        }
    }
void Kserokopiarka::wylacz(){
        if (_wlaczone) {
            _wlaczone = false;
            std::cout << "wylaczam urzadzenie" << std::endl;
        } else {
            std::cout << "Urzadzenie juz wylaczone" << std::endl;
        }
    }
Kserokopiarka::~Kserokopiarka() {
    std::cout<<"~Kserokopiarka"<<std::endl;
}

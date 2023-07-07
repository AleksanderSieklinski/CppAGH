#include "Animals.h"

void Sheep::print() const {
    std::cout << "- Owca " << name() << " " << (_sheared ? "ostrzyzona" : "nieostrzyzona") << std::endl;
}

Sheep::~Sheep() {
    std::cout << "- Owca " << name() <<(_sheared ? " ostrzyzona" : " nieostrzyzona")<< " wraca do zagrody"<< std::endl;
}

void Cow::print() const {
    std::cout << "- Krowa " << name() << std::endl;
}

Cow::~Cow() {
    std::cout << "- Krowa " << name() <<" wraca do obory"<< std::endl;
}

void Horse::print() const {
    std::cout << "- Kon " << name() << std::endl;
}

Horse::~Horse() {
    std::cout << "- Kon " << name() <<" wraca do stajni"<< std::endl;
}
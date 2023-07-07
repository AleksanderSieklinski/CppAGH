#include "Meadow.h"
void Meadow::add(std::unique_ptr<GeneralAnimal> animal) {
    _animals.push_back(std::move(animal));
}

void Meadow::print(const std::string &title) const {
    std::cout << "=== " << title << " ===" << std::endl;
    for (const auto &v: _animals) {
        v->print();
    }
}

void Meadow::countNames() const {
    std::map<std::string,int> names;
    for (const auto &v: _animals) {
        names[v->name()]++;
    }
    for (const auto &v: names) {
        std::cout << v.first << ": " << v.second << std::endl;
    }
}

std::vector<Sheep*> Meadow::getSheepHerd() const {
    std::vector<Sheep*> herd;
    for (const auto &v: _animals) {
        Sheep *s = dynamic_cast<Sheep*>(v.get());
        if (s) {
            herd.push_back(s);
        }
    }
    return herd;
}
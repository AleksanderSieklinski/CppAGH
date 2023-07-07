#include "Symlink.h"

Symlink::Symlink(std::string name, File* file) : File(name), file(file) {}

void Symlink::print(int level) const {
    for (int i = 0; i < level; ++i) {
        std::cout << "__";
    }
    std::cout << name << " -> ";
    file->print();
}

File* Symlink::operator->() const {
    return file;
}

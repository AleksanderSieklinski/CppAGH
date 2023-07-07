#include "Team.h"

void Team::add(const Member& m) {
    if (std::find_if(members.begin(), members.end(), [&](const Member& m2) { return m2.getName() == m.getName(); }) == members.end()) {
        members.push_back(m);
    }
    std::sort(members.begin(), members.end(), [&](const Member& m1, const Member& m2) { return m1.getName() < m2.getName(); });
}

void Team::kill(std::function<bool(const Member&)> f) {
    members.erase(std::remove_if(members.begin(), members.end(), f), members.end());
}

std::ostream& operator<<(std::ostream& o, const Team& t) {
    std::for_each(t.members.begin(), t.members.end(), [&](const Member& m) { o << m.getName() << " power:" << m.power() << " magic:" << m.magic() << " health:" << m.health() << std::endl; });
    return o;
}

Team& Team::operator+(const Team& t) {
    std::for_each(t.members.begin(), t.members.end(), [&](const Member& m) { add(m); });
    return *this;
}
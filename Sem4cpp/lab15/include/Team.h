#include "Member.h"

class Team {
public:
    //function to add a member to a team
    void add(const Member&);
    //function to remove a member from a team
    void kill(std::function<bool(const Member&)>);
    //function to print the members of a team
    friend std::ostream& operator<<(std::ostream&, const Team&);
    //function to add two teams together
    Team& operator+(const Team&);
private:
    std::vector<Member> members;
};
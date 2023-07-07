#include "GameObj.h"

std::ostream& operator<<(std::ostream& o, const GameObj& m) {
    if (m.GetName()=="Wario") {
        o<<"Bad guy: "<<m.GetName()<<", ma: ["<<m.GetHP()<<" HP]"<<std::endl<<"Jego uderzenie odbiera: ["<<m.GetDamage()<<" HP]";
    }
    else if(m.GetName()!="") {
        o<<"Player "<<m.GetName()<<", ma: ["<<m.GetHP()<<" HP]";
    }
    else{
        o<<m.GetName()<<"Jego uderzenie odbiera: ["<<m.GetHP()<<" HP]";
    }
    return o;
}

#pragma once
#include <iostream>
#include <string>
class HP{
    public:
    //constructor setting hp or damage 
    HP(int health,int damage=0) :_health(health),_damage(damage){}
    HP(){}
    virtual ~HP(){}
    //function returning the amount of health
    int GetHP()const {return _health;}
    int GetDamage()const {return _damage;}
    protected:
    int _health;
    int _damage;
};

class GameObj : public HP {
    public:
    //constructor setting all values of any game object
    GameObj(std::string pid,HP hp,std::string charname="",int damage=0):_id(pid),HP(hp.GetHP(),damage),_charname(charname){}
    GameObj(){}
    //function returning the name of a character
    std::string GetName() const {return _charname;}
    //function returning the id of an object
    std::string id() const{return _id;}
    //function returning the hp of an object
    int hp() const {return _health;}
    protected:
    std::string _id,_charname;
};

class Character: virtual public GameObj {
    public:
    //constructor of a Character using GameObj constructor
    Character(GameObj gobj):GameObj(gobj){}
};
class Player :public Character{
    public:
    //constructor of a Player using Character constructor because its one of the characters
    Player(HP hp,std::string charname, std::string pid):Character(GameObj(pid,hp,charname)),GameObj(pid,hp,charname){}
};
class Hurting: virtual public GameObj {
    public:
    //constructor of Hurting using GameObj constructor
    Hurting(HP hp,std::string pid): GameObj(pid,hp){}
};
class Bomb: public Hurting {
    public:
    //constructor of a Bomb using Hurting constructor because it deals damage
    Bomb(HP hp,std::string pid):Hurting(hp,pid),GameObj(pid,hp){}
};
class Boss: public Character,public Hurting{
    public:
    //constructor of a Boss using both Character and Hurting constructors because it deals damage and is a character
    Boss(HP hp, std::string charname,HP hp1,std::string id):Character(GameObj(id,hp,charname,hp1.GetHP())),Hurting(hp1,id),GameObj(id,hp,charname,hp1.GetHP()){}
};
//overloaded ostream operator returning key parameters of a given object
std::ostream& operator<<(std::ostream& o, const GameObj& m);
// Przed wirtualnym dziedziczeniem wartosci ID, hp oraz nazwy sa wypisywane poprawnie! :D
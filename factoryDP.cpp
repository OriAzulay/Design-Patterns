#include <unordered_map>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;






class Weapon{
    public:
    virtual void weaponType()=0;
};

class SledgeHammer:public Weapon{
    public:
    virtual void weaponType(){
        cout << "you got hammered"<<endl;
    }
};

class Bow:public Weapon{
    public:
    virtual void weaponType(){
        cout<<"you got an arrow in the knee"<<endl;
    }
};

class Creator
{
public:
    virtual Weapon* create() = 0;
};

class HammerCreator:public Creator{
    virtual Weapon* create(){
        return new SledgeHammer();
    }
};

class BowCreator:public Creator{
    virtual Weapon *create(){
        return new Bow();
    }
};

class weaponFactory{
    unordered_map<string, Creator *> weapons;
    public:
    weaponFactory(){
        weapons["Bow"] = new BowCreator();
        weapons["Hammer"] = new HammerCreator();
    }
    Weapon* createWeapon(string name){
        Creator* c = weapons[name];
        if (c != nullptr)
            return c->create();
        return nullptr;
    }
};

// int main(){
//     weaponFactory* f = new weaponFactory();
//     bool b = true;
//     int i;
//     string m;
//     while(b){
//     cout<<"Choose your weapon: \n 1.Hammer\n 2.Bow \n 3.out"<<endl;
//     cin>>i;
//     switch (i)
//     {
//     case 1:
//         m = "Hammer";
//         break;
//     case 2:
//         m = "Bow";
//         break;
//     case 3:
//         b = false;
//     }
//     Weapon* x = f->createWeapon(m);
//     x->weaponType();
//     }
//     return 0;
//     }

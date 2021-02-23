#include <unordered_map>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;






class Missle{
    public:
    virtual void missleType()=0;
};

class Explosion:public Missle{
    public:
    virtual void missleType(){
        cout << "The missle impact near the target! "<<endl;
    }
};

class HeadOn:public Missle{
    public:
    virtual void missleType(){
        cout<<"The missle impact Head-On!"<<endl;
    }
};

class Creator
{
public:
    virtual Missle* create() = 0;
};

class ExplosionCreator:public Creator{
    virtual Missle* create(){
        return new Explosion();
    }
};

class HeadOnCreator:public Creator{
    virtual Missle* create(){
        return new HeadOn();
    }
};

class missleFactory{
    unordered_map<string, Creator *> missles;
    public:
    missleFactory(){
        missles["head-on"] = new HeadOnCreator();
        missles["explosion"] = new ExplosionCreator();
    }
    Missle* createMissle(string name){
        Creator* c = missles[name];
        if (c != nullptr)
            return c->create();
        return nullptr;
    }
};

// int main(){
//    missleFactory* f = new missleFactory();
//     bool b = true;
//     int i;
//     string m;
//     while(b){
//     cout<<"Choose your type of impact: \n 1.Explosion\n 2.Head-on \n 3.out"<<endl;
//     cin>>i;
//     switch (i)
//     {
//     case 1:
//         m = "head-on";
//         break;
//     case 2:
//         m = "explosion";
//         break;
//     case 3:
//         b = false;
//     }
//     missles* x = f->createMissle(m);
//     x->weaponType();
//     }
//     return 0;
//     }

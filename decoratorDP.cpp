
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


class Pizza{
    public:
    virtual string getDescription()=0;
};

class personalPizza : public Pizza{
    string getDescription(){
        return "This is a personal pizza ";
    }
};

class familyPizza : public Pizza{
    string getDescription(){
        return "This is a family pizza ";
    }
};
//++++++++++++++++++++++++++++++++++++++++++++++++

class Decorator : public Pizza{
protected:
    Pizza* _pizza;
public:
    virtual string getDescription()=0;
};

class MushroomTop: public Decorator{
    public:
    MushroomTop(Pizza* p){
        _pizza = p;
    }
    string getDescription(){
        return _pizza->getDescription() + ",Mushroom on top ";
    }
};

class MozzarellaTop: public Decorator{
    public:
    MozzarellaTop(Pizza* p){
        _pizza = p;
    }
    string getDescription(){
        return _pizza->getDescription() + ",Mozzarella on top ";
    }
};


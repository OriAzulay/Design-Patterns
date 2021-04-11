#include <stdio.h>
#include <iostream>

using namespace std;
// Implementaions********************************//
class HouseImp{
    public:
    virtual void BuildHouse()=0;
};

class StrawHouse: public HouseImp{
    public:
    virtual void BuildHouse(){
        cout<<"This is a Straw House"<<endl;
    }
};
class WoodHouse: public HouseImp{
    public:
    virtual void BuildHouse(){
        cout<<"This is a wood House"<<endl;
    }
};

//********************************************************//
class HouseType{
    public:
    HouseImp* implemention;
    HouseType(HouseImp* imp){
        implemention = imp;
    }
    virtual void BuildHouse()=0;
};
class BigHouse:public HouseType{
    public:
    BigHouse(HouseImp* h):HouseType(h){
    }
    virtual void BuildHouse(){
        cout<<"This is a big house"<<endl;
        implemention->BuildHouse();
    }
};

class SmallHouse:public HouseType{
    public:
    SmallHouse(HouseImp* h):HouseType(h){
    }
    virtual void BuildHouse(){
        cout<<"This is a Small house"<<endl;
        implemention->BuildHouse();
    }
    
};

/**
int main(){
    HouseType* a = new BigHouse(new StrawHouse());
    a->BuildHouse();
    HouseType* b = new RoundHouse(new WoodHouse());
    b->BuildHouse();
    return 0;
};
 */



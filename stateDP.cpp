#include <iostream>
#include <cstring>

using namespace std;

class health{
    public:
    virtual void state()=0;
};

class healthy : public health{
    public:
    virtual void state(){
        cout<<"The robot is healthy"<<endl;
    }
};

class faulty : public health{
    public:
    virtual void state(){
        cout<<"The robot is faulty"<<endl;
    }
};

class CareRobot{
    public:
    health* h;
    void  setState(string s){
        if (s == "healthy")
            h = new healthy;
        else
            h = new faulty;
    }
    void getState(){
        h->state();
    }
};

// int main() {
//     CareRobot* r = new CareRobot();
//     r->setState("healthy");
//     r->getState();
//     r->setState("faulty");
//     r->getState();
//     return 0;
// }
/**
 * @file adapterDP.cpp
 * @author Ori Azulay 
 * @brief  Adapter design pattern is meant to adapt object from one property to another.
 * @version 0.1
 * @date 2021-04-11
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <iostream>

using namespace std;

class UStudent{
    public:
    void learning();
    virtual string getName()=0;
};

class Employee{
    public:
    void working();
    virtual string getName()=0;

};

class youngPerson : public UStudent{
    string sname;
    public:
    youngPerson(string n):sname(n){};   
     void learning(){
        cout<<"This person is learning"<<endl;
    }
    virtual string getName(){return sname;}
};

class oldPerson: public Employee{
    string name;
    public:
    oldPerson(string n):name(n){};
    void working(){
        cout<<"This person is working"<<endl;
    }
    string getName(){return name;}

};

class fromStudent2Employee : Employee{ //adapter
    public:
    UStudent* em;
    string usname;
    fromStudent2Employee(UStudent* e):em(e){
        usname = e->getName();
    }; 
    void working(){
        cout<<usname + " is also working"<<endl;
    }
    string getName(){return usname;}
};

/**Main:
 int main(){
    youngPerson* yp = new youngPerson("Ori");
    oldPerson* op = new oldPerson("Azulay");
    yp->learning();
    op->working();
    //adaption
    fromStudent2Employee* adapt = new fromStudent2Employee(yp);
    adapt->working();
    return 0;
};
 */




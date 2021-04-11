#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

class Worker{
    public:
    string name;
    int age;
    list<Worker*> workerList;
    Worker(string a):name(a){}
    virtual void operation(){};
    virtual void getChild(){};
    void Add(Worker *c) {
        workerList.push_back(c);
    };
    void Remove(Worker *c) {
        workerList.remove(c);
    };
};

class Manager : public Worker {
public:
    string ManagerName;
    Manager(string s) : Worker(s) {ManagerName=s;}
    void operation() override {
        cout << "Composite" << endl;
    }
    void getChild(){
        cout<< " The manager: " + ManagerName + " Has The workers: "<<endl;
        for (auto c : this->workerList){
            c->getChild();
        }
    }

};

//+++++++++++++++++++++++++++++++++++++++++
class Enginerr : public Worker{
    public:
    Enginerr(string n):Worker(n){}
    void operation() override{
        cout<<"Leaf"<<endl;
    }
    void getChild()override{
        cout<<"Engineer name: " + this->name<<endl;
    }
};

class Architect : public Worker{
    public:
    Architect(string n):Worker(n){}
    void operation() override{
        cout<<"Leaf"<<endl;
    }
    void getChild()override{
        cout<<"Architect name: " + this->name<<endl;
    }
};
//+++++++++++++++++++++++++++++++++++++++++++


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

/**
int main(){
   Worker *c = new Manager("Haim");
   Worker *c1 = new Manager("Omer");
   Worker *c2 = new Manager("Yoav");
   Worker *l = new Enginerr("Liran");
   Worker *l1 = new Enginerr("Elad");
   Worker *l2 = new Architect("Amir");
   c->Add(c1);
   c->Add(c2);
   c1->Add(l);
   c1->Add(l1);
   c2->Add(l1);
   c->getChild();
   return 0;
}
**/

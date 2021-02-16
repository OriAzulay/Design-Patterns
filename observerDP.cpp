//
// Created by tomer on 15-Feb-21.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Observer {
public:
    virtual void update(const char *course) = 0;
};

class Subject {
protected:
    vector<Observer *> observers;
public:
    void AddObserver(Observer *observer) {
        observers.push_back(observer);
    }

    void Detach(Observer *observer) {
        for (auto o : observers)
            if (o == observer)
                observer = nullptr;
    }

    virtual void Notify(const char* course) {
        for (auto o : observers)
            if (o != nullptr)
                o->update(course);
    }
};
class RADAR:public Subject{
bool threat;
public:
RADAR(){
    threat = false;
}
void setThreat(int x){
    threat = true;
    if (x==1)
        Notify("Missle");
    else if(x==2)
        Notify("Aircraft");
    
}

};
class MissleDefence: public Observer{
ControllPanel* ctrl;
public:
MissleDefence(ControllPanel* c):ctrl(c){}
void update(const char* o){
    if(strcmp("Missle",o)){
        cout<<"Iron doom missle is shooting the target"<<endl;
    }
}
};

class AircraftDefence: public Observer{
ControllPanel* ctrl;
public:
AircraftDefence(ControllPanel* c):ctrl(c){}
void update(const char* o){
    if(strcmp("Aircraft",o)){
        cout<<"PATRIOT launchers are ready to fire! "<<endl;
    }
}
};

// int main(){
//     RADAR* ctrl = new RADAR();
//     AircraftDefence* a = new AircraftDefence(ctrl);
//     MissleDefence* m = new MissleDefence(ctrl);
//     ctrl->AddObserver(a);
//     ctrl->AddObserver(m);
//     int threat;
//     while(threat != 0){
//       cout<<"Choose your radar threat:\n 1.Aircraft\n 2.Missles\n 3.out\n";
//       cin>>threat;
//       ctrl->setThreat(threat);
//     }
//    return 0;
// }

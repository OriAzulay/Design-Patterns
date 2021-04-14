#include <unordered_map>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

class Character {
protected:
    int health;
public:
    Character() { health = 0; }

    void setHealth(int h) {
        health = health;
    }

    int getHealth() const {
        return health;
    }

    virtual void print(int i, int j) = 0;
};

class Soldier : public Character {
public:
    Soldier(int h) {
        health = h;
    }

    void print(int i, int j) override {
        cout << "soldier=" << this << " is at [" << i << ", " << j << "] with health=" << health << endl;
    }
};

class ArielLauncher : public Character {
public:
    ArielLauncher(int h) {
        health = h;
    }

    void print(int i, int j) override {
        cout << "Launcher=" << this << " is at [" << i << ", " << j << "] with health=" << health << endl;
    }
};

class flyweight{
    protected:
    vector<Character*> c;
    virtual Character* newCharacter(int h)=0;
    public:
    Character* getCharacter(int h){
        int i;
        for (i=0; i<c.size(); i++){
            if(c.at(i)->getHealth() == h)
                return c.at(i); 
        }
        c.push_back(newCharacter(h));
        return c.at(i);
    }
};

class SoldierFlyweight:public flyweight{
    Character *newCharacter(int h) override {
        return new Soldier(h);
    }
};

class LauncherFlyweight:public flyweight{
    Character *newCharacter(int h) override {
        return new ArielLauncher(h);
    }
};



// int main() {
//     Character *table[4][4];
//     for (int i = 0; i < 4; ++i) {
//         for (int j = 0; j < 4; ++j) {
//             table[i][j] = nullptr;
//         }
//     }
//     Flyweight *soldierFlyweight = new SoldierFlyweight();
//     Flyweight *LauncherFlyweight = new LauncherFlyweight();
//     table[0][0] = soldierFlyweight->getCharacter(100);
//     table[1][0] = soldierFlyweight->getCharacter(100);
//     table[0][2] = LauncherFlyweight->getCharacter(50);
//     table[1][2] = LauncherFlyweight->getCharacter(50);
//     table[1][3] = LauncherFlyweight->getCharacter(50);
//     for (int i = 0; i < 4; ++i) {
//         for (int j = 0; j < 4; ++j) {
//             if (table[i][j])
//                 table[i][j]->print(i, j);
//         }
//     }
//     cout << "A tank was hit: Tank [1,2] health=10" << endl;
//     table[1][2] = tankFlyweight->getCharacter(10);
//     cout << "After change:" << endl;
//     for (int i = 0; i < 4; ++i) {
//         for (int j = 0; j < 4; ++j) {
//             if (table[i][j])
//                 table[i][j]->print(i, j);
//         }
//     }
// }
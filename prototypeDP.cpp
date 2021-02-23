#include <iostream>
#include <list>
#include <iterator> 
using namespace std;

class Branch{
public:
virtual Branch* clone(){
    Branch* shape = new Branch();
    return shape;
}
virtual void getDescription(){};
};

class PetachTikva:public Branch{
int x;
int y;
int width;
int height;
public:
virtual Branch* clone(){
    Branch* Rshape = new PetachTikva();
    return Rshape;
}
virtual void getDescription(){cout<<"PetachTikva\n";};
};
class RamatGan:public Branch{
int raduis;
int centerX;
int centerY;
public:
virtual Branch* clone(){
    Branch* Cshape = new RamatGan();
    return Cshape;
}
virtual void getDescription(){cout<<"RamatGan\n";};

};
class TelAviv:public Branch{
public:
virtual Branch* clone(){
    Branch* Tshape = new TelAviv();
    return Tshape;
}
virtual void getDescription(){cout<<"TelAviv\n";};

};

class BranchHolder{
list<Branch*> Alist;
public:
void addAcopy(Branch* s){
    Alist.push_back(s->clone());
}

list<Branch*> getList(){
return Alist;
}
};

// template<class iterator, class func>
// void forEach(iterator begin, iterator end, func c){
//     while(begin != end){
//         c(*begin);
//         begin++;
//     }
// }
// int main(){

// Branch* e = new Rectangle; // user choose shape
// Branch* d = new RamatGan; // user choose shape

// BranchHolder* s = new BranchHolder;
// s->addAcopy(e);
// s->addAcopy(d);
// cout<<"size of list:"<<s->getList().size()<<endl;Branch* l){l->getDescription();});

//    return 0;
// }
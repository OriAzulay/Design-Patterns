#include <iostream>
#include <list>
#include <iterator> 
using namespace std;

class Shape{
public:
virtual Shape* clone(){
    Shape* shape = new Shape();
    return shape;
}
virtual void getDescription(){};
};

class Rectangle:public Shape{
int x;
int y;
int width;
int height;
public:
virtual Shape* clone(){
    Shape* Rshape = new Rectangle();
    return Rshape;
}
virtual void getDescription(){cout<<"Rectangle\n";};
};
class Circle:public Shape{
int raduis;
int centerX;
int centerY;
public:
virtual Shape* clone(){
    Shape* Cshape = new Circle();
    return Cshape;
}
virtual void getDescription(){cout<<"Circle\n";};

};
class Triangle:public Shape{
public:
virtual Shape* clone(){
    Shape* Tshape = new Triangle();
    return Tshape;
}
virtual void getDescription(){cout<<"Triangle\n";};

};

class ShapeHolder{
list<Shape*> Alist;
public:
void addAcopy(Shape* s){
    Alist.push_back(s->clone());
}

list<Shape*> getList(){
return Alist;
}
};

// int main(){

// Shape* e = new Rectangle; // user choose shape
// Shape* d = new Circle; // user choose shape

// ShapeHolder* s = new ShapeHolder;
// s->addAcopy(e);
// s->addAcopy(d);
// cout<<"size of list:"<<s->getList().size()<<endl;
// forEach(s->getList().begin(),s->getList().end(), [](Shape* l){l->getDescription();});

//    return 0;
// }
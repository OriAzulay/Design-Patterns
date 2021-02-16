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
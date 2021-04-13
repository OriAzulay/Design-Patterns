
#include <iostream>

using namespace std;

class Abstract{

public:
virtual int evaluate()=0;
virtual string show()=0;
};

class BinaryExpresion:public Abstract{
    protected:
    Abstract* left;
    Abstract* right;
    BinaryExpresion(Abstract* left, Abstract* right):left(left), right(right){}
};

class leafNode : public Abstract{
    virtual int evaluate()=0;
    virtual string show()=0;        
};

class Num:public leafNode{
int n;
public:
    Num(float x):n(x){}
    string show()override{return to_string(n);}
    int evaluate()override{return n;}
};
class EXpress:public Abstract{
string n;
public:
    EXpress(string x):n(x){}
    string show()override{return n;}
    int evaluate()override{return 0;}
    
};

class Plus: public BinaryExpresion{
public:
Plus(Abstract* left, Abstract* right):BinaryExpresion(left,right){}
 string show()override{
    return ("("+ left->show() + " + " + right->show() + ")");
}
 int evaluate()override{
    return (left->evaluate() + right->evaluate());
}
};

class Minus: public BinaryExpresion{
public:
Minus(Abstract* left, Abstract* right):BinaryExpresion(left,right){}
string show()override{
    return ("("+ left->show() + " - " + right->show() + ")");
}
 int evaluate()override{
    return (left->evaluate() - right->evaluate());
}
};

class Mult: public BinaryExpresion{
public:
Mult(Abstract* left, Abstract* right):BinaryExpresion(left,right){}
string show()override{
    return ("(" + left->show() + "*" + right->show() + ")");
}
int evaluate()override{
    return (left->evaluate() * right->evaluate());
}
};

// int main() {
//     Abstract* expression = new Plus(new Num(1), new Num(2));
//     cout<<expression->show()<<"= "<<expression->evaluate()<<endl;
//     Abstract* ex2 = new Mult(new Plus(new Num(1), new Num(1)), new Num(3));
//     cout<<ex2->show()<<"= "<<ex2->evaluate()<<endl;
//     Abstract* ex3 = new Plus(new Num(2), new EXpress("X"));
//     cout<<ex3->show()<<endl;
//     return 0;
// };
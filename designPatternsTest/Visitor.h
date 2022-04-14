#ifndef VISITOR_H
#define VISITOR_H
#include <iostream>
#include <vector>
using namespace std;

class ElementA;
class ElementB;

class Visitor{
public:
    virtual ~Visitor(){}
    virtual void visitElementA(ElementA& element) = 0;
    virtual void visitElementB(ElementB& element) = 0;
};

class Element
{
public:
    virtual ~Element(){}
    virtual void accept(Visitor* visitor) = 0; //第一次多态辨析
};

class ElementA : public Element
{
public:
    ~ElementA(){}
    void accept(Visitor *visitor){
        visitor->visitElementA(*this);
    }
};

class ElementB : public Element
{
public:
    ~ElementB(){}
    void accept(Visitor *visitor){
        visitor->visitElementB(*this); //第二次多态辨析
    }
};

//==================================
//扩展1
class Visitor1 : public Visitor{
public:
    virtual ~Visitor1(){}
    void visitElementA(ElementA& element) override{
        cout << "Visitor1:"<<this<<" is processing ElementA:" <<&element<< endl;
    }

    void visitElementB(ElementB& element) override{
        cout << "Visitor1:"<<this<<" is processing ElementB:" <<&element<< endl;
    }
};

//扩展2
class Visitor2 : public Visitor{
public:
    virtual ~Visitor2(){}
    void visitElementA(ElementA& element) override{
        cout << "Visitor2:"<<this<<" is processing ElementA:" <<&element<< endl;
    }

    void visitElementB(ElementB& element) override{
        cout << "Visitor2:"<<this<<" is processing ElementB:" <<&element<< endl;
    }
};


#endif // VISITOR_H

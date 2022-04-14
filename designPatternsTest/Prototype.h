#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
using namespace std;

class Prototype
{
public:
    Prototype(){}
    virtual ~Prototype(){}
    virtual Prototype* Clone() = 0;
    virtual string getSelfName() = 0;
};

class ConcreatePrototype1 : public Prototype
{
public:
    ConcreatePrototype1(){}
    ConcreatePrototype1(const ConcreatePrototype1&){
        cout<<"ConcreatePrototype1进行了拷贝"<<endl;
    }
    virtual ~ConcreatePrototype1(){}
    virtual Prototype* Clone(){
        return new ConcreatePrototype1(*this);
    }
    virtual string getSelfName(){
        return "ConcreatePrototype1";
    }
};

class ConcreatePrototype2 : public Prototype
{
public:
    ConcreatePrototype2(){}
    ConcreatePrototype2(const ConcreatePrototype2&){
        cout<<"ConcreatePrototype2进行了拷贝"<<endl;
    }
    virtual ~ConcreatePrototype2(){}
    virtual Prototype* Clone(){
        return new ConcreatePrototype2(*this);
    }
    virtual string getSelfName(){
        return "ConcreatePrototype2";
    }
};
class PrototypeWindows
{
public:
    PrototypeWindows(Prototype *prototype){
        m_prototype = prototype;
    }
    ~PrototypeWindows(){
        m_prototype = NULL;
    }
    void Prototypeclick(){
        Prototype *pPrototype = m_prototype->Clone();
        cout<<pPrototype->getSelfName()<<"对象使用中"<<endl;
    }
protected:
    Prototype *m_prototype = NULL;
};


#endif // PROTOTYPE_H

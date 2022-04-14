#ifndef ABSTRACFACTORY_H
#define ABSTRACFACTORY_H

#include <iostream>
using namespace std;

class AbstractProductA
{
public:
    AbstractProductA() {}
    virtual ~AbstractProductA(){};
};
// 派生类ConcreateProductA1,继承自AbstractProductA,代表产品A 的第一种实现
class ConcreateProductA1 : public AbstractProductA
{
public:
    ConcreateProductA1(){
        cout<<"产品A 的第一种实现"<<endl;
    }
    virtual ~ConcreateProductA1(){}
};
// 派生类ConcreateProductA2,继承自AbstractProductA,代表产品A 的第二种实现
class ConcreateProductA2: public AbstractProductA
{
public:
    ConcreateProductA2(){
        cout<<"产品A 的第二种实现"<<endl;
    }
 virtual ~ConcreateProductA2(){}
};
// 抽象基类AbstractProductB,代表产品B 的抽象
class AbstractProductB
{
public:
    AbstractProductB() {}
    virtual ~AbstractProductB(){};
};
// 派生类ConcreateProductB1,继承自AbstractProductB,代表产品B 的第一种实现
class ConcreateProductB1 : public AbstractProductB
{
public:
    ConcreateProductB1(){
        cout<<"产品B 的第一种实现"<<endl;
    }

    virtual ~ConcreateProductB1(){}
};
// 派生类ConcreateProductB2,继承自AbstractProductB,代表产品B 的第二种实现
class ConcreateProductB2 : public AbstractProductB
{
public:
    ConcreateProductB2(){
        cout<<"产品B 的第二种实现"<<endl;
    }
    virtual ~ConcreateProductB2(){}
};
// 抽象基类AbstractFactory,工厂的抽象类,生产产品A 和产品B
class AbstractFactory
{
public:
    AbstractFactory(){}
    virtual ~AbstractFactory(){}
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
};
// 派生类ConcreateFactory1,继承自AbstractFactory
// 生产产品A 和产品B 的第一种实现
class ConcreateFactory1 : public AbstractFactory
{
public:
    ConcreateFactory1(){}
    virtual ~ConcreateFactory1(){}
    virtual AbstractProductA* CreateProductA(){
        return new ConcreateProductA1();
    }
    virtual AbstractProductB* CreateProductB(){
        return new ConcreateProductB1();
    }
};
// 派生类ConcreateFactory2,继承自AbstractFactory
// 生产产品A 和产品B 的第二种实现
class ConcreateFactory2: public AbstractFactory
{
public:
    ConcreateFactory2(){}
    virtual ~ConcreateFactory2(){}
    virtual AbstractProductA* CreateProductA(){
        return new ConcreateProductA2();
    }
    virtual AbstractProductB* CreateProductB(){
        return new ConcreateProductB2();
    }
};


#endif // ABSTRACFACTORY_H

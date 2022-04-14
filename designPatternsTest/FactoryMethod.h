#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H
#include <iostream>
using namespace std;
//产品基类
class Product
{
public:
    Product(){}
    virtual ~Product(){}
    virtual string getSelfName() = 0;
};
//工厂基类
class Factory : public Product
{
public:
    virtual ~Factory(){};
    virtual Product* getFactory() = 0;
    virtual string getSelfName() = 0;
};
//产品实例
class PCProduct : public Product
{
public:
    PCProduct(){
        cout<<"PCProduct创建"<<endl;
    }
    virtual ~PCProduct(){}
    virtual string getSelfName(){
        return "PCProduct";
    }
};
class MobileProduct : public Product
{
public:
    MobileProduct(){
        cout<<"MobileProduct创建"<<endl;
    }
    virtual ~MobileProduct(){}
    virtual string getSelfName(){
        return "MobileProduct";
    }
};
//具体工厂
class PCProductFactory : public Factory
{
public:
    virtual ~PCProductFactory(){}
    virtual Product* getFactory(){
        return new PCProduct();
    }
    virtual string getSelfName(){
        return "PCProductFactory";
    }
};
class MobileProductFactory : public Factory
{
public:
    virtual ~MobileProductFactory(){}
    virtual Product* getFactory(){
        return new MobileProduct();
    }
    virtual string getSelfName(){
        return "MobileProductFactory";
    }
};

//
class FactoryWindows
{
public:
    FactoryWindows(Factory *factory){
        m_factory = factory;
    }
    ~FactoryWindows(){
        m_factory = NULL;
    }
    void Productclick(){
        Product *pProduct = m_factory->getFactory();
        cout<<pProduct->getSelfName()<<"对象使用中"<<endl;
    }
protected:
    Factory *m_factory = NULL;
};







#endif // FACTORYMETHOD_H

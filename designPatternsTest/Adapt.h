#ifndef ADAPT_H
#define ADAPT_H
#include <iostream>
using namespace std;


//目标接口(新接口)
class ITarget
{
public:
    virtual ~ITarget(){}
    virtual void process( )=0;
};
//遗留接口（老接口)
class IAdaptee
{
public:
    virtual ~IAdaptee(){}
    virtual void foo( int data)=0;
    virtual int bar( )=0;
};
class Adapter: public ITarget
{
public:
    Adapter(IAdaptee* pAdaptee){
        m_pAdaptee = pAdaptee;
    }
    virtual ~Adapter(){
        m_pAdaptee = NULL;
    }
    virtual void process ( ){
        int data=m_pAdaptee->bar( );
        m_pAdaptee->foo(data);
    }
protected:
    IAdaptee* m_pAdaptee = NULL;
};
class OldIAdaptee : public IAdaptee
{
public:
    virtual ~OldIAdaptee(){}
    virtual void foo(int data){
        cout<<"旧接口的foo():"<<data<<endl;
    }
    virtual int bar(){
        cout<<"旧接口的bar():"<<endl;
        return 0;
    }
};




#endif // ADAPT_H

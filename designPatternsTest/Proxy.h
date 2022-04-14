#ifndef PROXY_H
#define PROXY_H
#include <iostream>
using namespace std;

// 定义了Proxy 和RealSubject 的公有接口,
// 这样就可以在任何需要使用到RealSubject 的地方都使用Proxy.
class ProxySubject
{
public:
    ProxySubject(){}
    virtual ~ProxySubject(){}
    virtual void Request() = 0;
};
// 真正使用的实体
class RealSubject : public ProxySubject
{
public:
    RealSubject(){}
    virtual ~RealSubject(){}
    virtual void Request(){
         cout<<"RealSubject运行中"<<endl;
    }
};
// 代理类,含有一个指向RealSubject 对象的指针
class Proxy : public ProxySubject
{
public:
    Proxy(){
        m_pProxySubject = new RealSubject();
    }
    virtual ~Proxy(){
        delete m_pProxySubject;
        m_pProxySubject = NULL;
    }
    virtual void Request(){
        cout<<"Proxy代理访问RealSubject"<<endl;
        m_pProxySubject->Request();
    }
private:
    ProxySubject* m_pProxySubject = NULL;
};


#endif // PROXY_H

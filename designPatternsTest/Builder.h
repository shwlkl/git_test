#ifndef BUILDER_H
#define BUILDER_H
#include <iostream>
using namespace std;

//  虚拟基类,是所有Builder 的基类,提供不同部分的构建接口函数
class  Builder
{
public :
    Builder() {} ;
    virtual   ~ Builder() {}
    //  纯虚函数,提供构建不同部分的构建接口函数
    virtual string getSelfName() = 0;
    virtual int step1()=0;
    virtual int step2()=0;
    virtual int step3()=0;
    virtual int step4()=0;
    virtual int step5()=0;
protected:
    int m_a = 0,m_b = 0,m_c = 0,m_d = 0,m_e = 0;
};
//  使用Builder 构建产品,构建产品的过程都一致,但是不同的builder 有不同的实现
//  这个不同的实现通过不同的Builder 派生类来实现,存有一个Builder 的指针,通过这个来 实现多态调用
class  DirectorBuilder
{
public :
    DirectorBuilder(Builder *  pBuilder){
        m_pBuilder = pBuilder;
    }

    ~DirectorBuilder(){
        m_pBuilder = NULL;
    }

    void Init(){
        m_pBuilder->step1();
        if(m_pBuilder->step2()>5){
            m_pBuilder->step3();
        }
        int n = m_pBuilder->step4();
        for(int i=0; i<n; i++){
            m_pBuilder->step5();
        }
    }

private :
    Builder *m_pBuilder = NULL;
};

class  ConcreateBuilder1 :  public  Builder
{
public :
    ConcreateBuilder1(int a,int b,int c,int d,int e){
        m_a = a;
        m_b = b;
        m_c = c;
        m_d = d;
        m_e = e;
    }
    virtual ~ ConcreateBuilder1(){}
    virtual string getSelfName(){
        return "ConcreateBuilder1";
    }

    virtual int step1()
    {
        cout << this->getSelfName()<<"运行step1" << endl;
        return m_a;
    }
    virtual int step2()
    {
        cout << this->getSelfName()<<"运行step2" << endl;
        return m_b;
    }
    virtual int step3()
    {
        cout << this->getSelfName()<<"运行step3" << endl;
        return m_c;
    }
    virtual int step4()
    {
        cout << this->getSelfName()<<"运行step4" << endl;
        return m_d;
    }
    virtual int step5()
    {
        cout << this->getSelfName()<<"运行step5" << endl;
        return m_e;
    }
};

class  ConcreateBuilder2 :  public  Builder
{
public :
    ConcreateBuilder2(int a,int b,int c,int d,int e){
        m_a = a;
        m_b = b;
        m_c = c;
        m_d = d;
        m_e = e;
    }
    virtual ~ ConcreateBuilder2(){}
    virtual string getSelfName(){
        return "ConcreateBuilder2";
    }
    virtual int step1()
    {
        cout << this->getSelfName()<<"运行step1" << endl;
        return m_a;
    }
    virtual int step2()
    {
        cout << this->getSelfName()<<"运行step2" << endl;
        return m_b;
    }
    virtual int step3()
    {
        cout << this->getSelfName()<<"运行step3" << endl;
        return m_c;
    }
    virtual int step4()
    {
        cout << this->getSelfName()<<"运行step4" << endl;
        return m_d;
    }
    virtual int step5()
    {
        cout << this->getSelfName()<<"运行step5" << endl;
        return m_e;
    }
};




#endif // BUILDER_H

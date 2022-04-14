#ifndef TEMPLATEMETHOD_H
#define TEMPLATEMETHOD_H
#include <iostream>
#include <list>
using namespace std;


class Template
{
public:
    virtual ~Template(){}

    void run()
    {
       step1();
       if(step2()>5){
           step3();
       }
       int n = step4();
       for(int i=0; i<n; i++){
           step5();
       }
    }
private:
    int step1()
    {
        cout << "运行step1" << endl;
        return 0;
    }
    int step3()
    {
        cout << "运行step3" << endl;
        return 0;
    }
    int step5()
    {
        cout << "运行step5" << endl;
        return 0;
    }
    virtual int step2()=0;
    virtual int step4()=0;

};

class TemplateView : public Template
{
public:
    ~TemplateView(){}

    void setStepValue(int step2,int step4)
    {
        m_step2 = step2;
        m_step4 = step4;
    }
private:
    int m_step2 = 0;
    int m_step4 = 0;

    virtual int step2()
    {
        cout << "运行step2" << endl;
        return m_step2;
    }
    virtual int step4()
    {
        cout << "运行step4" << endl;
        return m_step4;
    }
};



#endif // TEMPLATEMETHOD_H

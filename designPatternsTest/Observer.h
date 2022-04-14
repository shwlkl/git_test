#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
#include <list>
using namespace std;

//抽象观察者
class Observer
{
public:
    virtual ~Observer(){}
    virtual void DeleteSelf() = 0;
    virtual void Update(int) = 0;
};
//抽象目标
class Subject
{
public:
    virtual ~Subject(){}
    virtual void Attach(Observer *) = 0;
    virtual void Detach(Observer *) = 0;
    virtual void Notify() = 0;
};
//具体目标
class ConcreteSubject : public Subject
{
public:
    ~ConcreteSubject(){
        m_ObserverList.clear();
    }
    void Attach(Observer *pObserver)
    {
        m_ObserverList.push_back(pObserver);
    }
    void Detach(Observer *pObserver)
    {
        m_ObserverList.remove(pObserver);
    }
    void Notify()
    {
        std::list<Observer *>::iterator it = m_ObserverList.begin();
        while (it != m_ObserverList.end())
        {
            (*it)->Update(m_iState);
            ++it;
        }
    }
    void SetState(int state)
    {
        m_iState = state;
    }

private:
    std::list<Observer *> m_ObserverList;
    int m_iState;
};

//具体观察者1
class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(Subject *pSubject)
    {
        m_pSubject = pSubject;
    }
    ~ConcreteObserver(){
        m_pSubject = NULL;
    }

    void DeleteSelf(){
        m_pSubject->Detach(this);
    }
    void Update(int value)
    {
        cout << "ConcreteObserver get the update. New State:" << value << endl;
    }
private:
    Subject *m_pSubject = NULL;
};
//具体观察者2
class ConcreteObserver2 : public Observer
{
public:
    ConcreteObserver2(Subject *pSubject)
    {
        m_pSubject = pSubject;
    }
    ~ConcreteObserver2(){
        m_pSubject = NULL;
    }

    void DeleteSelf(){
        m_pSubject->Detach(this);
    }
    void Update(int value)
    {
        cout << "ConcreteObserver2 get the update. New State:" << value << endl;
    }
private:
    Subject *m_pSubject = NULL;
};



#endif // OBSERVER_H


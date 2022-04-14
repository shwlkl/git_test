#ifndef STATE_H
#define STATE_H
#include <iostream>
using namespace std;


class ContextState;

class State
{
public:
    virtual void Handle(ContextState *pContextState) = 0;
};

class ConcreteStateA : public State
{
public:
    virtual void Handle(ContextState *pContextState)
    {
        cout<<"I am concretestateA:"<<this<<endl;
    }
};

class ConcreteStateB : public State
{
public:
    virtual void Handle(ContextState *pContextState)
    {
        cout<<"I am concretestateB:"<<this<<endl;
    }
};

class ContextState
{
public:
    ContextState(State *pState){
        m_pState = pState;
    }
    ~ContextState(){
        m_pState = NULL;
    }

    void Request()
    {
        if (m_pState)
        {
            m_pState->Handle(this);
        }
    }

    void ChangeState(State *pState)
    {
        m_pState = pState;
    }

private:
    State *m_pState = NULL;
};



#endif // STATE_H

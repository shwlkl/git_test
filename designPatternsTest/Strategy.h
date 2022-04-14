#ifndef STRATEGY_H
#define STRATEGY_H
#include <iostream>
using namespace std;


class Strategy
{
public:
    virtual ~Strategy(){}
    virtual void AlgorithmInterface() = 0;
};

class ConcreateStrategyA : public Strategy
{
public:
    ~ConcreateStrategyA(){}
    virtual void AlgorithmInterface()
    {
        cout << "ConcreateStrategyA算法" << endl;
    }
};
class ConcreateStrategyB : public Strategy
{
public:
    ~ConcreateStrategyB(){}
    virtual void AlgorithmInterface()
    {
        cout << "ConcreateStrategyB算法" << endl;
    }
};

class Context
{
public:
    Context(Strategy *pStrategy)
    {
         m_pStrategy = pStrategy;
    }
    ~Context(){
        m_pStrategy = NULL;
    }
    void SetStrategy(Strategy *pStrategy)
    {
        m_pStrategy = pStrategy;
    }
    void ContextInterface()
    {
        if (NULL != m_pStrategy)
        {
            m_pStrategy->AlgorithmInterface();
        }
    }
private:
    Strategy* m_pStrategy = NULL;
};



#endif // STRATEGY_H

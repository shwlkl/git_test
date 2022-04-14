#ifndef MEMENTO_H
#define MEMENTO_H
#include <iostream>
#include <vector>
using namespace std;

class STMemento
{
public:
    STMemento(){};
    STMemento(int iVitality){
        this->iVitality = iVitality;
    }
    int GetVitality() const{
        return this->iVitality;
    }
private:
    int iVitality;
};

class STOriginator
{
public:
    STOriginator(string strName, int iVit){
        this->iVitality = iVit;
        this->name = strName;
    }
    STMemento *SaveState(){
        return new STMemento(iVitality);
    }
    void RecoverState(const STMemento *stMemento){
        this->iVitality = stMemento->GetVitality();
    }
    void SetVitality(int iVit){
        this->iVitality = iVit;
    }
    void Show(){
        cout << "Name: " << name << "     Live: " << iVitality<< endl;
    }
private:
    int iVitality;
    string name;
};

class STCareTaker
{
public:
    ~STCareTaker(){
        vecStMemento.clear();
    }
    void AddMemento(STMemento *stMemento){
        vecStMemento.push_back(stMemento);
    }
    STMemento *GetMemento(int index){
        if(index >= vecStMemento.size()){
            return NULL;
        }
        else{
            return vecStMemento[index];
        }
    }
private:
    vector<STMemento *> vecStMemento;
};

#endif // MEMENTO_H

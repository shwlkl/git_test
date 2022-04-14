#ifndef COMPOSITE_H
#define COMPOSITE_H
#include <iostream>
#include <list>
using namespace std;

#include <algorithm>
using namespace std;
class Component
{
public:
    virtual void process() = 0;
    virtual ~Component(){}
};
class Composite : public Component
{
private:
    string name;
    list<Component*> elements;
public:
    Composite( const string & s){
        name = s;
    }
    virtual ~Composite(){}
    void add(Component* element) {
        elements.push_back(element);
    }
    void remove(Component* element){
        elements.remove(element);
    }
    void process( ){
        //process current nodes
        cout<<name<<endl;
        //process leaf nodes
        for (auto &e : elements)
            e->process( );
    }
};
class Leaf : public Component
{
public:
    Leaf( string s){
        name = s;
    }
    void process( ){
        //process current node
        cout<<name<<endl;
    }
private:
    string name;
};


#endif // COMPOSITE_H

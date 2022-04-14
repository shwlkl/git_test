#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H
#include <iostream>
#include <map>
using namespace std;


class Font
{
public:
    Font(const string &key){
        m_key = key;
    }
    string m_key;
};
class FontFactory
{
public:
    ~FontFactory(){
        map<string,Font*>::iterator item = fontPool.begin();
        while(item != fontPool.end()){
            delete item->second;
            item++;
        }
        this->clear();
    }
    Font* getFont(const string &key){
         map<string,Font*>::iterator item = fontPool.find(key);
         if(item!=fontPool.end()){
             return item->second;
         }
         else{
             Font *font = new Font(key);
             fontPool[key] = font;
             return font;
         }
    }
    void clear(){
        fontPool.clear();
    }

private:
    map<string,Font*> fontPool;
};

#endif // FLYWEIGHT_H

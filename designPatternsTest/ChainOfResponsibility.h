#ifndef CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_H
#include <iostream>
using namespace std;

enum class RequestType
{
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3
};
class Reqest
{
        string description;
        RequestType reqType;
public:
    Reqest(const string & desc,RequestType type){
        description = desc;
        reqType = type;
    }
    RequestType getReqType( ) const{
        return reqType;
    }
    const string& getDescription() const{
        return description;
    }
};
class ChainHandler{
public:
    void sendReqestToNextHandler(const Reqest & req){
        if (nextChain != nullptr){
            cout<<this->getSelfName()<<"传给下一个链接："<<nextChain->getSelfName()<<endl;
            nextChain->handle(req);

        }
    }
protected:
    virtual bool canHandleRequest(const Reqest & req) = 0;
    virtual void processRequest(const Reqest & req) = 0;
    virtual string getSelfName() = 0;
public:
    ChainHandler( ){
        nextChain = nullptr;
    }
    void setNextChain(ChainHandler *next){
        cout<<this->getSelfName()<<"设置下一个链接："<<next->getSelfName()<<endl;
        nextChain = next;

    }
    void handle( const Reqest & req){
        if (canHandleRequest(req)){
            processRequest(req);
        }
        else{
            sendReqestToNextHandler(req);
        }
    }
public:
    ChainHandler *nextChain;
};
class Handler1 : public ChainHandler{
protected:
    bool canHandleRequest(const Reqest & req) override{
        return req.getReqType( ) == RequestType::REQ_HANDLER1;
    }
    void processRequest(const Reqest & req) override{
        cout << "Handler1 is handle reqest: " << req.getDescription( ) <<endl;
    }
    string getSelfName() override{
        return "Handler1";
    }
};
class Handler2 : public ChainHandler{
protected:
    bool canHandleRequest(const Reqest & req) override{
        return req.getReqType( ) == RequestType::REQ_HANDLER2;
    }
    void processRequest(const Reqest & req) override{
        cout << "Handler2 is handle reqest: " << req.getDescription( ) <<endl;
    }
    string getSelfName() override{
        return "Handler2";
    }
};
class Handler3 : public ChainHandler{
protected:
    bool canHandleRequest(const Reqest & req) override{
        return req.getReqType( ) == RequestType::REQ_HANDLER3;
    }
    void processRequest(const Reqest & req) override{
        cout << "Handler3 is handle reqest: " << req.getDescription( ) <<endl;
    }
    string getSelfName() override{
        return "Handler3";
    }
};









#endif // CHAINOFRESPONSIBILITY_H

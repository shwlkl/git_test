#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
using namespace std;

class Stream
{
public:
    virtual ~Stream(){}
    virtual void Read(int number) = 0;
    virtual void Write(int number) = 0;
};
class DecoratorStream : public Stream
{
public:
    DecoratorStream(Stream *stream){
        m_stream = stream;
    }
    virtual ~DecoratorStream(){
        m_stream = NULL;
    }
    virtual void Read(int number){
        cout<<"未添加职责中----职责子类未重写该函数-------:"<<number<<endl;
    }
    virtual void Write(int number){
        cout<<"未添加职责中----职责子类未重写该函数-------:"<<number<<endl;
    }
protected:
    Stream *m_stream = NULL;
};

class FileStream : public Stream
{
public:
    virtual ~FileStream(){}
    virtual void Read(int number){
        cout<<"FileRead中-----------:"<<number<<endl;
    }
    virtual void Write(int number){
        cout<<"FileWrite中-----------:"<<number<<endl;
    }
};

class NetworkStream : public Stream
{
public:
    virtual ~NetworkStream(){}
    virtual void Read(int number){
        cout<<"NetworkRead中-----------:"<<number<<endl;
    }
    virtual void Write(int number){
        cout<<"NetworkWrite中-----------:"<<number<<endl;
    }
};

class CrypotStream : public DecoratorStream
{
public:
    CrypotStream(Stream *stream):DecoratorStream(stream){
    }
    virtual ~CrypotStream(){}
    virtual void Read(int number){
        crypot();
        m_stream->Read(number);
    }
    virtual void Write(int number){
        crypot();
        m_stream->Write(number);
    }
    void crypot(){
        cout<<"从CrypotStream加密-----------"<<endl;
    }
};

class BufferStream : public DecoratorStream
{
public:
    BufferStream(Stream *stream):DecoratorStream(stream){
    }
    virtual ~BufferStream(){}
    virtual void Read(int number){
        crypot();
        m_stream->Read(number);
    }
    virtual void Write(int number){
        crypot();
        m_stream->Write(number);
    }
private:
    void crypot(){
        cout<<"BufferStream改写-----------"<<endl;
    }
};
#endif // DECORATOR_H

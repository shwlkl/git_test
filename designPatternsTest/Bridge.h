#ifndef BRIDGE_H
#define BRIDGE_H
#include <iostream>
using namespace std;

class MessageImp
{
public:
    virtual ~MessageImp(){}
    virtual void DrawPicture() = 0;
    virtual void WriteText() = 0;

};

class Message
{
public:
    Message(MessageImp *messageImp){
        m_messageImp = messageImp;
    }
    virtual ~Message(){}
    virtual void SendText() = 0;
    virtual void SendPicture() = 0;
protected:
    MessageImp *m_messageImp;
};
//接口实现
class PCMessageImp : public MessageImp
{
public:
    virtual ~PCMessageImp(){}
    virtual void DrawPicture(){
        cout<<"PC画图"<<endl;
    }
    virtual void WriteText(){
        cout<<"PC写文字"<<endl;
    }
};
class MobileMessageImp : public MessageImp
{
public:
    virtual ~MobileMessageImp(){}
    virtual void DrawPicture(){
        cout<<"Mobile画图"<<endl;
    }
    virtual void WriteText(){
        cout<<"Mobile写文字"<<endl;
    }
};
//业务实现
class MessageLite : public Message
{
public:
    MessageLite(MessageImp *messageImp):Message(messageImp){}
    virtual ~MessageLite(){}
    virtual void SendText(){
        cout<<"MessageLite发送文字开始----"<<endl;
        m_messageImp->WriteText();
        cout<<"MessageLite发送文字结束----"<<endl;
    }

    virtual void SendPicture(){
        cout<<"MessageLite发送图片开始----"<<endl;
        m_messageImp->DrawPicture();
        cout<<"MessageLite发送图片结束----"<<endl;
    }
};
class MessagePrefect : public Message
{
public:
    MessagePrefect(MessageImp *messageImp):Message(messageImp){}
    virtual ~MessagePrefect(){}
    virtual void SendText(){
        cout<<"MessagePrefect发送文字开始----"<<endl;
        m_messageImp->WriteText();
        m_messageImp->DrawPicture();
        cout<<"MessagePrefect发送文字结束----"<<endl;
    }

    virtual void SendPicture(){
        cout<<"MessagePrefect发送图片开始----"<<endl;
        m_messageImp->DrawPicture();
        m_messageImp->WriteText();
        cout<<"MessagePrefect发送图片开始----"<<endl;
    }
};



#endif // BRIDGE_H

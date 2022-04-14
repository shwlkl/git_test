#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//接受者
class Adder {
private:
    int num;
public:
    Adder(int n){
        this->num = n;
    }
    int add(int value) {
        cout<<num<<" + "<<value<<" = ";
        num += value;
        cout<<num<<endl;
        return num;
    }
};
//抽象命令
class Command {
public:
    virtual int execute(int value) = 0;
    virtual int undo() = 0;
    virtual int redo() = 0;
};
//具体命令
class AddCommand : public Command {
private:
    Adder *m_adder;
    stack <int>unStack;
    stack <int>reStack;
public:
    AddCommand(Adder *adder){
        m_adder = adder;
    }
    int undo() {
        int i = 0;
        if (unStack.empty()) {
            i = -1;
        }
        else {
            reStack.push(unStack.top());
            unStack.pop();
            if (!unStack.empty()) {
                i = unStack.top();
            }
        }
        return i;
    }
    int redo() {
        int i = 0;
        if (reStack.empty()) {
            i = -1;
        }
        else {//撤回时只要可以可以撤回，则撤回栈一定有数据
            unStack.push(reStack.top());
            i = reStack.top();
            reStack.pop();
        }
        return i;
    }
    int execute(int value) {
        int v = 0;
        v = m_adder->add(value);
        unStack.push(v);
        return v;
    }
};
//调用者
class Invoker{
private:
    AddCommand *m_command;
public:
    Invoker(AddCommand *command) {
        m_command = command;
    };
    void compute(int value) {
        m_command->execute(value);
    };
    void undo() {
        int i = m_command->undo();
        if (i == -1) {
            cout << "已撤销到初态" << endl;
        }
        else {
            cout << "撤销执行成功，运算结果是：" << i << endl;
        }
    }
    void redo() {
        int i = m_command->redo();
        if (i == -1) {
            cout << "已恢复至终态" << endl;
        }
        else {
            cout << "恢复执行成功，运算结果是：" << i << endl;
        }
    }
};

#endif // COMMAND_H

#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>
#include <mutex>
#include <atomic>
#include <thread>
using namespace std;

class Singleton{
private:
    Singleton( ){}
    Singleton(const Singleton& other){}
public:
    static Singleton* getInstance();
    static Singleton* getInstance(int n);
    static Singleton* getInstance(string str);
    static Singleton* getInstance(char a);
    static Singleton* getInstance(int a,int b);
public:
    static Singleton* m_instance;
    static atomic<Singleton*> m_instance1;

};
//线程非安全版本
Singleton* Singleton::m_instance=nullptr;
static mutex mtx1;
static mutex mtx2;
static mutex mtx3;
Singleton* Singleton::getInstance(int n){
    if (m_instance == nullptr) {
        m_instance = new Singleton( );
    }
    return m_instance;
}
//线程安全版本，但锁的代价过高
Singleton* Singleton::getInstance(string str) {
    lock_guard<mutex> lock(mtx1);
    if (m_instance == nullptr) {
        m_instance = new Singleton( );
    }
    return m_instance;
}

//双检查锁，但由于内存读写reorder不安全
Singleton* Singleton::getInstance(char a){
    if(m_instance==nullptr){
        lock_guard<mutex> lock(mtx2);
        if (m_instance == nullptr) {
            m_instance = new Singleton( );
        }
    }
    return m_instance;
}
//C++11版本之后的跨平台实现(或者volatile修饰m_instance1)
atomic<Singleton*> Singleton::m_instance1;
Singleton* Singleton::getInstance(){
    Singleton* tmp = m_instance1.load(memory_order_relaxed);
    atomic_thread_fence(memory_order_acquire);//获取内存fence
    if ( tmp == nullptr) {
        lock_guard<mutex> lock(mtx3) ;
        tmp = m_instance1.load(memory_order_relaxed);
        if (tmp == nullptr){
            tmp = new Singleton();
            std::atomic_thread_fence(memory_order_release);//释放内存fence
            m_instance1.store(tmp,memory_order_relaxed) ;
        }
    }
    return tmp;
}

//(存在抛出异常问题时说明未链接thread) 用于call_once的局部静态变量,必定只调用一次(once_flag的生命周期，它必须要比使用它的线程的生命周期要长。所以通常定义成全局变量比较好)
static once_flag oc;
Singleton* Singleton::getInstance(int a,int b) {
    call_once(oc, [&](){m_instance = new Singleton();});
    return m_instance;

}


#endif // SINGLETON_H

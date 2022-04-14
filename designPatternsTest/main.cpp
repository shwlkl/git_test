#include <iostream>
#include <list>
using namespace std;

#include "TemplateMethod.h"
#include "Strategy.h"
#include "Observer.h"
#include "Decorator.h"
#include "Bridge.h"
#include "FactoryMethod.h"
#include "AbstracFactory.h"
#include "Prototype.h"
#include "Builder.h"
#include "Singleton.h"
#include "Flyweight.h"
#include "Proxy.h"
#include "Adapt.h"
#include "State.h"
#include "Memento.h"
#include "Composite.h"
#include "Iterator.h"
#include "ChainOfResponsibility.h"
#include "Command.h"
#include "Visitor.h"


int main()
{
    //00:设计模式的根本：必须有稳定的存在，然后抽象不稳定的存在
    //01:模版方法 Template method-------------------
    //父类固定算法流程，子类重构算法中部分功能
    {
        cout << "01:模版方法 Template method:" << endl;
        TemplateView *pTemplateView = new TemplateView();
        pTemplateView->setStepValue(6,3);
        pTemplateView->run();
        delete pTemplateView;
    }
    //02:策略模式 Strategy------------------------------
    //不同算法有共同父类，客户依据需求传入算法
    {
        cout << "02:策略 Strategy:" << endl;
        //创建算法
        Strategy* pStrategyA = new ConcreateStrategyA();
        Strategy* pStrategyB = new ConcreateStrategyB();
        //创建客户
        Context* pContext = new Context(pStrategyA);
        //使用算法A
        pContext->ContextInterface();
        //客户更新算法B
        pContext->SetStrategy(pStrategyB);
        //使用算法B
        pContext->ContextInterface();
        delete pStrategyA;
        delete pStrategyB;
        delete pContext;
    }
    //03:观察者模式 Observer-------------------------
    //目标可添加删除观察者，观察者也可主动取消目标订阅（一个目标对多个观察者）
    {
        cout << "03观察者模式 Observer:" << endl;
        // 创建目标
        ConcreteSubject *pSubject = new ConcreteSubject();
        // 创建观察者
        Observer *pObserver = new ConcreteObserver(pSubject);
        Observer *pObserver2 = new ConcreteObserver2(pSubject);
        // 目标添加观察者
        pSubject->Attach(pObserver);
        pSubject->Attach(pObserver2);
        // 更新目标数值
        pSubject->SetState(1);
        // 目标发布
        pSubject->Notify();
        // 观察者取消订阅
        pObserver2->DeleteSelf();
        // 更新目标数值
        pSubject->SetState(2);
        // 目标发布
        pSubject->Notify();
        // 目标移除观察者
        pSubject->Detach(pObserver);
        // 更新目标数值
        pSubject->SetState(3);
        // 目标发布
        pSubject->Notify();

        delete pObserver;
        delete pObserver2;
        delete pSubject;
    }
    //04:装饰模式 Decorator--------------------------
    //将额外的职责抽出来，与原先功能任意组合（职责的抽象类与功能仍拥有同一个基类）
    {
        cout << "04装饰模式 Decorator:" << endl;
        //创建文件流对象
        Stream *pStream = new FileStream();
        //给文件流对象添加加密功能
        DecoratorStream *pDecoratorStream = new CrypotStream(pStream);
        //给文件流对象添加改写功能
        DecoratorStream *pDecoratorStream2 = new BufferStream(pDecoratorStream);
        pDecoratorStream2->Read(1);
        pDecoratorStream2->Write(2);
        delete pStream;
        delete pDecoratorStream;
        delete pDecoratorStream2;
    }
    //05:桥接模式 Bridge-----------------------------
    //将实现与业务两两任意组合（实现拥有一个基类，业务拥有一个基类，实现基类为业务基类的成员）
    {
        cout << "05桥接模式 Bridge:" << endl;
        //创建实现
        PCMessageImp *pPCMessage = new PCMessageImp();
        MobileMessageImp *pMobileMessageImp = new MobileMessageImp();
        //创建业务
        MessageLite *pMessageLite = new MessageLite(pPCMessage);
        MessagePrefect *pMessagePrefect = new MessagePrefect(pPCMessage);
        pMessagePrefect->SendText();
        delete pPCMessage;
        delete pMobileMessageImp;
        delete pMessageLite;
        delete pMessagePrefect;
    }
    //06:工厂方法 FactoryMethod----------------------
    //产品和产品工厂各拥有一个基类，产品工厂实例创建对应的产品实例(将new创建对象放到FactoryWindows基类外，使FactoryWindows内部不依靠具体类)
    {
        cout << "06工厂方法 Factory Method:" << endl;
        Factory *pFactory = new PCProductFactory();
        FactoryWindows *pWindows = new FactoryWindows(pFactory);
        pWindows->Productclick();
        delete pWindows;
        delete pFactory;
    }
    //07:抽象工厂 AbstracFactory---------------------
    //产品A和产品B各有一个基类，A和B两种实现方式为其子类，产品的实现方式为抽象工厂基类，子类为产品A和产品B的同一种实现方式
    {
        cout << "07：抽象工厂 AbstracFactory:" << endl;
        // 生产产品A 的第一种实现
        ConcreateFactory1 *pFactory1 = new ConcreateFactory1();
        AbstractProductA *pProductA = pFactory1->CreateProductA();
        // 生产产品B 的第二种实现
        ConcreateFactory2 *pFactory2 = new ConcreateFactory2();
        AbstractProductB *pProductB = pFactory2->CreateProductB();
        delete pFactory1;
        delete pProductA;
        delete pFactory2;
        delete pProductB;
    }
    //08:原型模式 Prototype--------------------------
    //某个对象的状态需要多次使用(将new创建对象放到CPrototypeWindows基类外，使PrototypeWindows内部可以拷贝这个对象的状态来使用)
    {
        cout << "08:原型模式 Prototype:" << endl;
        Prototype *pPrototype = new ConcreatePrototype1();
        PrototypeWindows *pPrototypeWindows = new PrototypeWindows(pPrototype);
        pPrototypeWindows->Prototypeclick();
    }
    //09:生成器模式 Builder----------------------------
    //算法流程固定，将算法中功能抽象为接口，子类继承接口(与模版方法 Template method类似，但是将固定流程与易变功能分离)
    {
        cout << "09:生成器模式 Builder:" << endl;
        Builder *pBuilder = new ConcreateBuilder1(1,2,3,4,5);
        DirectorBuilder *pDirectorBuilder = new DirectorBuilder(pBuilder);
        pDirectorBuilder->Init();
    }
    //10:单件模式 Singleton----------------------------
    //确保只存在一个对象(利用静态static)
    {
        cout << "10:单件模式 Singleton:" << endl;
        Singleton *pSingleton = Singleton::getInstance(1);
        cout << pSingleton << endl;
        Singleton *pSingleton1 = Singleton::getInstance('1');
        cout << pSingleton1 << endl;
        Singleton *pSingleton2 = Singleton::getInstance("sss");
        cout << pSingleton2 << endl;
    }
    //11:享元模式 Flyweight----------------------------
    //类似线程池
    {
        cout << "11:享元模式 Flyweight:" << endl;
        FontFactory *pfontFactory = new FontFactory();
        Font *pFont = pfontFactory->getFont("1");
        cout<<pFont<<endl;
        Font *pFont1 = pfontFactory->getFont("11");
        cout<<pFont1<<endl;
        Font *pFont2 = pfontFactory->getFont("111");
        cout<<pFont2<<endl;
        Font *pFont3 = pfontFactory->getFont("11");
        cout<<pFont3<<endl;
        delete pfontFactory;
    }
    //12:外观模式 Facade----------------------------
    //
    {
        cout << "12:外观模式 Facade:" << endl;
        cout << "类似单例模式，主要起隔离作用，将所有操作通过facade对象进行操作内部对象" << endl;
    }
    //13:代理模式 Proxy----------------------------
    //代理对象和真正对象都继承自同一个基类，使用真正对象必须通过代理对象来操作
    {
        cout << "13:代理模式 Proxy:" << endl;
        ProxySubject* pProxy = new Proxy();
        pProxy->Request();
        delete pProxy;
    }
    //14:适配器模式 Adapt----------------------------
    //新旧接口的转换(两种方式：1，多继承实现(不推荐)。2，组合方式实现)
    {
        cout << "14:适配器模式 Adapt:" << endl;
        IAdaptee* pIAdaotee = new OldIAdaptee();
        ITarget* pItarget = new Adapter(pIAdaotee);
        pItarget->process();
        delete pItarget;
        delete pIAdaotee;
    }
    //15:中介者 Mediator----------------------------
    //
    {
        cout << "15:中介者 Mediator:" << endl;
        cout << "类似观察者模式，多个对象通过Mediator对象进行进阶访问和操作" << endl;
    }
    //16:状态模式 State----------------------------
    //客户状态需要发生变化，依据需求传入(与策略模式 Strategy类似，但主要是对象状态发生变化)
    {
        cout << "16:状态模式 State:" << endl;
        State *pStateA = new ConcreteStateA();
        State *pStateB = new ConcreteStateB();
        ContextState *pContextState = new ContextState(pStateA);
        pContextState->Request();
        pContextState->ChangeState(pStateB);
        pContextState->Request();
        delete pContextState;
        delete pStateB;
        delete pStateA;
    }
    //17:备忘录模式 Memento----------------------------
    //客户对象的部分状态保存起来，供需要时恢复(与状态模式 State类似，但状态的变化进行保存)
    {
        cout << "17:备忘录模式 Memento:" << endl;
        //创建游戏对象
        STOriginator *pstOriginator = new STOriginator("xxx", 10);
        cout << "原始状态: ";
        pstOriginator->Show();
        //创建存档列表
        STCareTaker *pstCareTaker = new STCareTaker();
        //创建游戏对象存档
        STMemento *pstMemento = pstOriginator->SaveState();
        //将游戏对象存档存入存档列表
        pstCareTaker->AddMemento(pstMemento);
        //更改游戏对象状态
        pstOriginator->SetVitality(50);
        cout << "战斗后状态: ";
        pstOriginator->Show();
        //取出存档列表中存档
        STMemento *pstMementold = pstCareTaker->GetMemento(0);
        //游戏对象恢复存档
        pstOriginator->RecoverState(pstMementold);
        cout << "归档后状态: ";
        pstOriginator->Show();
        delete pstCareTaker;
        delete pstOriginator;
        delete pstMemento;
    }
    //18:组合模式 Composite----------------------------
    //相当于json结构或树结构(代码示例为树的先序遍历)
    {
        cout << "18:组合模式 Composite:" << endl;
        Composite root( "root" ) ;
        Composite treeNode1("treeNode1" );
        Composite treeNode2( "treeNode2" );
        Composite treeNode3( "treeNode3" );
        Composite treeNode4( "treeNode4" );
        Leaf left1("left1" );
        Leaf left2("left2" );
        Leaf left3("left3" );
        Leaf left4("left4" );

        root.add(&treeNode1);
        root.add(&treeNode2);
        root.add(&treeNode3);
        treeNode1.add(&treeNode4);
        treeNode2.add(&left1);
        treeNode2.add(&left2);
        treeNode3.add(&left3);
        treeNode4.add(&left4);
        root.process();
        cout<<"移除treeNode1后："<<endl;
        root.remove(&treeNode1);
        root.process();
    }
    //19:迭代器 Iterator----------------------------
    //提供一种方式,使得算法和容器可以独立的变化,而且在访问容器对象的时候不必暴露容器的内部细节
    {
        cout << "19:迭代器 Iterator:" << endl;
        ConcreteAggregate* pName = new ConcreteAggregate();
        if (NULL != pName){
            pName->Push("hello");
            pName->Push("word");
            pName->Push("cxue");
        }
        Iterator* iter = pName->CreateIterator();
        if (NULL != iter){
            string strItem = iter->First();
            while (!iter->IsDone()){
                cout << iter->CurrentItem() << " is ok" << endl;
                iter->Next();
            }
        }
    }
    //20:职责链 ChainOfResponsibility----------------------------
    //对请求一级一级向下传递，直到能被处理为止(nginx的请求处理)
    {
        cout << "20:职责链 ChainOfResponsibility:" << endl;
        Handler1 h1;
        Handler2 h2;
        Handler3 h3;
        cout<<&h1<<endl;
        cout<<&h2<<endl;
        cout<<&h3<<endl;
        h1.setNextChain(&h2);
        h2.setNextChain(&h3);
        Reqest req("process task ... ",RequestType:: REQ_HANDLER3);
        h1.handle(req);
    }
    //21:命令模式 Command----------------------------
    //将行为抽象成对象，将行为保存
    {
        cout << "21:命令模式 Command:" << endl;
        Adder *pAdder = new Adder(0);
        AddCommand *pAddCommand = new AddCommand(pAdder);
        Invoker *pInvoker = new Invoker(pAddCommand);
        //计算
        cout << "计算过程：" << endl;
        pInvoker->compute(2);
        pInvoker->compute(6);
        pInvoker->compute(9);
        //多次撤回
        cout << "undo操作：" << endl;
        pInvoker->undo();
        pInvoker->undo();
        pInvoker->undo();
        pInvoker->undo();
        //多次恢复
        cout << "redo操作：" << endl;
        pInvoker->redo();
        pInvoker->redo();
        pInvoker->redo();
        pInvoker->redo();
    }
    //22:访问器 Visitor----------------------------
    //Element基类的子类必须明确个数，只能增加子类中的方法，不能增加子类个数(通过双重动态绑定)
    {
        cout << "22:访问器 Visitor:" << endl;
        Visitor *pVisitor2 = new Visitor2();
        Element *pElementB = new ElementB();
        pElementB->accept(pVisitor2);// double dispatch
        Element *PElementA = new ElementA();
        PElementA->accept(pVisitor2);
        delete pVisitor2;
        delete pElementB;
        delete PElementA;
    }
    //23:解释器 Interperter----------------------------
    //
    {
        cout << "23:解释器 Interperter:" << endl;
        cout << "将某些规则以程序方式表示出来或显示结果，类似字符串计算器" << endl;

    }
    system("pause");
}

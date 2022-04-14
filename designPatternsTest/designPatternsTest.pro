TEMPLATE = app
CONFIG += console c++11 thread
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    AbstracFactory.h \
    Adapt.h \
    Bridge.h \
    Builder.h \
    ChainOfResponsibility.h \
    Command.h \
    Composite.h \
    Decorator.h \
    FactoryMethod.h \
    Flyweight.h \
    Iterator.h \
    Memento.h \
    Observer.h \
    Prototype.h \
    Proxy.h \
    Singleton.h \
    State.h \
    Strategy.h \
    TemplateMethod.h \
    Visitor.h

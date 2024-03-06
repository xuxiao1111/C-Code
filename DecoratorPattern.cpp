#include <iostream>
using namespace std;

// 抽象构件类
class Component {
public:
    virtual void operation() = 0;
};

// 具体构件类
class ConcreteComponent : public Component {
public:
    void operation() override {
        // 实现具体操作
        cout << "Concrete Component" << endl;
    }
};

// 抽象装饰器类
class Decorator : public Component {
protected:
    Component* component; //维持一个对抽象构件类的引用

public:
    Decorator(Component* comp) : component(comp) {}

    void operation() override {
        if (component)
            component->operation(); //调用原有也许方法
    }
};

// 具体装饰器类A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp) : Decorator(comp) {}

    void operation() override {
        Decorator::operation(); //调用原有业务方法方法
        // 添加额外的功能
        cout << "Added Functionality A" << endl;
    }
    //新增业务方法
    void addedBehavior() {
        cout << "New method in Concrete Decorator A" << endl;
    }
};

// 具体装饰器类B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* comp) : Decorator(comp) {}

    void operation() override {
        Decorator::operation();
        // 添加额外的功能
        cout << "Added Functionality B" << endl;
    }
};

int main() {
    Component* component = new ConcreteComponent();
    Component* decoratorA = new ConcreteDecoratorA(component);
    Component* decoratorB = new ConcreteDecoratorB(decoratorA);

    decoratorB->operation();
    ConcreteDecoratorA* concreteDecoratorA = dynamic_cast<ConcreteDecoratorA*>(decoratorA);
    concreteDecoratorA->addedBehavior(); //调用装饰器A的新方法

    delete decoratorB;
    delete decoratorA;
    delete component;

    return 0;
}

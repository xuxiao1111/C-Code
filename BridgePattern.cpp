#include <iostream>
using namespace std;

// 实现类接口
class Implementor {
public:
    virtual void operationImpl() = 0;
};

// 具体实现类A
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() override {
        // 实现具体操作
        cout << "Concrete Implementor A" << endl;
    }
};

// 具体实现类B
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() override {
        // 实现具体操作
        cout << "Concrete Implementor B" << endl;
    }
};

// 抽象类
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl) : implementor(impl) {}

    virtual void operation() = 0;
};

// 扩展抽象类
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* impl) : Abstraction(impl) {}

    void operation() override {
        // 执行操作前的其他逻辑
        implementor->operationImpl();
        // 执行操作后的其他逻辑
    }
};

int main() {
    Implementor* implA = new ConcreteImplementorA();
    Implementor* implB = new ConcreteImplementorB();

    // 使用具体实现类A的对象创建扩展抽象类对象
    Abstraction* abstractionA = new RefinedAbstraction(implA);
    abstractionA->operation();

    // 使用具体实现类B的对象创建扩展抽象类对象
    Abstraction* abstractionB = new RefinedAbstraction(implB);
    abstractionB->operation();

    delete implA;
    delete implB;
    delete abstractionA;
    delete abstractionB;

    return 0;
}

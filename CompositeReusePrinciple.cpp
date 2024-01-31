#include <iostream>

// 基础组件类
class Component {
public:
    virtual void operation() = 0;
};

// 具体组件类
class ConcreteComponent : public Component {
public:
    void operation() override {
        std::cout << "ConcreteComponent operation." << std::endl;
    }
};

class ConcreteComponent_2 : public Component {
public:
    void operation() override {
        std::cout << "ConcreteComponent_2 operation." << std::endl;
    }
};

// 组合类
class Composite {
private:
    Component* component;

public:
    Composite(Component* comp) : component(comp) {}

    void operation() {
        component->operation();
    }
};

int main() {
    Component* component = new ConcreteComponent_2();
    Composite composite(component);
    composite.operation();

    delete component;

    return 0;
}

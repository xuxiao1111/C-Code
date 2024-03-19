#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Flyweiget {
public:
    virtual void Operation() = 0;
};


class ConcreteFlyweight : public Flyweiget {
public:
    ConcreteFlyweight(int intrinsicState) {
        this->intrinsicState = intrinsicState;
    }
    void Operation() override {
        cout << "具体享元对象，内部状态为 " << intrinsicState << endl;
    }
private:
    int intrinsicState;
};

class FlyweigetFactory {
public:
    Flyweiget* getFlyweight(int key) {
        if (flyweights.find(key) != flyweights.end()) {
            return flyweights[key];
        }
        else {
            Flyweiget* fw = new ConcreteFlyweight(key);
            flyweights[key] = fw;
            return fw;
        }
    }
private:
    unordered_map<int, Flyweiget*> flyweights;
};



int main() {
    FlyweigetFactory factory;
    Flyweiget* flyweight1 = factory.getFlyweight(1);
    flyweight1->Operation();

    Flyweiget* flyweight2 = factory.getFlyweight(2);
    flyweight2->Operation();

    Flyweiget* flyweight3 = factory.getFlyweight(1);
    flyweight3->Operation();

    cout << "flyweight1 和 flyweight3 是否为同一个对象？" << (flyweight1 == flyweight3 ? "是" : "否") << endl;

    return 0;
}

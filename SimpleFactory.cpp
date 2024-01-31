#include <iostream>
#include <string>
using namespace std;

class Product {
public:
	//所有产品类的公共业务方法
	void methodSame() {
		//公共方法的实现
		cout << "Product::methodSame" << endl;
	}
	//声明抽象业务方法
	virtual void methodDiff() = 0;
};

class ProductA : public Product {
public:
	//实现业务方法
	void methodDiff() {
		cout << "ProductA::methodDiff" << endl;
	}
};

class ProductB : public Product {
public:
	//实现业务方法
	void methodDiff() {
		cout << "ProductB::methodDiff" << endl;
	}
};

class factory {
public:
	static Product* getProduct(string arg) {
		Product *product = nullptr;
		if (arg == "a") {
			return new ProductA();
		}
		else if (arg == "b") {
			return new ProductB();
		}
		else {
			return nullptr;
		}
	}
};

int main() 
{
	Product* pA = factory::getProduct("a");
	if (pA) {
		pA->methodSame();
		pA->methodDiff();
		delete pA;
	}
	

	Product* pB = factory::getProduct("b");
	if (pB) {
		pB->methodSame();
		pB->methodDiff();
		delete pB;
	}
	return 0;
}

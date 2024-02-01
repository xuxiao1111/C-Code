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

class Factory {
public:
	virtual Product* createProduct() = 0;
};

class concerteFactoryA : public Factory {
public:
	Product* createProduct() {
		Product *product = new ProductA();
		return product;
	}
};

class concerteFactoryB : public Factory {
public:
	Product* createProduct() {
		Product* product = new ProductB();
		return product;
	}
};


int main() 
{
	Factory* factory_1 = new concerteFactoryA();
	Product* product_1 = factory_1->createProduct();
	product_1->methodSame();
	product_1->methodDiff();

	Factory* factory_2 = new concerteFactoryB();
	Product* product_2 = factory_2->createProduct();
	product_2->methodSame();
	product_2->methodDiff();
}

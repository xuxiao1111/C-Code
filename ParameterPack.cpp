#include <iostream>
#include <memory>
#include <string>

template<size_t...args> //1
struct X {
	void f() {
		for (const auto& i : { args... }/*6*/) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
};

template<typename...Args> //2
void f(Args...args) { //5
	((std::cout << args << " "), ...); //c++17折叠表达式
	std::cout << '\n';
}

template<std::integral...Args> //3
void f2(Args...args) {
	((std::cout << args << " "), ...);
	std::cout << '\n';
}

template<class T1, class T2, class T3>
struct T {

};

template<template<class T1, class T2, class T3>class...Args> //4
struct Y {

};

void print() {} //递归终止条件
template<class T, class...Args>
void print(T t, Args...args) {
	std::cout << t << ' ';
	print(args...);//6
}

template<size_t...Args>
void t() {
	int array[sizeof...(Args)]{ Args... };
	for (const auto& i : array) {
		std::cout << i << ' ';
	}
	endl(std::cout);
}

int main()
{
	X<1,2,3,4,5,6> x;
	x.f();
	f(1, 2, 3, 4, '*', "*");
	f2(1, 2, 3, 4, '*');
	Y<std::basic_string, T, T, T>y;
	print("1", 2, 3, 5.5); 
}

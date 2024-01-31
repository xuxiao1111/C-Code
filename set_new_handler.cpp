#include <iostream>
#include <new>

class MyClass {
public:
    static void* operator new(std::size_t size);
    static void operator delete(void* ptr) noexcept;
    static std::new_handler set_new_handler(std::new_handler p) noexcept;

private:
    static std::new_handler currentHandler;
};

std::new_handler MyClass::currentHandler = nullptr;

void* MyClass::operator new(std::size_t size) {
    void* ptr = std::malloc(size);
    if (!ptr) {
        // 内存分配失败，调用当前的 new_handler（如果已设置）
        if (currentHandler)
            currentHandler();
        else
            throw std::bad_alloc();
    }
    else {
        if (currentHandler)
            currentHandler();
    }
    return ptr;
}

void MyClass::operator delete(void* ptr) noexcept {
    std::free(ptr);
}

std::new_handler MyClass::set_new_handler(std::new_handler p) noexcept {
    std::new_handler oldHandler = currentHandler;
    currentHandler = p;
    return oldHandler;
}

int main() {
    MyClass::set_new_handler([]() {
        std::cout << "Custom new handler called" << std::endl;
        // 在这里编写适当的处理代码
        });

    MyClass* obj = new MyClass;
    // 使用自定义的 operator new 进行对象的动态内存分配

    delete obj;
    // 使用自定义的 operator delete 进行对象的内存释放

    return 0;
}

#include <iostream>

class Foo{
    public:
        void bar(){
            std::cout << "Hello" << std::endl;
        }
};

int main() {
    Foo foo;
    foo.bar();
    return 0;
}
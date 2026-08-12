#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::cout << rd.entropy() << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << rd() <<std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}
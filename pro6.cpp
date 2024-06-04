#include <iostream>

void demonstrate_optimizations() {
    // Constant folding
    int x = 5;
    int y = 10;
    int z = x * y; // Constant folding: the compiler can optimize this to int z = 50;
    
    // Dead code elimination
    int a = 20;
    if (a > 30) {
        a = 30; // This block will never execute and can be removed by the compiler
    }

    // Strength reduction
    int b = 64;
    int c = b * 8; // Strength reduction: the compiler can optimize this to int c = b << 3;

    // Output results
    std::cout << "Constant folding result (z): " << z << std::endl;
    std::cout << "Dead code elimination result (a): " << a << std::endl;
    std::cout << "Strength reduction result (c): " << c << std::endl;
}

int main() {
    demonstrate_optimizations();
    return 0;
}

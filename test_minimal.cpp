#include <cstdlib>
#include <iostream>

int add(int, int); // declare the function under test

int main() {
    if (add(2, 3) != 5) {
        std::cerr << "Test failed: add(2,3) should be 5\n";
        return EXIT_FAILURE;
    }

    std::cout << "Test passed.\n";
    return EXIT_SUCCESS;
}

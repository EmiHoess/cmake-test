#include <iostream>
#include <string>

static int tests_failed = 0;

void check(bool condition, const std::string& name) {
    if (condition) {
        std::cout << "[ OK ] " << name << "\n";
    } else {
        std::cout << "[FAIL] " << name << "\n";
        tests_failed++;
    }
}

// Example functions
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main() {
    check(add(2, 2) == 4, "add(2,2) == 4");
    check(add(-1, 1) == 0, "add(-1,1) == 0");
    check(sub(5, 3) == 2, "sub(5,3) == 2");
    check(sub(1, 3) == -3, "sub(0,3) == -3");

    if (tests_failed > 0) {
        std::cout << "\nTests FAILED: " << tests_failed << "\n";
    } else {
        std::cout << "\nAll tests passed!\n";
    }

    return tests_failed == 0 ? 0 : 1;
}

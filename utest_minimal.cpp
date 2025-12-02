#include <boost/ut.hpp>

int add(int, int);

int main() {
    using namespace boost::ut;

    "basic addition"_test = [] {
        expect(add(2,3) == 5_i);
    };
}

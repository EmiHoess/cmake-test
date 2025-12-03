#include <boost/ut.hpp>

int add(int, int);

int main() {
    using namespace boost::ut;

    "basicc addition"_test = [] {
        expect(add(2,3) == 5_i);
    };

    "basicc addition2"_test = [] {
        expect(add(3,3) == 5_i);
    };
}

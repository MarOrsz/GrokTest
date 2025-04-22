#include <iostream>
#include "debug_example.cpp"



int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    process(numbers);
    sort(numbers);
    for (const int& x : numbers) {
        std::cout << x << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>

void process(std::vector<int>& data) {
    for (int i = 0; i <= data.size(); ++i) {
        data[i] *= 2;
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    process(numbers);
    for (const int& x : numbers) {
        std::cout << x << " ";
    }
    return 0;
}
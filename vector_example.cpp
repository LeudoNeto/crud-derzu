#include <iostream>
#include <vector>

std::vector<int> getVector() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    return vec;
}

int main() {
    std::vector<int> result = getVector();
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

void unique(std::vector<int> &v)
{
    std::sort(v.begin(), v.end());
    auto result = std::unique(begin(v), end(v));
    v.erase(result, v.end());
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача 1. Уникальный вектор.\n";

    std::vector<int> vec{ 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "\n[IN]:\t";
    for (auto& it : vec)
    {
        std::cout << it << " ";
    }

    unique(vec);

    std::cout << "\n[OUT]:\t";
    for (auto& it : vec)
    {
        std::cout << it << " ";
    }

}
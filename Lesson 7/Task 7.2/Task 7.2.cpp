#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача 2. Удаление дубликатов.\n";

    int size, number;
    std::cout << "\n[IN]:\n";
    std::cin >> size;

    std::vector<int> vec;
    for (int i = 0; i < size; i++)
    {
        std::cin >> number;
        vec.push_back(number);
    }

    std::sort(vec.begin(), vec.end(), std::greater<>());
    auto result = std::unique(begin(vec), end(vec)); 
    
    std::cout << "\n[OUT]:\n";

    std::for_each(begin(vec), result, [](int it)
        {
            std::cout << it << "\n";
        });
    
}
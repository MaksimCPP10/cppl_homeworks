#include <iostream>
#include <vector>
#include <functional>



int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №1. Лямбда-функция.\n";

    std::vector<int> v1 {4, 7, 9, 14, 12};

    std::cout << "\nВходные данные: ";

    for (auto a : v1)
    {
        std::cout << a << " ";
    }

    std::cout << "\nВыходные данные: ";

    auto lambda=[](std::vector<int> &vec)
    {
        for (auto &a : vec)
        {
            if (a % 2 == 1)
            {
                a *= 3;
                std::cout << a << " ";
            }
            else
            {
                std::cout << a << " ";
            }
        }

    };

    lambda(v1);

    std::cout << "\n";    
}
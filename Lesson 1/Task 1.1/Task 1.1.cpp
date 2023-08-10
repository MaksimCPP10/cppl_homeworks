#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

void print(int a)
{
    std::cout << a << " ";
}

void check(int &a)    
{
    if (a % 2 == 1) { a *= 3; }
    print(a);
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №1. Лямбда-функция.\n";

    std::vector<int> v1 {4, 7, 9, 14, 12};

    std::cout << "\nВходные данные: ";

    for_each(begin(v1), end(v1), print);
    
    std::cout << "\nВыходные данные: ";

    auto lambda=[](std::vector<int> &vec)
    {
        for_each(begin(vec), end(vec), check);
    };

    lambda(v1);

    std::cout << "\n";    
}
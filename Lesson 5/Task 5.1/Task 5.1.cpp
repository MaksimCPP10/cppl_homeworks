#include <iostream>
#include <vector>

template <typename T>
T square(T a)
{
    return a * a;
}
template <>
std::vector<int> square(std::vector<int> vec)
{
    for (auto &element : vec)
    {
        element *= element;
    }
    return vec;
}


int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №1. Возведение в квадрат.\n";

    int number=4;

    std::cout << "\nПример работы шаблонной функции для простых чисел.\n";    
    
    std::cout << "\n[IN]:\t" << number;
    std::cout << "\n[OUT]:\t"<< square(number) << "\n";

    std::cout << "\nПример работы шаблонной функции для std::vector.\n";  
        
    std::vector<int> vec {-1,4,8};

    std::cout << "\n[IN]:\t{ ";
    for(auto element:vec)
    {
        std::cout << element << ", ";
    }
    std::cout << "\b\b }";

    std::vector<int> vec1 = square(vec);

    std::cout << "\n[OUT]:\t{ ";
    for (auto element : vec1)
    {
        std::cout << element << ", ";
    }
    std::cout << "\b\b }\n";    
}
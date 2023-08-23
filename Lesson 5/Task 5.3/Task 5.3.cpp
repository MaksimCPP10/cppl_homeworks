#include <iostream>

class MyFunctor
{
    int sum = 0;
    int count = 0;

public:

    void operator ()(int value)
    {
        if (value % 3 == 0)
        {
            sum += value;
            count++;
        }
    }

    void get_sum()
    {
        std::cout << "\n[OUT]: get_sum = " << sum;
    }

    void get_count()
    {
        std::cout << "\n[OUT]: get_count = " << count;
    }
};

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №3. Счетчик чисел.\n";

    int arr[] = { 4, 1, 3, 6, 25, 54 };

    std::cout << "\n[IN]: ";
    for (auto element : arr)
    {
        std::cout << element << " ";
    }

    MyFunctor f;

    for (auto element : arr)
    {
        f(element);
    }

    f.get_sum();
    f.get_count();

    std::cout << "\n";
}
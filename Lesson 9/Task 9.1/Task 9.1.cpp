#include <iostream>
#include <vector>
#include <string>

template <typename T>
void move_vectors(std::vector<T> &vec1, std::vector<T> &vec2)
{
    std::vector<T> tmp = std::move(vec1);
    vec1 = std::move(vec2);
    vec2 = std::move(tmp);
};

template <class T>
void print_container(T& cont)
{
    for (auto& it : cont)
    {
        std::cout << it << ", ";
    }
    std::cout << "\b\b;\n";
};

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача 1. Перемещение объектов.\n";

    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;

    std::cout << "\nСодержимое контейнера std::vector <std::string> one:\t";
    print_container(one);

    move_vectors(one, two);

    std::cout << "\nСодержимое контейнера std::vector <std::string> two:\t";
    print_container(two);

    std::cout << "\n";

}
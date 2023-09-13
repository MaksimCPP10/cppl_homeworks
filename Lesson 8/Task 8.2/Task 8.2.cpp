#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <string>

template <class T>
void print_container(T &cont)
{
    for (auto& it : cont)
    {
        std::cout << it << ", ";
    }
    std::cout<<"\b\b;\n";
};
int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача 2. Печать контейнера.\n";

    std::cout << "\nПечать контейнера std::set:\t";
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);

    std::cout << "\nПечать контейнера std::list:\t";
    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::cout << "\nПечать контейнера std::vector:\t";
    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);

}
#include <iostream>
#include <map>
#include <string>

typedef std::pair<char, int> pair;

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №1. Частота символов.\n";

    std::string phrase = { "Hello world!!" };

    std::cout << "\n[IN]:\t" << phrase;

    std::cout << "\n[OUT]:";

    std::map<char, int> symb;
    
    for (const char &it : phrase)
    {
        symb[it]++;        
    } 

    std::multimap<int, char, std::greater<>> sym;

    for (const auto& pair : symb)
    {
        sym.insert(std::make_pair(pair.second, pair.first));
    }
        
    for (const auto &pair : sym)
    {
        std::cout << "\n" << "\'" << pair.second << "\'" << " :  " << pair.first;
    }
 
    std::cout << "\n";

}
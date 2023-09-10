#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

void sort_map(std::map<char, int>& S)
{
    std::vector < std::pair <char, int> > vec;
    for (auto& it : S)
        vec.push_back(it);

    sort (vec.begin(), vec.end());

    for (auto& it : vec)
    {
        std::cout << "\n" << "\'" << it.first << "\'" << " :  " << it.second;
    }
}


int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №1. Частота символов.\n";

    std::string phrase = { "Hello world!!" };

    std::cout << "\n[IN]:\t" << phrase;

    std::cout << "\n[OUT]:";

    std::map<char, int> symb;
    
    for (auto it : phrase)
    {
        symb[it]++;        
    } 
       
    //sort_map(symb);
    /*
    for (auto& it : symb)
    {
        std::cout << "\n" << "\'" << it.first << "\'" << " :  " << it.second;
    }
   */
    for (auto it=symb.begin(); it!=symb.end(); it++)
    {
        std::cout << "\n" << "\'" << it->first << "\'" << " :  " << it->second;
    }
    

}
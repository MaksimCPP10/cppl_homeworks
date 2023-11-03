#include <iostream>
#include <string>
#include <deque>
#include <iterator>

class big_integer
{
private:
    std::string value;
    std::deque<unsigned> result;

public:
    big_integer(){}
    
    big_integer(big_integer&& other) noexcept
    {
        this->value = other.value;
        other.value = "";
    }

    big_integer& operator = (big_integer&& other) noexcept
    {
        if (&other == this) { return *this; }
        this->value = other.value;
        other.value = "";
        return *this;
    }

    big_integer(std::string str) 
    {
        for (auto& n : str)
            
            dec.push_back(n-'0');
        
    };

    big_integer& operator + (const big_integer& other)
    {
        big_integer sum;
        auto size = std::max(dec.size(), other.dec.size());
        if (dec.size() < size) 
        { 
            for (int i=0; i<(size - dec.size()); i++)
            dec.push_front(0); 
        }
        if (other.dec.size() < size) 
        { 
            for (int i = 0; i < (size - other.dec.size()); i++)
                other.dec.push_front();
        }
        for (auto i = size; i!=0; i--)
        {
            auto flag = 0;
            auto a = i > dec.size() ? 0 : dec[i];
            auto b = i > other.dec.size() ? 0 : other.dec[i];
            result.push_back((a + b + flag) % 10);
            flag = ((a + b + flag) / 10);

        }
        std::cout << "\n";
        for (auto& i : result)
            std::cout << i;

        return result;
    }
       
    big_integer operator * (const big_integer& other)
    {

    }
    
    big_integer(const big_integer& other)
    {

    }
        
    ~big_integer(){}

};

std::ostream& operator << (std::ostream& os, const big_integer& result)
{    
    return os << result;
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача 2. Большие числа.\n";

    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result;
    
}
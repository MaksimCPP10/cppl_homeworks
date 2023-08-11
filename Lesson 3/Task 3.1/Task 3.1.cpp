#include <iostream>
#include <exception>

class smart_array
{
private:
    int* arr = nullptr;
    int size, n=0;
public:
    smart_array(int arr_size)
    {
        size = arr_size;
        arr = new int[size] {0};
        std::cout << "\nСоздан массив int arr[" << size << "] {0}.\n";
    }

    void add_element(int a)
    {
        if (n < 0 || n >= size)
        {
            throw std::exception("\n\aПопытка добавить элемент, выходящий за \"границы\" массива!\n");
        }
        else { arr[n] = a; n++; }
    }

    int get_element(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::exception("\n\aПопытка получить данные, находящиеся за \"границами\" массива!\n");
        }
        else { return arr[index]; }
    }
    
    ~smart_array()
    {
        delete[] arr;
        std::cout << "\nУдаление массива arr[].\n";
    }
};

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №1. Умный массив.\n";

    int value, size = 5;      

    smart_array arr(size);
       
        try
        {
            std::cout << "\nДобавление значения элемента в массив:\n";
            for (int i = 0; i <= size; i++)
            {                
                value=rand()%100;
                arr.add_element(value);
                std::cout << "arr[" << i << "]\n";
            }                        
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what();
        } 

        try
        {
            std::cout << "\nПолучение значения элемента массива по индексу:\n";
            for (int i = 0; i <= size; i++)
            {
                std::cout << "Элемент массива arr[" << i << "] = " << arr.get_element(i) << "\n";
            }
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what();
        }
}
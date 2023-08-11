#include <iostream>
#include <exception>

class smart_array
{
private:
    int* arr = nullptr;
    int size, n = 0;
    
public: 
    smart_array(const int arr_size)
    {
        static int count_obj = 0;
        size = arr_size;
        arr = new int[size] {0};
        count_obj += 1;
        if (count_obj == 1)
        {
            std::cout << "\nСоздан массив int arr[" << size << "] {0}.\n";
        }
        else
        {
            std::cout << "\nСоздан массив int new_arr[" << size << "] {0}.\n";
        }
    }

   smart_array operator =(const smart_array& other)
   {
        arr = nullptr;
        arr = new int[other.size];
        for (int i = 0; i < other.size; i++)
        {
            arr[i] = other.arr[i];
        }
        return *arr;
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
        static int count_del = 0;
        delete[] arr;
        
        if (count_del <= 1)
        {
            std::cout << "\nУдаление массива arr[].\n";
        }
        else
        {
            std::cout << "\nУдаление массива new_arr[].\n";
        }
        count_del += 1;
    }
};

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №2. Копирование \"умных\" массивов.\n";

    int value, size = 5;
    smart_array arr(size);

    std::cout << "\nДобавление значения элемента в массив arr[]:\n";
    for (int i = 0; i < size; i++)
    {
        value = rand() % 100;
        arr.add_element(value);
        std::cout << "arr[" << i << "] = " << value << ";\n";
    }

    size = 2;
    smart_array new_arr(size);

    std::cout << "\nДобавление значения элемента в массив new_arr[]:\n";
    for (int i = 0; i < size; i++)
    {
        value = rand() % 100;
        new_arr.add_element(value);
        std::cout << "new_arr[" << i << "] = " << value << ";\n";
    }

    std::cout << "\narr[] = new_arr[]\n";

    arr = new_arr;

    std::cout << "\nПолучение значения элемента массива по индексу:\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "Элемент массива arr[" << i << "] = " << arr.get_element(i) << "\n";
    }
}
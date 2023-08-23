#include <iostream>

template<class T>
class Matrix
{
    T** matrix;
    T rows;
    T cols;
public:
    Matrix(T r, T c)
    {
        rows = r, cols = c;
        matrix = new T*[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new T[cols];
        }
    }

    T* operator[](T rows)
    {
        return matrix[rows];
    }   
};

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №2. Таблица.\n";

    Matrix<int> table(2, 3);

    auto test = table;

    test[0][0] = 4;

    std::cout << test[0][0] << std::endl;

}

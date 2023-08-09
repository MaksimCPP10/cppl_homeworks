#include <iostream>

struct point 
{
	int m_x;
	int m_y;	
};

void print_point(const point& point_object) 
{
	std::cout << "x: " << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №1. Программа с ошибками.\n\n";

	point my_point;

	for (int i = 0; i < 5; i++)
	{
		my_point.m_x=i;
		my_point.m_y = i * 2;
		print_point(my_point);
	}
	return 0;
}
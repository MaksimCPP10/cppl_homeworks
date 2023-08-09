#include <iostream>
#include <string>
#include <vector>
#include <variant>

std::variant<int, std::string, std::vector<int>> get_variant() 
{
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №2. std::variant.\n";

	auto result = get_variant();

	int index = result.index();
	
	if (index == 0)
	{
		auto output = std::get<int>(result);
		std::cout << "\nРезультатом работы get_variant() является число: " << output * 2 << "\n";
	}
	else if(index==1)
	{
		auto output = std::get<std::string>(result);
		std::cout << "\nРезультатом работы get_variant() является строка: \"" << output << "\"\n";
	}
	else
	{
		auto output = std::get<std::vector<int>>(result);
		std::cout << "\nРезультатом работы get_variant() является vector: ";
		for (int val : output)
			std::cout << val << " ";	
	}

	std::cout << "\n";
}
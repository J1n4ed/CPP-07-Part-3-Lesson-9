// main function

#include <iostream>
#include <vector>
#include <Windows.h>

template<typename T>
void swap_vectors(std::vector<T>& first, std::vector<T>& second)
{
	std::vector<T> tmp = std::move(first);
	first = std::move(second);
	second = std::move(tmp);
} // END OF swap_vectors()

template<typename T>
void move_vectors(std::vector<T>& first, std::vector<T>& second)
{	
	second = std::move(first);
}

int main(int argc, char** argv)
{
	// CMD

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// VAR

	std::vector<int> vec_int_1{ 1, 2, 3, 4, 5 };
	std::vector<int> vec_int_2{ 10, 20, 30, 40, 50 };

	std::vector<double> vec_dbl_1{ 1.5, 2.5, 3.5, 4.5, 5.5 };
	std::vector<double> vec_dbl_2{ 10.5, 20.5, 30.5, 40.5, 50.5 };

	// на этом моменте я понял что нужно не swap а move...

	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;

	// BODY

	std::cout << "--------------------- VECTOR<INT> ---------------------\n\n";

	std::cout << "Первый массив (int):\n";

	for (const auto& element : vec_int_1)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	std::cout << "Второй массив (int):\n";

	for (const auto& element : vec_int_2)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	// swap call

	swap_vectors(vec_int_1, vec_int_2);

	// print swapped

	std::cout << "\n- SWAP - \n\n";

	std::cout << "Первый массив (int):\n";

	for (const auto& element : vec_int_1)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	std::cout << "Второй массив (int):\n";

	for (const auto& element : vec_int_2)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	// Double test

	std::cout << "--------------------- VECTOR<DOUBLE> ---------------------\n\n";

	std::cout << "Первый массив (double):\n";

	for (const auto& element : vec_dbl_1)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	std::cout << "Второй массив (double):\n";

	for (const auto& element : vec_dbl_2)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	// swap call

	swap_vectors(vec_dbl_1, vec_dbl_2);

	// print swapped

	std::cout << "\n- SWAP - \n\n";

	std::cout << "Первый массив (double):\n";

	for (const auto& element : vec_dbl_1)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	std::cout << "Второй массив (double):\n";

	for (const auto& element : vec_dbl_2)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	// move...

	std::cout << "--------------------- MOVE ---------------------\n\n";

	std::cout << "Первый массив (std:;string):\n";

	for (const auto& element : one)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	std::cout << "Второй массив (std:;string):\n";

	for (const auto& element : two)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	// swap call

	move_vectors(one, two);

	// print swapped

	std::cout << "\n- MOVE - \n\n";

	std::cout << "Первый массив (std:;string):\n";

	for (const auto& element : one)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	std::cout << "Второй массив (std:;string):\n";

	for (const auto& element : two)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;

	// EXIT

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;

} // END OF main()
// Main function

#include "..\headers\bignum.hpp"
#include <iostream>
#include <Windows.h>

int main(int argc, char** argv)
{
	// CMD

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// VAR

	jinx::bignum myNum1("12345");
	jinx::bignum myNum2("6789");

	// BODY

	std::cout << "Дано два числа:\n\n";

	std::cout << "1: "; myNum1.print(); std::cout << '\n';
	std::cout << "2: "; myNum2.print(); std::cout << '\n';

	std::cout << "\nЧистый вывод _num:\n\n";

	std::cout << "1: "; myNum1.raw_print(); std::cout << '\n';
	std::cout << "2: "; myNum2.raw_print(); std::cout << '\n';	
	
	std::cout << std::endl << "\nОперации над числами:\n\n";
	
	std::cout << "myNum1 = myNum1 + myNum2\n";
	
	myNum1.print(); std::cout << " = "; myNum1.print(); std::cout << " + "; myNum2.print();

	myNum1 = myNum1 + myNum2;
	std::cout << "\nmyNum1 = ";
	myNum1.print(); std::cout << " [ANSWER]";
	std::cout << "\nraw _num = ";
	myNum1.raw_print();

	std::cout << "\n\n";

	std::cout << "myNum2 = myNum2 + myNum1\n";
	myNum2.print(); std::cout << " = "; myNum2.print(); std::cout << " + "; myNum1.print();
	myNum2 = myNum2 + myNum1;
	std::cout << "\nmyNum2 = ";
	myNum2.print(); std::cout << " [ANSWER]";
	std::cout << "\nraw _num = ";
	myNum2.raw_print();

	// DEBUG Пример с задания

	std::cout << "\n\n";

	std::cout << "Сложение 2:\n";

	auto number1 = jinx::bignum("114575");
	auto number2 = jinx::bignum("78524");
	std::cout << "result = " << number1 << " + " << number2;
	auto result = number1 + number2;

	std::cout << "\nresult = " << result; // 193099

	// Умножение

	std::cout << "\n\n";
	std::cout << "Умножение:\n";

	auto someNum1 = jinx::bignum("1024");
	auto someNum2 = jinx::bignum("4");
	std::cout << "resultMult = " << someNum1 << " * " << someNum2;

	auto resultMult = someNum1 * someNum2;

	std::cout << "\nresultMult = " << resultMult; // 4096

	// REAL BIG NUM CHECK

	std::cout << "\n\n";
	std::cout << "Проверка реально большими числами\n";

	auto realBigNum1 = jinx::bignum("55555555555000000000000002222222222333333333335555555555");
	auto realBigNum2 = jinx::bignum("22222222222999999999933333333377777777");

	std::cout << "realBigNum1: "; realBigNum1.print(); std::cout << '\n';
	std::cout << "realBigNum2: "; realBigNum2.print(); std::cout << '\n';
	
	std::cout << "\nrealBigResult = " << realBigNum1 << " + " << realBigNum2 << '\n';
	auto realBigResult = realBigNum1 + realBigNum2;

	std::cout << "\nrealBigResult = " << realBigResult; std::cout << '\n' << '\n';

	std::cout << "realBigMult = " << realBigNum1 << " * " << realBigNum2 << '\n';
	auto realBigMult = realBigNum1 * realBigNum2;

	std::cout << "\nrealBigMult = " << realBigMult;

	// EXIT

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;

} // END OF main()
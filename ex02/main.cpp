#include "./hpp/Array.hpp"

void	test_empty_array()
{
	std::cout << "--- Empty array ---" << std::endl;
	Array<int> array;
	std::cout << "array.size = " << array.size() << std::endl;
	std::cout << std::endl;
}

void	test_create_array(unsigned int i)
{
	std::cout << "--- Create array int ---" << std::endl;
	Array<int> array(i);
	std::cout << "array.size = " << array.size() << std::endl;
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	std::cout << std::endl;
}

void	test_array_int()
{
	std::cout << "--- Array int ---" << std::endl;
	Array<int> array(3);
	std::cout << "array.size = " << array.size() << std::endl;
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	std::cout << std::endl;
}

void	test_array_char()
{
	std::cout << "--- Array char ---" << std::endl;
	Array<char> array(3);
	std::cout << "array.size = " << array.size() << std::endl;
	array[0] = 'a';
	array[1] = 'b';
	array[2] = 'c';
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	std::cout << std::endl;
}

void	test_invalid_index()
{
	std::cout << "--- Invalid index ---" << std::endl;
	Array<int> array(3);
	std::cout << "array.size = " << array.size() << std::endl;
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	for (unsigned int i = 0; i < 5; i++)
	{
		try {
			std::cout << "array[" << i << "] = " << array[i] << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}

void	test_copy_constructor()
{
	std::cout << "--- Copy constructor ---" << std::endl;
	Array<int> array(3);
	std::cout << "array.size = " << array.size() << std::endl;
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	Array<int> array2(array);
	std::cout << "array2.size = " << array2.size() << std::endl;
	for (unsigned int i = 0; i < array2.size(); i++)
		std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
	std::cout << "Change array[0] = 42" << std::endl;
	array[0] = 42;
	std::cout << "array[0] = " << array[0] << std::endl;
	std::cout << "array2[0] = " << array2[0] << std::endl;
	std::cout << std::endl;
}

void	test_copy_assignation()
{
	std::cout << "--- Copy assignation ---" << std::endl;
	Array<int> array(3);
	std::cout << "array.size = " << array.size() << std::endl;
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	Array<int> array2 = array;
	std::cout << "array2.size = " << array2.size() << std::endl;
	for (unsigned int i = 0; i < array2.size(); i++)
		std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
	std::cout << "Change array[0] = 42" << std::endl;
	array[0] = 42;
	std::cout << "array[0] = " << array[0] << std::endl;
	std::cout << "array2[0] = " << array2[0] << std::endl;
	std::cout << std::endl;
}

int main(int, char**)
{

	{
		
		test_empty_array();
		test_create_array(3);
		test_array_int();
		test_array_char();
		test_invalid_index();
		test_copy_constructor();
		test_copy_assignation();
		
	}


	return 0;
}
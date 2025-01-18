#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750

void	testEmptyInit(unsigned int n)
{
	Array<std::string>	test(n);

	std::cout << test << "END.\n";	
}

void	testTwoClasses( void )
{
	Array<int>	me(5);
	Array<int>	you(me);
	Array<int>	us = me;

	for (int i = 0; i < 5; i++)
		me[i] = i;
	for (int i = 0; i < 5; i++)
		you[i] = i + 5;
	for (int i = 0; i < 5; i++)
		us[i] = i + 10;
	std::cout << GREY << "me is " << NEUTRAL << me << '\n';
	std::cout << GREY << "you is " << NEUTRAL << you << '\n';
	std::cout << GREY << "us is " << NEUTRAL << us << '\n';

	me = you;
	std::cout << "me = you and printing me\n" << me << '\n';
}


int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	std::cout
	<< MAGENTA << "\t\t\tPERSONAL TESTS\n" << NEUTRAL
	<< GREY << "Initializing an Array of size 10 with empty strings...\n" << NEUTRAL;
	{
		testEmptyInit(10);
	}
	{
		testTwoClasses();
	}
    return 0;
}
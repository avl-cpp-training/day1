// app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "../lib/public.h"
#include "../dll2/public.h"
#include "Windows.h"

typedef double(*GETVALUEFUNC)(int value);

GETVALUEFUNC getValueFunc;

int main()
{
	std::cout << static_lib::get_value(10);
	std::cout << "\n";
	std::cout << get_value(10);
	std::cout << "\n";
	HMODULE dynLib = LoadLibraryA("dynamic_library.dll");
	getValueFunc = (GETVALUEFUNC)GetProcAddress(dynLib, "get_value");
	auto x = (double(*)(int value))GetProcAddress(dynLib, "get_value");
	std::cout << x(10);
	std::cout << "\n";
	std::cout << getValueFunc(10);
	FreeLibrary(dynLib);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

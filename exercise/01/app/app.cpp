// app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "..\lib\public.h"
#include "..\dll2\public.h"
#include <windows.h>

typedef double(__cdecl *func)(int);
const int value = 10;

int main()
{
    std::cout << "call get_value from .lib\n"; 
    std::cout << static_lib::get_value(value) << std::endl;

    std::cout << "call get_value from .dll\n";

    HMODULE dynamicLibrary;
    func procAddress;
    LPCSTR libraryToLoad = "dynamic_library.dll";
    LPCSTR funcToLoad = "get_value";

    dynamicLibrary = LoadLibraryA(libraryToLoad);
    if (dynamicLibrary != NULL)
    {
      procAddress = (func)GetProcAddress(dynamicLibrary, funcToLoad);

      if (procAddress != NULL)
      {
        std::cout << procAddress(value) << std::endl;
      }
      else
      {
        std::cout << "No function with name " << funcToLoad << " found." << std::endl;
      }

      FreeLibrary(dynamicLibrary);
    }
    else 
    {
      std::cout << "No .dll with name " << libraryToLoad << " found." << std::endl;
    }

    std::cout << "call get_value from .dll with implib\n";
    std::cout << get_value(value) << std::endl;
}

/*
Napravite projekt app (.exe) u folderu app koji poziva i ispisuje rezultat:

funkcije get_value iz static_library.lib (lib/public.h)
funkcije get_value iz dynamic_library.dll (potpis: double get_value(int))
funkcije get_value iz dynamic_library_with_implib.dll (dll2/public.h)
Uputstva:

za dynamic_library.dll trebat će vam Windows API funkcije LoadLibrary, GetProcAddress, FreeLibrary.
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

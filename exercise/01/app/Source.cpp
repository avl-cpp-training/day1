#include <iostream>
#include "../lib/public.h"  // public.h from static library
#include "../dll2/public.h" // public.h from implib dll
#include <Windows.h>


int main()
{
  std::cout << "Static library: " << static_lib::get_value(1) << std::endl;
  std::cout << "Dynamic library with implib: " << get_value(1) << std::endl;
  const HMODULE handle = LoadLibraryA("dynamic_library.dll");
  if (0 == handle)
  {
    std::cout << "failed to load dll" << std::endl;
    return 1;
  }
  
  typedef double(*LPGETVALUE)(int input);
  LPGETVALUE function;
  function = (LPGETVALUE) GetProcAddress(handle, "get_value");
  std::cout << "Dynamic library: " << function(1) << std::endl;
  FreeLibrary(handle);
  return 0;
}
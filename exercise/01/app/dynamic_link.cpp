#include "pch.h"
#include "dynamic_link.h"
#include <Windows.h>


double no_implib::get_value(int input)
{
  using get_value_func = double(*)(int) ;
  HMODULE module = LoadLibraryA("dynamic_library.dll");
  get_value_func func = (get_value_func)GetProcAddress(module, "get_value");
  return func(input);
}
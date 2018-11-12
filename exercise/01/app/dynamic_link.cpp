#include "pch.h"
#include "dynamic_link.h"
#include <Windows.h>
#include <exception>


double no_implib::get_value(int input)
{
  using get_value_func = double(*)(int) ;
  HMODULE module = LoadLibraryA("dynamic_library.dll");
  if (!module)
    throw "no dll";
  get_value_func func = (get_value_func)GetProcAddress(module, "get_value");
  if (!func)
    throw "no get_value function found in dynamic_library.dll";
  return func(input);
}
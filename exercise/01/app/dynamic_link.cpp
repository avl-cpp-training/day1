#include "pch.h"
#include "dynamic_link.h"
#include <Windows.h>
#include <exception>



double no_implib::get_value(int input)
{
  struct scoped_library
  {
    HMODULE module;
    scoped_library()
    {
      module = LoadLibraryA("dynamic_library.dll");
    }
    ~scoped_library() { if(module) FreeLibrary(module); }

  } loader;
  using get_value_func = double(*)(int) ;
  if (!loader.module)
    throw "no dll";
  get_value_func func = (get_value_func)GetProcAddress(loader.module, "get_value");
  if (!func)
    throw "no get_value function found in dynamic_library.dll";
  return func(input);
}
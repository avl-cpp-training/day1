#include <iostream>
#include "../lib/public.h"  // public.h from static library
#include "../dll2/public.h" // public.h from implib dll
#include <Windows.h>
  
struct function_wrapper
{
  function_wrapper(std::string const& path, std::string const& function)
  {
    m_handle = LoadLibraryA(path.c_str());
    if (nullptr == m_handle)
    {
      throw std::invalid_argument("invalid path to target dll");
    }
    m_function = reinterpret_cast<function_t>(::GetProcAddress(m_handle, function.c_str()));
    if (nullptr == m_function)
    {
      throw std::invalid_argument("invalid function argument");
    }
  }

  ~function_wrapper()
  {
    ::FreeLibrary(m_handle);
  }

  double operator()(const int arg) const
  {
    return m_function(arg);
  }

private:
  typedef double(*function_t)(int input);
  function_t m_function;
  HMODULE m_handle;
};

namespace dynamic_lib
{
  const function_wrapper get_value("dynamic_library.dll", "get_value");
}


int main()
{
  std::cout << "Static library: " << static_lib::get_value(1) << std::endl;
  std::cout << "Dynamic library without implib: " << dynamic_lib::get_value(1) << std::endl;
  std::cout << "Dynamic library with implib: " << get_value(1) << std::endl;
  
  return 0;
}
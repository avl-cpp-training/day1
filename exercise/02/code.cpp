#include "stdafx.h"
#include "code.h"
#include <algorithm>

void f1(int& a, int& b)
{
  using std::swap;
  swap(a, b);
}

void f2(int* begin, int* end)
{
  std::for_each(begin, end, [](auto& arg) {return ++arg; });
}

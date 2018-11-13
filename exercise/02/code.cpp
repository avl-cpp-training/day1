#include "stdafx.h"
#include "code.h"
#include <algorithm>

void f1(int & a, int & b)
{
  a = 2;
  b = 1;
}

void f2(int* first, int* last)
{
  std::transform(first, last, first, [](int i) {return i + 1; });
}

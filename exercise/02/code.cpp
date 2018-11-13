#include "stdafx.h"
#include "code.h"

void f1(int& a, int& b)
{
  auto c = a;
  a = b;
  b = c;
}

void f2(int* a, const int* b)
{
  while (a != b)
  {
    *a = *a + 1;
    ++a;
  }
}

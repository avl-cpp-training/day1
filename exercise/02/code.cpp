#include "stdafx.h"
#include "code.h"

void f1(int& a, int& b)
{
  a += b;
  b = a - b;
  a = a - b;
}

void f2(int *begin, const int *const end)
{
  for (; begin < end; begin++)
    (*begin)++;
}

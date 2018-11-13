#include "stdafx.h"
#include "code.h"

void f1(int& a, int& b)
{
  using std::swap;
  swap(a, b);
}

void f2(int* begin, int* end)
{
  while (begin < end)
  {
    ++(*begin);
    ++begin;
  }
}

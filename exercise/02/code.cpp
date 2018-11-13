#include "stdafx.h"
#include "code.h"

void f1 (int &a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

void f2(int* const begin, int* const end)
{
  for (auto i=begin; i < end; ++i)
  {
    ++*i;
  }
}
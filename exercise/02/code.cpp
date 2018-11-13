#include "stdafx.h"
#include "code.h"

void f1(int & a, int & b)
{
	std::swap(a, b);
}

void f2(int * arr, int * end)
{
	std::transform(arr, end, arr, [](int num) -> int { return ++num; });
}
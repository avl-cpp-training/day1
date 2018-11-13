#include "stdafx.h"
#include "code.h"
#include <algorithm>

void f1(int& a, int& b)
{
	std::swap(a, b);
}

void f2(int* begin, int* end)
{
	if (begin > end) return;
	std::transform(begin, end, begin, [](int n) {return n + 1; });
}
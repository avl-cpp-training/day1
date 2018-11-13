#include "stdafx.h"
#include "code.h"

void f1(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void f2(int* first, int* last)
{
	for (; first < last; ++first)
		++(*first);
}


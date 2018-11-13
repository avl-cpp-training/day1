#include "stdafx.h"
#include "code.h"

#include <utility>

void f1(int& a, int& b)
{
    std::swap(a, b);
}

void f2(int* const begin, int* const end)
{
    for (auto it = begin; it != end; ++it)
        ++(*it);
}

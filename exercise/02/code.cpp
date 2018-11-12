#include "stdafx.h"
#include "code.h"

void f1(int* pa, int* pb) {
  *pa += *pb;
  *pb = *pa - *pb;
  *pa -= *pb;
}

void f2(int* startValuePointer, int* endValuePointer) {
  if (startValuePointer && endValuePointer)
  {
    int iterateNum = endValuePointer - startValuePointer;

    for (int i = 0; i < iterateNum; ++i)
    {
      (*(startValuePointer + i))++;
    }
  }
}
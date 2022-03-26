#ifndef PROBLEM 
#define PROBLEM

#include <vector>
#include <iostream>
#include "solucion.h"

class Problem {
 public:
  Problem();
  virtual ~Problem();
  virtual void print() = 0;
  virtual int getSize() = 0;
};

#endif
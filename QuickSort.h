#ifndef QUICK_SORT_
#define QUICK_SORT_

#include "divide.h"
#include "vectorProblem.h"
#include "vectorSolucion.h"

class QuickSort : public Framework {
 public:
  QuickSort();
  ~QuickSort();

  bool isSmall(Problem* p);
  std::pair<Problem*,Problem*> Divide(Problem* p);
  void SolveSmall(Problem* p, Solution* s);
  void combine(std::pair<Solution*, Solution*> subSolutions, Solution* s);
  std::string getA();
  std::string getB();
  std::string getC();
 private:
};

#endif
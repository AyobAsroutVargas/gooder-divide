#ifndef MERGE_SORT
#define MERGE_SORT

#include <climits>
#include "divide.h"
#include "vectorProblem.h"
#include "vectorSolucion.h"

class MergeSort : public Framework {
 public:
  MergeSort();
  ~MergeSort();

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
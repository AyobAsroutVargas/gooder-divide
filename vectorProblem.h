#ifndef VECTOR_PROBLEM
#define VECTOR_PROBLEM

#include <vector>
#include "problema.h"

class VectorProblem : public Problem {
 public:
  VectorProblem(std::vector<int> vector);
  ~VectorProblem();
  void print();
  int getSize();
  std::vector<int> vector_;
};

#endif
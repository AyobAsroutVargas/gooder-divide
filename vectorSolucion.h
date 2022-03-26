#ifndef VECTOR_SOLUTION
#define VECTOR_SOLUTION

#include <vector>
#include "solucion.h"

class VectorSolution : public Solution {
 public:
  VectorSolution();
  ~VectorSolution();
  void print();
  Solution* getInstance();
  std::vector<int> vector_;
};

#endif
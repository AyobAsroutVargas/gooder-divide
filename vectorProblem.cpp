#include "vectorProblem.h"

VectorProblem::VectorProblem(std::vector<int> vector) {
  vector_.assign(vector.begin(), vector.end());
}

VectorProblem::~VectorProblem(){
  
}
int VectorProblem::getSize(){
  return vector_.size();
}

void VectorProblem::print(){
  for (auto element : vector_) {
    std::cout << element << ", ";
  }
  std::cout << "\n";
}
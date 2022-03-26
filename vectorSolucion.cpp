#include "vectorSolucion.h"

VectorSolution::VectorSolution(){
  
}

VectorSolution::~VectorSolution(){
    
}

void VectorSolution::print(){
  for (auto element : vector_) {
    std::cout << element << " ";
  }
  std::cout << "\n";
}

Solution* VectorSolution::getInstance(){
  return new VectorSolution();
}
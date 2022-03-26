#include "generator.h"

std::vector<int> RandomVectorGenerator::generateInstance(int size) {
  std::vector<int> randomVector(size, 0);
  srand((unsigned) time(NULL));
  for (int i = 0; i < size; i++) {
    randomVector[i] = rand();
  }
  return randomVector;
}
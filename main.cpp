#include "mergeSort.h"
#include "generator.h"
#include "QuickSort.h"

int main(int argc, char **argv) {
  std::vector<int> definedVector;
  MergeSort* mergeSort = new MergeSort();
  QuickSort* quickSort = new QuickSort();
  std::cout << mergeSort->Recurrence() << "\n";
  RandomVectorGenerator generator;
  for (int i = 0; i < 5000; i++) {
    definedVector = generator.generateInstance(i);
    VectorProblem* p = new VectorProblem(definedVector);
    VectorSolution* s1 = new VectorSolution();
    VectorSolution* s2 = new VectorSolution();
    // std::cout << "Initial instance:\n";
    // p->print();
    // std::cout << "\n";
    clock_t t0 = clock();
    mergeSort->Solve(p,s1);
    long double time0 = (long double)(clock() - t0);

    clock_t t1 = clock();
    quickSort->Solve(p, s2);
    long double time1 = (long double)(clock() - t1);

    printf("%14s|%12s|%12s|", "instance size", "merge sort:", "quick sort:");
    std::cout << "\n";
    printf("%14d|%12Lf|%12Lf|", i, time0 / CLOCKS_PER_SEC, time1 / CLOCKS_PER_SEC);
    std::cout << "\n";
    // std::cout << "Solution:\n";
    // s1->print();
    // std::cout << "\n";
  }
  // VectorProblem* p = new VectorProblem(definedVector);
  // VectorSolution* s2 = new VectorSolution();
  // quickSort->Solve(p, s2);
  // std::cout << "Solution:\n";
  // s2->print();
  // std::cout << "\n";
}
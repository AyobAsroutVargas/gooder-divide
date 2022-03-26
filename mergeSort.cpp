#include "mergeSort.h"

MergeSort::MergeSort() {

}

MergeSort::~MergeSort(){
  
}

bool MergeSort::isSmall(Problem* p){
  return (p->getSize() <= 2);
}

std::pair<Problem*,Problem*> MergeSort::Divide(Problem* p){
  std::pair<Problem*,Problem*> subProblems;

  std::vector<int> v1(((VectorProblem*)p)->vector_.cbegin(), ((VectorProblem*)p)->vector_.cbegin() + ((VectorProblem*)p)->vector_.size() / 2);
  std::vector<int> v2(((VectorProblem*)p)->vector_.cbegin() + ((VectorProblem*)p)->vector_.size() / 2, ((VectorProblem*)p)->vector_.cend());

  subProblems.first = new VectorProblem(v1);
  subProblems.second = new VectorProblem(v2);
  return subProblems;
}
void MergeSort::SolveSmall(Problem* p, Solution* s){
  std::vector<int> tempVector = ((VectorProblem*)p)->vector_;
  if (((VectorProblem*)p)->vector_.size() == 1){
    ((VectorSolution*)s)->vector_ = ((VectorProblem*)p)->vector_;
	} else if (((VectorProblem*)p)->vector_.size() == 2) {
		//Swap it if it's not correctly ordered
		if(tempVector[0] > tempVector[1]) {
			int aux = tempVector[0];
			tempVector[0] = tempVector[1];
			tempVector[1] = aux;
		}
		((VectorProblem*)p)->vector_ = tempVector;
  }
  ((VectorSolution*)s)->vector_ = ((VectorProblem*)p)->vector_;
  return;
}
void MergeSort::combine(std::pair<Solution*, Solution*> subSolutions, Solution* s){
  std::vector<int> a1 = (((VectorSolution*)subSolutions.first))->vector_;
  std::vector<int> a2 = (((VectorSolution*)subSolutions.second))->vector_;

  a1.push_back(INT_MAX);
  a2.push_back(INT_MAX);

  int i = 0, j = 0;
  int size = (a1.size() - 1) + (a2.size() - 1);

  ((VectorSolution*)s)->vector_.resize(size);

  for (int iterator = 0; iterator < size; iterator++) {
    if(a1[i] < a2[j]) {
      ((VectorSolution*)s)->vector_[iterator] = a1[i];
      i++;
    } else {
      ((VectorSolution*)s)->vector_[iterator] = a2[j];
      j++;
    }
  }
}

std::string MergeSort::getA(){
  return "2";
}

std::string MergeSort::getB(){
  return "n/2";
}

std::string MergeSort::getC(){
  return "O(n)";
}
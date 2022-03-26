#include "QuickSort.h"

QuickSort::QuickSort(){
    
}
QuickSort::~QuickSort(){
    
}

bool QuickSort::isSmall(Problem* p){
  return (p->getSize() <= 2);
}


std::pair<Problem*,Problem*> QuickSort::Divide(Problem* p){
  int i = 0, j = ((VectorProblem*)p)->vector_.size() - 2;
  int pivotPos = ((VectorProblem*)p)->vector_.size() / 2;
  int endPos = ((VectorProblem*)p)->vector_.size() - 1;
  int pivot = ((VectorProblem*)p)->vector_[pivotPos];
  std::pair<Problem*,Problem*> subProblems;

  //movemos el pivote al final
  int aux = ((VectorProblem*)p)->vector_[endPos];
	((VectorProblem*)p)->vector_[endPos] = pivot;
	((VectorProblem*)p)->vector_[pivotPos] = aux;

  while (i < j) {
    //Buscamos primer elemento mayor que el pivote empezando desde la izquierda
    while (((VectorProblem*)p)->vector_[i] < ((VectorProblem*)p)->vector_[endPos]) {
      i++;
    }
    //Buscamos primer elemento menor que el pivote empezando desde la derecha
    while (((VectorProblem*)p)->vector_[j] > ((VectorProblem*)p)->vector_[endPos]) {
      j--;
    }
    //Si todavia no hemos comprobado todos los elementos intercambiamos los elementos
    if (i < j) {
      int temp = ((VectorProblem*)p)->vector_[j];
      ((VectorProblem*)p)->vector_[j] = ((VectorProblem*)p)->vector_[i];
      ((VectorProblem*)p)->vector_[i] = temp;
    //Si ya hemos revisado todos los elementos, intercambiamos el pivote con el ultimo elemento mayor que el pivote empezando desde la izquierda.
    } else {
      int aux1 = ((VectorProblem*)p)->vector_[endPos];
	    ((VectorProblem*)p)->vector_[endPos] = ((VectorProblem*)p)->vector_[i];
	    ((VectorProblem*)p)->vector_[i] = aux1;
      pivotPos = i;
    }
  }

  std::vector<int> v1;
  std::vector<int> v2;
  for (int it = 0; it < pivotPos; it++) {
    v1.push_back(((VectorProblem*)p)->vector_[it]);
  }
  for (int it = pivotPos; it < ((VectorProblem*)p)->vector_.size(); it++) {
    v2.push_back(((VectorProblem*)p)->vector_[it]);
  }
  subProblems.first = new VectorProblem(v1);
  subProblems.second = new VectorProblem(v2);
  return subProblems;
}


void QuickSort::SolveSmall(Problem* p, Solution* s){
  std::vector<int> tempVector = ((VectorProblem*)p)->vector_;
  if (((VectorProblem*)p)->vector_.size() == 1){
    ((VectorSolution*)s)->vector_ = ((VectorProblem*)p)->vector_;
    return;
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


void QuickSort::combine(std::pair<Solution*, Solution*> subSolutions, Solution* s){
  std::vector<int> tempVector(((VectorSolution*)subSolutions.first)->vector_);
  tempVector.insert(tempVector.end(), ((VectorSolution*)subSolutions.second)->vector_.begin(), ((VectorSolution*)subSolutions.second)->vector_.end());
  ((VectorSolution*)s)->vector_ = tempVector;
}


std::string QuickSort::getA(){
  return "";
}
std::string QuickSort::getB(){
  return "";
}
std::string QuickSort::getC(){
  return "";
}
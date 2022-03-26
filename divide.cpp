#include "divide.h"

Framework::Framework(){

}
Framework::~Framework(){

}

void Framework::Solve(Problem* p, Solution* s) {
  if (this->isSmall(p)) {
    return this->SolveSmall(p, s);
  } else {
    std::pair<Problem*, Problem*> subProblems;
    std::pair<Solution*, Solution*> subSolutions;
    subProblems = this->Divide(p);
    subSolutions.first = s->getInstance();
    subSolutions.second = s->getInstance();
    Solve(subProblems.first, subSolutions.first);
    Solve(subProblems.second, subSolutions.second);
    this->combine(subSolutions, s);
  }
}

std::string Framework::Recurrence() {
  return "T(n) <= " + this->getA() + "T(" + this->getB() + ") + " + this->getC() + "\n";
}
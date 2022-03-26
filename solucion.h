#ifndef SOLUTION
#define SOLUTION

#include <vector>
#include <iostream>

class Solution {
 public:
  Solution();
  virtual ~Solution();

  virtual void print() = 0;
  virtual Solution* getInstance() = 0;
};

#endif
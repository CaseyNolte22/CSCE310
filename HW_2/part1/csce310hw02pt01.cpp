#include "csce310hw02pt01.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> placeNumbers( vector<int> numbers  , string signs ){

  vector<int> solution;

  for (int i = 0; i < signs.length(); i++) {
    if (signs[i] == '<') {
      solution.push_back(numbers[0]);
      numbers.erase(numbers.begin());
    }

    else if (signs [i] == '>') {
      solution.push_back(numbers[numbers.size() - 1]);
      numbers.pop_back(); 
    }

  }

  solution.push_back(numbers[0]);
  
  return solution;
}

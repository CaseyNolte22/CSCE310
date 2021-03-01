#include "csce310hw02pt03.h"
#include <vector>
#include <limits>
#include <cmath>
#include <iostream>

using namespace std;

double closestNumbers(vector<double> numbers)
{
  double closest = std::numeric_limits<double>::infinity();

  for (int i = 0; i < numbers.size(); i++)
  {
    double diff = abs(numbers[i] - numbers[i + 1]);
    
    if ( diff < closest)
    {
      closest = diff;
    }
  }

  return closest;
}

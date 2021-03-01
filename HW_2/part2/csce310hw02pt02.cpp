#include <vector>
#include "csce310hw02pt02.h"
#include <bits/stdc++.h>

using namespace std;

int overlappingIntervals(vector<int> start, vector<int> end)
{
  int maxEnd = 0;
  int minStart = start[0];

  for (int i = 0; i < end.size(); i++)
  {
    if (end[i] > maxEnd)
    {
      maxEnd = end[i];
    }
  }

  int maxCount = 0;
  int count = 0;
  for (int i = minStart; i <= maxEnd; i++)
  {
    count = 0;
    for (int j = 0; j < start.size(); j++)
    {
      if (i >= start[j] && i <= end[j])
      {
        count++;
      }
    }
    if (count > maxCount)
    {
      maxCount = count;
    }
  }

  return maxCount;
}

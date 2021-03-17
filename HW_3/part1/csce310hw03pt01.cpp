#include <vector>
#include "csce310hw03pt01.h"
#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

double maximumST( vector< vector<double> > adjacencyMatrix ){
  vector<int> row(4,-1);
  vector< vector<int> > matrix(5,row);
  cerr << matrix.size() << endl;
  cerr << matrix[0].size() << endl;
  for( int i = 0; i < 5; i++ ){
    for( int j = 0; j < 4; j++ ){
      fprintf( stderr , "% 2d " , matrix[i][j] );
    }
    cerr << endl;
  }
  return 42.0;
}

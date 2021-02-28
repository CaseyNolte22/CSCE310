#include "csce310hw02pt03.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main( int argc , char* argv[] ){
  int num;
  vector<double> numbers;

  while( cin >> num ){
    numbers.push_back( num );
  }

  try{
    fprintf( stdout , "The closest numbers are %f apart.\n" , closestNumbers( numbers ) );
  }
  catch( exception e ){
    cout << "An Error Occurred" << endl;
  }
}

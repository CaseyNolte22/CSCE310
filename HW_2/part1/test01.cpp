#include "csce310hw02pt01.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int indexOf( vector<int> vec , int val ){
  for( int z = 0; z < vec.size(); z++ ){
    if( vec[z] == val ){
      return z;
    }
  }
  return -1;
}

int main( int argc , char* argv[] ){
  int number;
  vector<int> numbers;
  string signs;

  cin >> signs;

  while( cin >> number ){
    numbers.push_back( number );
  }

  vector<bool> used( numbers.size() , false );

  try{
    vector<int> result = placeNumbers( numbers , signs );
    bool okay = true;
    for( int i = 0; i < signs.length(); i++ ){
      cout << result[i];
      if( signs[i] == '<' ){
	cout << " < ";
	int ind = indexOf( numbers , result[i] );
	okay = okay && result[i] < result[i+1] && ind >= 0 & !used[ind];
	used[ind] = true;
      }
      else{
	cout << " > ";
	int ind = indexOf( numbers , result[i] );
	okay = okay && result[i] > result[i+1] && ind >= 0 & !used[ind];
	used[ind] = true;
      }
    }
    cout << result[signs.length()] << endl;
    int ind = indexOf( numbers , result[signs.length()] );
    okay = okay && ind >= 0 & !used[ind];
    used[ind] = true;

    for( int i = 0; i < used.size(); i++ ){
      okay = okay && used[i];
    }

    cout << endl;

    if( okay ){
      cout << "VALID" << endl;
    }
    else{
      cout << "INVALID" << endl;
    }
  }
  catch( exception e ){
    cerr << "An error occurred." << endl;
  }
}

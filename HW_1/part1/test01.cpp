#include "csce310hw01pt01.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main( int argc, char* argv[] )
{
    unsigned long long int num;
    cin >> num;

    try
    {
        fprintf( stdout, "%llu has %llu odd digit(s).\n", num, oddDigits( num ) );
    }
    catch( exception e )
    {
        cerr << "An error occurred." << endl;
    }
}

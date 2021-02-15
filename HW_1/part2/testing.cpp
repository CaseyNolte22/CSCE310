#include <string>
#include <iostream>

using namespace std;

int findLargestMobile(char characters[] , int direc[], int len)
{
    int index = 0;
    char greatest = 'a';
    for (int i = 1; i < len; i++){
        if ((characters[i]>characters[i-1]) && direc[i] == -1 && characters[i]>greatest) {
            greatest = characters[i];
            index = i;
        }
        if ((characters[i]>characters[i+1]) && direc[i] == 1 && characters[i]>greatest) {
            greatest = characters[i];
            index = i;
        }
    }
    return index; 
}

int main()
{
    if ('a'>' '){
        cout << "hi" << endl;
    }
    return 1;
}

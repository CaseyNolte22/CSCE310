#include "csce310hw01pt02.h"
#include <string>
#include <iostream>

using namespace std;

int findLargestMobile(char characters[] , int direc[], int len)
{
    int index = 0;
    char greatest = ' ';
    for (int i = 1; i < len; i++){
        if ((characters[i]>characters[i-1]) && direc[i] == -1 && characters[i]>greatest) {
            greatest = characters[i];
            index = i;
        }
    }
    for (int i = 0; i < len - 1; i++ ) {
        if ((characters[i]>characters[i+1]) && direc[i] == 1 && characters[i]>greatest) {
            greatest = characters[i];
            index = i;
        }
    }
    return index; 
}

void printPermutations( string word, int permutations )
{
    int direc[word.length()]; 
    for (int i = 0; i < word.length(); i++) {
        direc[i] = -1;
    }
    char charArray[word.length()];
    for (int i = 0; i < word.length(); i++) {
        charArray[i] = word[i];
    }
    cout << charArray << endl;
    for(int i = 1; i <= permutations-1; i++ )
    {
        int largeMobileIndex = findLargestMobile(charArray, direc, word.length());
        if (direc[largeMobileIndex] == (-1)) {
            int temp = charArray[largeMobileIndex-1];
            charArray[largeMobileIndex -1] = charArray[largeMobileIndex];
            charArray[largeMobileIndex] = temp;
            int tempDirec = direc[largeMobileIndex - 1];
            direc[largeMobileIndex - 1] = direc[largeMobileIndex];
            direc[largeMobileIndex] = tempDirec;
                for (int j = 0; j < word.length(); j++) {
                    if (charArray[j] > charArray[largeMobileIndex-1]){
                       direc[j] = direc[j]*(-1);
                    }
                }
        }
        else {
            int tempChar = charArray[largeMobileIndex + 1];
            charArray[largeMobileIndex + 1] = charArray[largeMobileIndex];
            charArray[largeMobileIndex] = tempChar;
            int tempDirec = direc[largeMobileIndex + 1];
            direc[largeMobileIndex + 1] = direc[largeMobileIndex];
            direc[largeMobileIndex] = tempDirec;
                for (int j = 0; j < word.length(); j++) {
                    if (charArray[j] > charArray[largeMobileIndex+1]){
                        direc[j] = direc[j]*(-1);
                }
            }
        }
        
        cout << charArray << endl;
    }
    return;
}

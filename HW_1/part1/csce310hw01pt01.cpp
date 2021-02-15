#include "csce310hw01pt01.h"

using namespace std;

unsigned long long int oddDigits( unsigned long long int digits )
{
    int OddDigits = 0;
    while (digits >= 1)
    {
        int SingleDigit = digits % 10;
        if (SingleDigit % 2 == 1)
        {
            OddDigits++;
        }
        digits = digits / 10;
    }
    return OddDigits;
}

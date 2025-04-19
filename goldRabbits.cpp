// Name: Vansh Patel
// Class (CECS 325-02)
// Project Name (Prog 5 - STL (GoldRabbits))
// Due Date (04/22/25)
// I certify that this program is my own original work. I did not copy and part of this program from any other source.
// I further certify that I typed each and every line of code in this program.
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
// #define integer short
#define integer int
// #define integer long long
using namespace std;

static map<integer, integer> memoizedMap = {{0, 1}, {1, 1}}; // initialize map with base cases
static integer overflowAt;                                   // keeping track of when overflow occurs

integer goldRabbits(integer n)
{
    if (n == -1)
    {
        cout << "Fibo Map contents:" << endl;
        map<integer, integer>::iterator it = memoizedMap.begin(); // iterator to traverse the map
        while (it != memoizedMap.end())                           // while not at end of map
        {
            cout << it->first << ":" << it->second << endl; // first = key, second = value
            ++it;
        }
        cout << "end of Fibo map" << endl;
        return 0;
    }

    if (memoizedMap.find(n) != memoizedMap.end())
    { // if n in map then return the value
        return memoizedMap[n];
    }
    // otherwise calculate the value and store it in the map for future use
    integer prev1 = goldRabbits(n - 1);
    integer prev2 = goldRabbits(n - 2);
    // Calculate sum and check for overflow
    integer res = prev1 + prev2;

    // if addition of 2 pos nums causes neg res => overflow, save position and throw string exception
    if ((prev1 > 0 && res < prev1) || (prev2 > 0 && res < prev2))
    {
        overflowAt = n; // store position where overflow occurred
        throw string("overflow");
    }

    memoizedMap[n] = res;
    return res;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        try
        {
            if (!isdigit(argv[i][0]) && argv[i][0] != '-') // if not a number or negative sign then error
            {
                cout << argv[i] << " is not an integer" << endl;
                continue;
            }
            integer n = atoi(argv[i]);
            if (n == -1) // if n is -1 then print the map and continue
            {
                cout << "fibo(-1):" << endl;
                goldRabbits(n);
                continue;
            }
            integer result = goldRabbits(n);
            cout << "fibo(" << n << "): " << result << endl;
        }
        catch (string s)
        {
            cout << "fibo(" << argv[i] << "): overflow error at fib(" << overflowAt << "):" << memoizedMap[overflowAt - 1] + memoizedMap[overflowAt - 2] << endl;
        }
    }
    return 0;
}
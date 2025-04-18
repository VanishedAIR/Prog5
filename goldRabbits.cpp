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

integer goldRabbits(integer n)
{
    if (n == -1)
    {
        cout << "Fibo Map contents:" << endl;
        map<integer, integer>::iterator it = memoizedMap.begin();
        while (it != memoizedMap.end())
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
    if (prev1 == -1)
    {
        return -1;
    }
    integer prev2 = goldRabbits(n - 2);
    if (prev2 == -1)
    {
        return -1;
    }
    if (prev1 + prev2 < 0)
    {
        cout << "fibo(" << n << "): overflow error at fib(" << n << "):" << prev1 + prev2 << endl;
        return -1;
    }

    integer result = prev1 + prev2;
    memoizedMap[n] = result;
    return result;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        try
        {
            integer n = atoi(argv[i]);
            if (n == -1)
            {
                cout << "fibo(-1):" << endl;
                goldRabbits(n);
                continue;
            }
            integer result = goldRabbits(n);
            cout << "fibo(" << n << "): " << result << endl;
        }
        catch (integer n)
        {
            cout << "fibo(" << argv[i] << "): overflow error at fib(" << n << "):" << overflow_value << endl;
        }
        catch (...)
        {
            cout << argv[i] << " is not an integer" << endl;
            continue;
        }
    }
    return 0;
}
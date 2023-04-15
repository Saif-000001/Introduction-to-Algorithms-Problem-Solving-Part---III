#include <bits/stdc++.h>
using namespace std;

// O(2^n)
// int fib(int n)
// {
//     if (n <= 2)
//         return 1;

//     return fib(n - 1) + fib(n - 2);
// }

long long ara[101];

/*
ara[3] = 2
ara[4] = 3
ara[5] = 5
ara[6] = 8

ara[50] = 12586269025

*/

// O(n)
long long fib(int n)
{
    if (n <= 2)
        return 1;

    if (ara[n] != 0)
        return ara[n];

    ara[n] = fib(n - 1) + fib(n - 2);
    return ara[n];
}

int main()
{
    long long n;
    cin >> n;
    cout << fib(n) << "\n";

    return 0;
}
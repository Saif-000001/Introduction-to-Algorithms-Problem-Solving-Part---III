#include <bits/stdc++.h>
using namespace std;

int digitSum(int n)
{
    int sum = 0;
    // base case
    if (n == 0)
        return sum;

    int digit = n % 10;
    sum = sum + digit;
    return sum + digitSum(n / 10);
}

int main()
{
    int n;
    cin >> n;
    // digitSum(n);
    cout << digitSum(n) << "\n";

    // int sum = 0;
    // while (n != 0)
    // {
    //     int digit = n % 10;
    //     sum += digit;
    //     n /= 10;
    // }
    // cout<<sum<<"\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void reverseString(string s, int i)
{
    int r = s.size();
    // base case
    if (i > r)
        return;
    // generalized formula
    char ch = s[i];
    i = i + 1;
    reverseString(s, i);

    cout << ch;
}

int main()
{
    string s;
    cin >> s;
    reverseString(s, 0);
    cout << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void reverse(string str, int i)
{
    int r = str.size();
    // base case
    if (i > r)
        return;
    // generalized formula
    char ch = str[i];
    i = i + 1;
    reverse(str, i);

    cout << ch;
}

int main()
{
    string s;
    cin >> s;
    reverse(s, 0);
    cout << "\n";
    return 0;
}
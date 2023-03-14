#include <bits/stdc++.h>
using namespace std;

void getCapital(string str, int i)
{
    if (i > str.size())
        return;
    if (str[i] > 'A' && str[i] < 'Z')
    {
        cout << str[i] << "\n";
        return;
    }
    i = i + 1;
    getCapital(str, i);
}

int main()
{
    string s;
    cin >> s;
    getCapital(s, 0);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool is_palindram(string s)
{
    int freq[26] = {0};

    for (auto c : s)
        freq[c - 'a']++;

    int oddFreqCount = 0;
    for (int i = 1; i <= 26; i++)
    {
        if (freq[i] % 2 == 1)
            oddFreqCount++;
    }
    return oddFreqCount <= 1;
}

int main()
{
    string s;
    cin >> s;

    if (is_palindram(s))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
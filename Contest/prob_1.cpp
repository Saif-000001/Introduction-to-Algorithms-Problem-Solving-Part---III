#include <bits/stdc++.h>
using namespace std;
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int main()
{
    Faster;
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << ">\n";
        return 0;
    }
    int i = 0;
    int k = 1;
    int t = 0;
    while (i < n)
    {

        for (int j = i + 1; j < n; j++)
        {
            cout << " ";
        }

        for (int i = 1; i <= k; i++)
        {
            if (t)
                cout << "<";
            else
                cout << ">";
        }
        cout << "\n";
        if (t)
            t = 0;
        else
            t = 1;
        k += 2;
        i++;
    }

    i = 1;
    k = k - 4;

    while (i < n)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " ";
        }
        for (int i = 1; i <= k; i++)
        {
            if (t)
                cout << "<";
            else
                cout << ">";
        }
        cout << "\n";
        if (t)
            t = 0;
        else
            t = 1;
        k -= 2;
        i++;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int findKingIndex(vector<int> &blocks)
{
    int totalSum = 0;

    for (int i = 0; i < blocks.size(); i++)
        totalSum += blocks[i];

    int leftSum = 0;
    for (int i = 0; i < blocks.size(); i++)
    {
        int rightSum = totalSum - leftSum - blocks[i];
        if (leftSum == rightSum)
            return i;

        leftSum += blocks[i];
    }

    return -1;
}

int main()
{
    Faster;
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> blocks(n);
        for (int i = 0; i < n; i++)
        {
            cin >> blocks[i];
        }

        int kingIndex = findKingIndex(blocks);
        cout << kingIndex << "\n";
    }

    return 0;
}

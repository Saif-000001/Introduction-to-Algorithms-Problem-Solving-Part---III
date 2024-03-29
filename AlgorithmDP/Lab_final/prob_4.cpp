#include <bits/stdc++.h>
using namespace std;
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
    
int main()
{
    Faster;
    int n, target;
    cin >> n >> target;

    vector<pair<int, int>> values;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        values.push_back({x, i + 1});
    }

    sort(values.begin(), values.end());

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        if (values[left].first + values[right].first > target)
            right--;
        else if (values[left].first + values[right].first < target)
            left++;
        else if (values[left].first + values[right].first == target)
        {
            cout << values[right].second << " " << values[left].second << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
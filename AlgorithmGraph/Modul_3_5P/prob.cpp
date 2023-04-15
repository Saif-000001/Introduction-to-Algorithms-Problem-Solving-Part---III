#include <bits/stdc++.h>
using namespace std;
/*
int main()
{
    // Total time complexity -> O(1) + O(N) + O(M) = O(N+M)
    // Total space complexity -> O(1) + O(N*M) + O(1) = O(N*M)
    int a = 0, b = 0; // time -> O(1)  // space -> O(1)
    int N, M;
    int matrix[N][M];           // time -> O(1)   // space -> O(N*M)
    for (int i = 0; i < N; i++) // time -> O(N) // space -> O(1)
    {
        a = a + i;
        matrix[i][i] = a;
    }
    for (int j = 0; j < M; j++) // time -> O(M) // space -> O(1)
    {
        b = b + 2 * j;
    }
}

*/

// int main()
// {
//     // Total time complexity -> O(1) + O(N) + O(N-1) = N+(N-1)+(N-2)+.....1+0
//     //                         = N*(N-1)/2 = O(N*N)
//     //                         = O(N^2)
//     // Total space complexity -> O(1) = O(1)

//     int a = 0, N;               // time -> O(1) // space -> O(1)
//     for (int i = 0; i < N; i++) // time -> O(N)
//     {
//         for (int j = N; j > i; j--) // time -> O(N-1)
//         {
//             a = a + i + j;
//         }
//     }
// }

int main()
{
    // Total time complexity -> O(logn)

    // Total space complexity -> O(1)

    int N;            // time -> O(1) // space -> O(1)
    int a = 0, i = N; // time -> O(1) // space -> O(1)
    vector<int> vec;  // time -> O(1) // space -> O(1)
    while (i > 0)     // time -> O(logn)
    {
        a += i;
        i /= 2; // i/2+i/2........
        vec.push_back(a);
    }
}

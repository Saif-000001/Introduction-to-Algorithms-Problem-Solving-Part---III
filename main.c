#include <stdio.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i = 10;
    int a = (n / i);
    int b = (n % i);

    if ((b % a )== 0 || (a % b) == 0 )
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
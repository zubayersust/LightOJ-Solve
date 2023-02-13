#include<bits/stdc++.h>

using namespace std;

int T;
int A, B, C, x1, x2, y1, y2;

int find_any_solution(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;

        return a;
    }

    int x0, y0;
    int g = find_any_solution(b, a % b, x0, y0);

    x = y0;;
    y = x0 - (a / b) * y0;

    return g;
}

int find_solution_count()
{

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &T);

    int testCase = 1;
    while(testCase <= T)
    {
        scanf("%d%d%d%d%d%d%d", &A, &B, &C, &x1, &x2, &y1, &y2);

        int result = 0;
        int x, y;
        int gcd = find_any_solution(A, B, x, y);
        if(C % gcd) result = 0;
        else
        {

        }

        printf("Case %d: %d\n", testCase++, result);
    }

    return 0;
}

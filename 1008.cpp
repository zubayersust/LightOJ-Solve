/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.00s
Memory : 1700
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<set>
#include<algorithm>

using namespace std;

int testCase,p=1,range,col,row;
double s,start,finish,temp,number;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &testCase);

    while(p<=testCase)
    {
        scanf("%lf", &s);

        number = s;
        s=ceil(sqrt(s));

        start  = pow(s-1.0, 2.0)+1.0;
        finish = pow(s, 2.0);

        if(number == 1.0)
            printf("Case %d: %d %d\n", p++, 1, 1);
        else
        {
            if((int)s%2 ==0)
            {
                range = (int) (finish-start)+1.0;
                temp  = (number-start)+1;

                if(temp <= (range/2))
                {
                    col = (int) temp;
                    row = (int) s;
                }
                else
                {
                    col = (int) s;
                    row = (int) (finish-number)+1;
                }
            }
            else
            {
                range = (int) (finish-start)+1.0;
                temp  = (finish-number)+1;

                if(temp <= (range/2))
                {
                    col = (int) temp;
                    row = (int) s;
                }
                else
                {
                    col = (int) s;
                    row = (int) (number-start)+1;
                }
            }
            printf("Case %d: %d %d\n",p++,col,row);
        }
    }
    return 0;
}

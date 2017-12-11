/**
Online Judge : LightOJ
Problem No   : 1000
Problem Name : Greetings from LightOJ
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.0s
Memory       : 1088KB
Algorithm    : Implementation
*/

#include<stdio.h>

int main()
{
    int T,a,b,sum,i=1;
    scanf("%d",&T);

    while((i<=T && scanf("%d %d",&a,&b)==2))
    {
        printf("Case %d: ",i);
        sum=a+b;
        printf("%d\n",sum);
        i++;
    }
    return 0;
}

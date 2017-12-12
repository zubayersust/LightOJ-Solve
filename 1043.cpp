/**
Online Judge : LightOJ
Problem No   : 1043
Problem Name : Triangle Partitioning
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 0.0s
Memory       : 1700KB
Algorithm    : Binary Search (Bisection)
*/

#include<bits/stdc++.h>

using namespace std;

int testCase,caseNum=1;
double ab,ac,bc,r;
double ad;

double binarySearch(double low, double high)
{
    double mid = (low+high)/2;
    ad = mid;

    double ae = (mid*ac)/ab;
    double de = (mid*bc)/ab;

    double s;
    double abc,ade,bdec;

    s = (ab+ac+bc)/2;
    abc = sqrt(s*(s-ab)*(s-ac)*(s-bc));

    s = (mid+ae+de)/2;
    ade = sqrt(s*(s-mid)*(s-ae)*(s-de));

    bdec = abc-ade;

    return (ade/bdec);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &testCase);

    while(caseNum<=testCase)
    {
        scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &r);

        double ad_high = ab;
        double ad_low = 0;
        double calculated_r = 0;

        while(abs(r-calculated_r) >= 0.0000001)
        {
            calculated_r = binarySearch(ad_low, ad_high);

            if(r-calculated_r > 0)
                ad_low = (ad_low+ad_high)/2;
            else if(r-calculated_r < 0)
                ad_high = (ad_low+ad_high)/2;
        }

        printf("Case %d: %.10lf\n", caseNum++, ad);
    }
    return 0;
}

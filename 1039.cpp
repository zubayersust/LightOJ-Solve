/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.024s
Memory : 1848
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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

#define mem(x,y) memset(x,y,sizeof(x))
#define MAX_LETTERS 27

using namespace std;

int testCase,p=1,n,i,k,m,r,len_start,len_mid,len_last,st,md,lt,start_st,start_md,start_lt,finish_st,finish_md,finish_lt;
int visited[MAX_LETTERS][MAX_LETTERS][MAX_LETTERS];
int weight[MAX_LETTERS][MAX_LETTERS][MAX_LETTERS];
string start_string,finish_string;

int dir_first[] = {0, 0, 0, 0, 1,-1};
int dir_mid  [] = {0, 0, 1,-1, 0, 0};
int dir_last [] = {1,-1, 0, 0, 0, 0};

class node
{
public:
    int start;
    int mid;
    int last;

    node(int start, int mid, int last)
    {
        this->start = start;
        this->mid   = mid;
        this->last  = last;
    }

    node()
    {

    }
};

queue<node> q;

void reset()
{
    mem(visited,0);
    mem(weight,-1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    scanf("%d", &testCase);

    while(p<=testCase)
    {
        cin>>start_string>>finish_string;

        cin>>n;

        reset();

        for(i=0; i<n; i++)
        {
            string start,mid,last;
            cin>>start>>mid>>last;

            len_start = start.size();
            len_mid   = mid.size();
            len_last  = last.size();

            for(k=0; k<len_start; k++)
            {
                st = (int) start.at(k)-96;
                for(m=0; m<len_mid; m++)
                {
                    md = (int) mid.at(m)-96;
                    for(r=0; r<len_last; r++)
                    {
                        lt = (int) last.at(r)-96;
                        visited[st][md][lt] = 1;
                    }
                }
            }
        }

        start_st = (int) start_string.at(0)-96;
        start_md = (int) start_string.at(1)-96;
        start_lt = (int) start_string.at(2)-96;

        finish_st = (int) finish_string.at(0)-96;
        finish_md = (int) finish_string.at(1)-96;
        finish_lt = (int) finish_string.at(2)-96;

        if(visited[start_st][start_md][start_lt])
            printf("Case %d: %d\n", p++, -1);
        else
        {
            node nd = node(start_st, start_md, start_lt);

            visited[start_st][start_md][start_lt] = 1;
            weight[start_st][start_md][start_lt]  = 0;

            q.push(nd);

            while(!q.empty())
            {
                node nd = q.front();
                q.pop();

                if(nd.start == finish_st && nd.mid == finish_md && nd.last == finish_lt)
                {
                    while(!q.empty())
                        q.pop();
                    break;
                }

                for(i=0; i<6; i++)
                {
                    node new_node;

                    new_node.start = (nd.start + dir_first[i]) % 26;
                    new_node.mid   = (nd.mid   + dir_mid[i]) % 26;
                    new_node.last  = (nd.last  + dir_last[i]) % 26;

                    if(new_node.start == 0)
                        new_node.start = 26;
                    if(new_node.mid == 0)
                        new_node.mid = 26;
                    if(new_node.last == 0)
                        new_node.last = 26;

                    if(!visited[new_node.start][new_node.mid][new_node.last])
                    {
                        visited[new_node.start][new_node.mid][new_node.last] = 1;
                        weight[new_node.start][new_node.mid][new_node.last] = weight[nd.start][nd.mid][nd.last] +
                                (abs(dir_first[i])+abs(dir_mid[i])+abs(dir_last[i]));
                        q.push(new_node);
                    }
                }
            }
            printf("Case %d: %d\n",p++,weight[finish_st][finish_md][finish_lt]);
        }
    }
    return 0;
}

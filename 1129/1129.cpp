/**
Online Judge : LightOJ
Problem No   : 1129
Problem Name : Consistency Checker
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 1.000s
CPU          : 0.400s
Memory       : 7076KB
Algorithm    : Trie
*/

#include<bits/stdc++.h>

#define MAX_DIGIT 10

using namespace std;

class PhoneNumber
{
public:
    string number;
    int numberLength;

    PhoneNumber(string number)
    {
        this->number=number;
        this->numberLength = number.size();
    }

    bool operator< (const PhoneNumber& phoneNumber) const
    {
        return numberLength > phoneNumber.number.size();
    }
};

priority_queue<PhoneNumber> Q;

class Node
{
public:
    bool word;
    Node *next[MAX_DIGIT+1];

    Node()
    {
        word = false;

        for(int i=0; i<MAX_DIGIT; i++)
            next[i] = NULL;
    }
};

Node *root;
bool consistent;

void Insert(string s, int len)
{
    Node *current_node = root;

    for(int i=0; i<len; i++)
    {
        int id = s.at(i) - '0';

        if(current_node->next[id] == NULL)
            current_node->next[id] = new Node();
        else
        {
            current_node = current_node->next[id];

            if(current_node->word)
                consistent = false;
            continue;
        }

        current_node = current_node->next[id];
    }
    current_node->word = true;
}

void reset(Node *current_node)
{
    int i;

    for(i=0; i<MAX_DIGIT; i++)
        if(current_node->next[i])
            reset(current_node->next[i]);

    delete(current_node);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int testCases,caseNumber=1;
    int n;

    scanf("%d", &testCases);

    while(caseNumber<=testCases)
    {
        scanf("%d", &n);

        int i;
        string s;

        for(i=0; i<n; i++)
        {
            cin>>s;

            PhoneNumber phoneNumber(s);
            Q.push(phoneNumber);
        }

        root = new Node();
        consistent = true;

        while(!Q.empty())
        {
            PhoneNumber phoneNumber = Q.top();
            Q.pop();
            Insert(phoneNumber.number, phoneNumber.numberLength);
        }

        if(consistent)
            printf("Case %d: YES\n", caseNumber++);
        else printf("Case %d: NO\n", caseNumber++);

        reset(root);
    }
    return 0;
}

/**
Author : Zubayer Rahman
Email  : zubayer.csesust@gmail.com
CPU    : 0.512s
Memory : 8024KB
*/

#include<bits/stdc++.h>

using namespace std;

class MyClass
{
public:
    string str;
    int len;

    MyClass(string s)
    {
        str = s;
        len = str.size();
    }

    bool operator< (const MyClass& myClass) const
    {
        return len > myClass.str.size();
    }
};

priority_queue<MyClass> q;

class Node
{
public:
    bool word;
    Node *next[10+1];

    Node()
    {
        word = false;

        int i;

        for(i=0; i<10; i++)
            next[i] = NULL;
    }
};

Node *root;
bool consistent;

void Insert(string s, int len)
{
    Node *current_node = root;

    int i;

    for(i=0; i<len; i++)
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

    for(i=0; i<10; i++)
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

            MyClass myClass(s);
            q.push(myClass);
        }

        root = new Node();
        consistent = true;

        while(!q.empty())
        {
            MyClass obj = q.top();
            q.pop();
            Insert(obj.str, obj.str.size());
        }

        if(consistent)
            printf("Case %d: YES\n", caseNumber++);
        else printf("Case %d: NO\n", caseNumber++);

        reset(root);
    }
    return 0;
}

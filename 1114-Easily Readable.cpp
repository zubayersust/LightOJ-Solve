/**
Online Judge : LightOJ
Problem No   : 1114
Problem Name : Easily Readable
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
Time Limit   : 2.000s
CPU          : 0.604s
Memory       : 33200KB
Algorithm    : Trie
*/

#include<bits/stdc++.h>

#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define PB push_back
#define MP make_pair
#define PI acos(-1.0)
#define ff first
#define ll long long
#define ss second
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define QI queue<int>
#define SI stack<int>
#define PII pair<int,int>
#define MAX(a,b) max(a,b)
#define MOD 1000000007
#define INF 1<<30
#define mem(a,b) memset((a),(b),sizeof(a))
#define MAX3(a,b,c) max(a,max(b,c))
#define READ_INPUT_FILE() freopen("input.txt","r",stdin)

using namespace std;

struct Node
{
    bool endmark;
    int word_count;
    Node* next[52];

    Node()
    {
        endmark = false;
        word_count = 0;
        REP(i, 52) next[i] = NULL;
    }
}* root;

void insert_word(char* word, int len)
{
    Node* cn = root;

    REP(i, len)
    {
        int id = isupper(word[i]) ? word[i] - 'A' : word[i] - 'a' + 26;
        if (cn->next[id] == NULL)
            cn->next[id] = new Node();
        cn = cn->next[id];
    }

    cn->endmark = true;
    cn->word_count += 1;
}

int search_word(char* word, int len)
{
    Node* cn = root;

    REP(i, len)
    {
        int id = isupper(word[i]) ? word[i] - 'A' : word[i] - 'a' + 26;
        if (cn->next[id] == NULL)
            return 0;
        cn = cn->next[id];
    }

    if (cn->endmark)
        return cn->word_count;

    return 0;
}

void delete_nodes(Node* cn)
{
    REP(i, 52)
    {
        if(cn->next[i])
            delete_nodes(cn->next[i]);
    }

    delete(cn);
}

int main()
{
#ifndef ONLINE_JUDGE
    READ_INPUT_FILE();
#endif // ONLINE_JUDGE

    int T, n, m;
    char word[101], sentence[10001];

    while(cin >> T)
    {
        FOR(i, 1, T)
        {
            root = new Node();

            printf("Case %d:\n", i);

            sc(n);
            FOR(j, 1, n)
            {
                scanf("%s", word);

                if (strlen(word) > 2) sort(word + 1, word + strlen(word) - 1);
                insert_word(word, strlen(word));
            }

            sc(m);
            getchar();

            FOR(j, 1, m)
            {
                gets(sentence);

                int result = 1;
                for(int k = 0; sentence[k]; k++)
                {
                    if(!isalpha(sentence[k])) continue;

                    int m = 0;
                    while(sentence[k] && isalpha(sentence[k])) word[m++] = sentence[k++];
                    word[m] = '\0';
                    k--;

                    if(m > 2) sort(word + 1, word + strlen(word) - 1);
                    result *= search_word(word, strlen(word));
                }

                pf(result);
            }

            delete_nodes(root);
        }
    }

    return 0;
}

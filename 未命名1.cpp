#include<bits/stdc++.h>
#define LL long long
#define pa pair<int,int>
#define lson k<<1
#define rson k<<1|1
//ios::sync_with_stdio(false);
using namespace std;
const int N = 1000100;
const int M = 200100;
const LL mod = 1e9 + 7;
int tr[N][30], val[N];
int rt;
int ans[N];
void add(string s) 
{
    int k = 0;int i = 0;
    while( i < s.length()) 
    {
        int d = s[i] - 'a';
        if (!tr[k][d]) tr[k][d] = ++rt;
        k = tr[k][d]; i++;
    }
    val[k] = 1;//?????? 
}
void search(string s) 
{
    int k = 0;
    memset(ans, 0, sizeof(ans));int i = 0;
    while( i < s.length()) 
    {
        int d = s[i] - 'a';
        if (!tr[k][d]) break;
        k = tr[k][d];
        if (val[k]) ans[i] = 1;//???????? 
     i++;}
    int bb = 0;  
    for(int c = 0;c < s.length();c++) 
    {
        if (ans[c]) bb = c + 1;
        else continue;
        int k = 0;
        for (int j = c + 1; j < s.length(); j++) 
        {
            int d = s[j] - 'a';
            if (!tr[k][d]) break;
            k = tr[k][d];
            if (val[k]) ans[j] = 1;
        } 
    }
    cout << bb << endl;
}
int main() 
{
//     ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string s;int i = 1;
    while ( i <= n) 
    {
        cin >> s;
        add(s); i++;
    }
    for (int i = 1; i <= m; i++) 
    {
        cin >> s;
        search(s);
    }
    return 0;
}

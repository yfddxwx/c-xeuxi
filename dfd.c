//#include<stdio.h>
//struct student{
//	int uid;
//	char name[80];
//	int eng,chi,math;
//	int g;
//};
//int main(){
//	int n,i,p=0;
//	printf("请输入人数");	scanf("%d",&n);
//
//	struct student num[n];
//	for(i=0;i<n;i++){
//		printf("现在的是%d号",&i);
//		scanf("%d %s %d %d %d",&num[i].uid,&num[i].name,&num[i].eng,&num[i].chi,&num[i].math);
//		num[i].g=(num[i].chi+num[i].eng+num[i].math)/3;
//		if(num[i].g>p)p=num[i].g;
//	}
//	printf("%d",p);
//}
//#include<stdio.h>
//int main()
//{
//	int n,i,a[100000];
//	scanf("%d",&n);
//	for(i=0;i<n;i++)
//		scanf("%d",&a[i]);
//	int max=0,k,j,sum=0;
//	for(i=0;i<n;i++)
//	{
//		sum=sum+a[i];
//		if(sum>max)
//			max=sum;
//		else if(sum<0)
//			sum=0;
//	}
//	printf("%d\n",max);
// } 
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
    int bb = 0;int i = 0; 
    while(i < s.length()) 
    {
        if (ans[i]) bb = i + 1;
        else continue;
        int k = 0;
        for (int j = i + 1; j < s.length(); j++) 
        {
            int d = s[j] - 'a';
            if (!tr[k][d]) break;
            k = tr[k][d];
            if (val[k]) ans[j] = 1;
        } i++;
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


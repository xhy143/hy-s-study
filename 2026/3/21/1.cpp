#include<bits/stdc++.h>
#define ll long long
using namespace std;
int l,r,len,num[15],f[15][15][2][2];
int dfs(int len,int last,bool flag,bool zero)
{
	if (!len) return 1;   
	if (~f[len][last][flag][zero]) return f[len][last][flag][zero];         
	int res=0;
	for (int i=0;i<=9;i++)
	    if ((i<=num[len] || !flag) && (abs(i-last)>=2 || zero))   
		    res+=dfs(len-1,i,flag&&(i==num[len]),zero&&(!i));   
	f[len][last][flag][zero]=res; 
	return res;
}
int solve(int x)  
{
	int tmp=x;
	len=0;
	memset(num,0,sizeof(num));
	while (tmp)       
	{
		num[++len]=tmp%10;
		tmp/=10;
	}
	memset(f,-1,sizeof(f));
	return dfs(len,11,1,1); 
}
int main()
{
	cin>>l>>r; 
	cout<<solve(r)-solve(l-1);
}

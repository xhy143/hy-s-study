#include<bits/stdc++.h>
#define OwO 0
using namespace std;
struct node{
	int p,c;
	
};
struct node2{
	int a,b;
	
};
bool cmp1(node a,node b){
    return a.p<b.p;
}
bool cmp2(node2 a,node2 b){
    return a.a-a.b>b.a-b.b;
}
int n,m,x,head,back;
long long ans;
node stt[100001];
node2 cr[100001];
int main(){
	cin>>n>>m>>x;
	for(int i = 1;i <= n;i ++)cin>>stt[i].p>>stt[i].c; 
	for(int i = 1;i <= m;i ++){
		cin>>cr[i].a>>cr[i].b;
		ans += ((long long)cr[i].b * x << 1);
	}
	sort(stt + 1,stt + n + 1,cmp1);
	sort(cr + 1,cr + m + 1,cmp2);
	head = 1,back = n; 
	for(int i = 1;i <= m && cr[i].a > cr[i].b;i ++){
		int a = cr[i].a,b = cr[i].b; 
		ans += ((long long)(a - b) * stt[head].p << 1);
		if(!(-- stt[head].c)) head++;
	}
	for(int i = m;i && cr[i].a < cr[i].b;i --){
		int a = cr[i].a,b = cr[i].b; 
		ans += ((long long)(a - b) * stt[back].p << 1);
		if(!(--stt[back].c)) back--;
	}
	cout<<ans;
	return OwO;//
} 

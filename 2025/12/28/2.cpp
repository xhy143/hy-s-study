#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long i,n,d,a[N],v[N],sum[N],mi,k,ans,modd;
int main()
{
    cin>>n>>d;
    for(i=1;i<n;i++)cin>>v[i];
    for(i=1;i<=n;i++)cin>>a[i];
    mi=a[1],k=1;
    for(i=1;i<n;i++)
    {
        if(a[i]>=mi)sum[k]+=v[i];
        else
        {
            k=i,mi=a[i],sum[i]+=v[i];
        }
    }
    for(i=1;i<=n;i++)
    {
		ans+=ceil(sum[i]*1.0/d)*a[i];
		modd+=ceil(sum[i]*1.0/d)*d-sum[i];
		if(modd>=d)modd-=d,ans-=a[i];
	}
    cout<<ans;
    return 0;
}

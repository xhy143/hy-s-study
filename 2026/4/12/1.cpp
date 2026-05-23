#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],ma[100001],f[100001];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		f[i]=INT_MAX;
	}
	int mix=0;
	f[0]=0;
	for(int i=1;i<=n;i++){
		int l=0,r=mix,mid;
		if(ma[b[i]]>f[mix]){
			mix++;
			f[mix]=ma[b[i]];
		}
		else{
			while(l<r){	
			    mid=(l+r)/2;
			    if(f[mid]>ma[b[i]]){
			    	r=mid;
				}
				else{
					l=mid+1; 
				}
			}
			f[l]=min(ma[b[i]],f[l]);
     	}
    }
    cout<<mix;
}

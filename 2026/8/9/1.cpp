#include<bits/stdc++.h>
using namespace std;
int main(){
  unordered_map<int,int>color;
  int n;
  cin>>n;
  int ans=0;
  for(int i=0;i<n;i++){
    int p;
    cin>>p;
    color[p]+=1;
    ans=max(ans,color[p]);
  }
  cout<<n-ans;
}
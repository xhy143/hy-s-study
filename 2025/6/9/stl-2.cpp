#include<bits/stdc++.h>
using namespace std;
int m,n;
int main(){
    cin>>m;
    vector<vector<int> > v(m+1);
    for(int i=1;i<=m;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
        	int p;
        	cin>>p;
            v[i].push_back(p);
        }
        sort(v[i].begin(),v[i].end());
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=m;i++){
        for(int j:v[i]){
            cout<<j<<' ';
        }
        cout<<endl;
    }
}

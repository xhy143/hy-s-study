#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct MS{
    multiset<int> ms;
    void ins(int x) { 
        ms.insert(x);
    }
    void delOne(int x) { 
        multiset<int>::iterator it = ms.find(x);
        if (it == ms.end()) return ;
        ms.erase(it);
    }
    int getMin() {
        return *ms.begin();
    }
} bst;
int a[1000001];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<k;i++){
        bst.ins(a[i]);
    }
    for(int i=k;i<=n;i++){
        int t=bst.getMin();
        cout<<t<<endl;
        bst.delOne(a[i-k]);
        bst.ins(a[i]);
    }
}
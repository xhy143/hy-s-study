#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    unordered_set <int> st;
    int cnt=0;
    for(int i=0;i<n;i++){
        int num=x-a[i];
        auto it=st.find(num);
        if(it!=st.end()) cnt++;
        st.insert(a[i]);
    }
    cout<<cnt;
    return 0;
}

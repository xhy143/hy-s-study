#include<bits/stdc++.h>
using namespace std;
struct br{
    string id;
    int age;
    int rk;
    bool operator <(const br&b) const{
        if (age >= 60 && b.age < 60) return true;
        if (age < 60 && b.age >= 60) return false;
        if (age >= 60 && b.age >= 60) {
            if (age != b.age) return age > b.age;
            return rk < b.rk;
        }
        return rk<b.rk;
    }
};
int main(){
    br a[100001];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].id>>a[i].age;
        a[i].rk=i;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        cout<<a[i].id<<endl;
    }
}
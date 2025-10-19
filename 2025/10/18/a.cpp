#include<bits/stdc++.h>
using namespace std;
//结构体存储
/*
1，决斗
思路：排序战斗力，枚举每一个未攻击过的怪兽j，找到比他的攻击小的攻击力最大的怪兽作为i，直到每一只怪兽都攻击过
预估得分：我不到啊%
*/  
int main(){
    int n;
    cin>>n;
    map<int,int>a;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        a[p]++;
    }
    int maxx=-1;
    for(auto s:a){
        if(s.second>maxx){
            maxx=s.second;
        }
    }
    cout<<maxx;
}
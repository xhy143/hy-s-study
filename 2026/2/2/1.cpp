#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct MS{
    multiset<int> ms;
    void ins(int x) { // 插入x
        ms.insert(x);
    }
    void delOne(int x) { // 删除一个x
        multiset<int>::iterator it = ms.find(x);
        if (it == ms.end()) return ;
        ms.erase(it);
    }
    int getMin() { // 获取最小值
        return *ms.begin();
    }
    int getMax() { // 获取最大值
        return *(--ms.end());
    }
    int getPre(int x) { // 求x的前驱
        multiset<int>::iterator it = ms.lower_bound(x);
        if (it == ms.begin()) return -INF; // 不存在x的前驱
        return *(--it);
    }
    int getNext(int x) { // 求x的后继
        multiset<int>::iterator it = ms.upper_bound(x);
        if (it == ms.end()) return INF; // 不存在x的后继
        return *it;
    }
    int closest(int x) { // 求最接近x的数
        if (ms.empty()) return INF; // 容器为空
        multiset<int>::iterator it = ms.lower_bound(x), it2 = it;
        if (it == ms.end()) return *(--it); // 不存在>=x的
        if (it == ms.begin()) return *it; // 不存在<x的
        it2--;
        if (*it - x < x - *it2) return *it;
        return *it2;
    }
} bst;
int main(){
    int n,ans=0;
    cin>>n;
    int k;
    cin>>k;
    bst.ins(k);
    ans+=k;
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        ans+=abs(p-bst.closest(p));
        bst.ins(p);
    }
    cout<<ans;
}
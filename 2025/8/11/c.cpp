#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> apples(n);
    for(int i = 0; i < n; i++) apples[i] = i + 1;
    int day = 0, flag = 0;
    while(!apples.empty()) {
        day++;
        vector<int> next;
        for(int i = 0; i < apples.size(); i++) {//as;lkdj
            if(i % 3 != 0) next.push_back(apples[i]);
            else if(apples[i] == n) flag = day;
        }
        apples = next;
    }
    cout << day << " " << flag << endl;
}
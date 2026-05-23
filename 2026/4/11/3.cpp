#include <bits/stdc++.h>
#define ovO 0;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    deque<int> mindq, maxdq;
    vector<long long> minVals, maxVals;

    for (int i = 0; i < N; ++i) {
        if (!mindq.empty() && mindq.front() <= i - K) mindq.pop_front();
        if (!maxdq.empty() && maxdq.front() <= i - K) maxdq.pop_front();
        while (!mindq.empty() && arr[mindq.back()] > arr[i]) {
            mindq.pop_back();
        }
        mindq.push_back(i);
        while (!maxdq.empty() && arr[maxdq.back()] < arr[i]) {
            maxdq.pop_back();
        }
        maxdq.push_back(i);
        if (i >= K - 1) {
            minVals.push_back(arr[mindq.front()]);
            maxVals.push_back(arr[maxdq.front()]);
        }
    }
    for (int j = 0; j < minVals.size(); ++j) {
        cout << minVals[j] <<' ';
    }
    cout<<"\n";
    for (int j = 0; j < maxVals.size(); ++j) {
        cout << maxVals[j] <<' ';
    }
    return ovO
}
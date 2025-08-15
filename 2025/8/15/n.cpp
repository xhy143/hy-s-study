#include <bits/stdc++.h>
using namespace std;
bool check(const vector<int>& arr, int m, int max_sum) {
    int segments = 1;  
    int current_sum = 0;
    
    for (int num : arr) {
        if (num > max_sum) {
            return false;
        }
        if (current_sum + num > max_sum) {
            segments++;
            current_sum = num;
            if (segments > m) {
                return false;
            }
        } else {
            current_sum += num;
        }
    }
    
    return true;
}
int findMinMaxSum(const vector<int>& arr, int m) {
    int left=-0x3f3f3f;
    for(int num:arr){
        if(num>left){
            left=num;
        }
    }
    int right = 0;  
    for (int num : arr) {
        right += num;
    }
    while (left < right) {
        int mid = left + (right - left) / 2; 
        
        if (check(arr, m, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << findMinMaxSum(arr, m) << endl;
    
    return 0;
}

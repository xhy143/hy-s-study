#include<bits/stdc++.h>
using namespace std;
vector<int> multiply(const vector<int>& a, int b) {
    vector<int> result;
    int carry = 0; 
    for (int i = 0; i < a.size(); i++) {
        carry += a[i] * b;
        result.push_back(carry % 10);
        carry /= 10;
    }
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
    return result;
}
void addTo(vector<int>& a, const vector<int>& b) {
    int carry = 0;
    for (size_t i = 0; i < max(a.size(), b.size()) || carry; i++) {
        if (i == a.size()) a.push_back(0); 
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] / 10;
        a[i] %= 10;        
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> factorial = {1}; 
    vector<int> sum = {0};   

    for (int i = 1; i <= n; i++) {
        factorial = multiply(factorial, i); 
        addTo(sum, factorial);            
    }

    for (int i = sum.size() - 1; i >= 0; i--) {
        cout << sum[i];
    }
    cout << endl;

    return 0;
}
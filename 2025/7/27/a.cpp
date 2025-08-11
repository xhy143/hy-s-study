#include<bits/stdc++.h>
using namespace std;
bool leq(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a <= b;
}

int main() {
    int n;
    string a;
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        string prod = "1";
        bool has_zero = false;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] == '0') {
                has_zero = true;
                break;
            }
            int digit = a[j] - '0';
            int carry = 0;
            string tmp = "";
            for (int k = prod.size() - 1; k >= 0; k--) {
                int mul = (prod[k] - '0') * digit + carry;
                tmp += (mul % 10) + '0';
                carry = mul / 10;
            }
            while (carry) {
                tmp += (carry % 10) + '0';
                carry /= 10;
            }
            reverse(tmp.begin(), tmp.end());
            prod = tmp;
            if (!leq(prod,a)) break;
        }
        if (has_zero || leq(prod, a)) {
            cout << "kawaii" << endl;
        } else {
            cout << "dame" << endl;
        }
    }
}
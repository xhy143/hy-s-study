#include <bits/stdc++.h>
using namespace std;
void sor(string num) {
    sort(num.begin(), num.end());
    if (num[0] == '0') {
        for (size_t i = 1; i < num.size(); ++i) {
            if (num[i] != '0') {
                swap(num[0], num[i]);
                break;
            }
        }
    }

    cout << num << endl;
}
int main() {
    string num;
    cin >> num;
    sor(num);
    return 0;
}
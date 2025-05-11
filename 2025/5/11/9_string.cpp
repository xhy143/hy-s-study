#include <bits/stdc++.h>
using namespace std;
string q1(string a, string b) {
    int len1 = a.size();
    int len2 = b.size();
    int len3 = max(len1, len2) + 1;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (a.size() < len3) {
        a += '0';
    }
    while (b.size() < len3) {
        b += '0';
    }
    int carry = 0;
    string ans;
    for (int i = 0; i < len3; i++) {
        int num = (a[i] - '0') + (b[i] - '0') + carry;
        ans += char(num % 10 + '0');
        carry = num / 10;
    }
    if (carry) {
        ans += '1';
    }

    reverse(ans.begin(), ans.end());
    size_t pos = ans.find_first_not_of('0');
    if (pos != string::npos) {
        return ans.substr(pos);
    }
    return "0";
}

int main() {
    string s;
    cin >> s;
    size_t equal_pos = s.find('=');
    if (equal_pos == string::npos) {
        cout << "Impossible!" << endl;
        return 0;
    }
    string left = s.substr(0, equal_pos);
    string right = s.substr(equal_pos + 1);
    for (size_t i = 1; i < left.size(); ++i) {
        string part1 = left.substr(0, i);
        string part2 = left.substr(i);
        if (q1(part1, part2) == right) {
            cout << part1 << "+" << part2 << "=" << right << endl;
            return 0;
        }
    }
    cout << "Impossible!" << endl;
    return 0;
}
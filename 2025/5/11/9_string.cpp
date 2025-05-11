#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    size_t equal_pos = s.find('=');
    if (equal_pos == string::npos) {
        cout << "Impossible!" << endl;
        return 0;

    string left = s.substr(0, equal_pos);
    string right = s.substr(equal_pos + 1);
    long long r = stoll(right);
    for (size_t i = 1; i < left.size(); ++i) {
        string part1 = left.substr(0, i);
        string part2 = left.substr(i);
        long long num1 = stoll(part1);
        long long num2 = stoll(part2);
        if (num1 + num2 == r) {
            cout << part1 << "+" << part2 << "=" << right << endl;
            return 0;
        }
    }
    cout << "Impossible!" << endl;
    return 0;
}
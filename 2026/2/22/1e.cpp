#include <bits/stdc++.h>
using namespace std;
string under_hundred(int x) {
    string units[17] = {
        "zéro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf",
        "dix", "onze", "douze", "treize", "quatorze", "quinze", "seize"
    };
    string tens[7] = {
        "", "", "vingt", "trente", "quarante", "cinquante", "soixante"
    };
    if (x <= 16) return units[x];
    if (x <= 19) {
        if (x == 17) return "dix-sept";
        if (x == 18) return "dix-huit";
        if (x == 19) return "dix-neuf";
    }
    if (x <= 69) {
        int ten = x / 10;
        int unit = x % 10;
        if (unit == 0) return tens[ten];
        if (unit == 1) {
            if (ten == 2) return "vingt et un";
            if (ten == 3) return "trente et un";
            if (ten == 4) return "quarante et un";
            if (ten == 5) return "cinquante et un";
            if (ten == 6) return "soixante et un";
        }
        return tens[ten] + "-" + units[unit];
    }
    if (x <= 79) {
        int unit = x - 60;
        if (unit == 11) return "soixante et onze";
        if (unit == 12) return "soixante-douze";
        if (unit == 13) return "soixante-treize";
        if (unit == 14) return "soixante-quatorze";
        if (unit == 15) return "soixante-quinze";
        if (unit == 16) return "soixante-seize";
        if (unit == 17) return "soixante-dix-sept";
        if (unit == 18) return "soixante-dix-huit";
        if (unit == 19) return "soixante-dix-neuf";
        if (unit == 10) return "soixante-dix";
    }
    int unit = x - 80;
    if (unit == 0) return "quatre-vingts";
    if (unit == 1) return "quatre-vingt-un";
    if (unit <= 9) return "quatre-vingt-" + units[unit];
    unit = x - 90;
    if (unit == 0) return "quatre-vingt-dix";
    if (unit == 1) return "quatre-vingt-onze";
    if (unit == 2) return "quatre-vingt-douze";
    if (unit == 3) return "quatre-vingt-treize";
    if (unit == 4) return "quatre-vingt-quatorze";
    if (unit == 5) return "quatre-vingt-quinze";
    if (unit == 6) return "quatre-vingt-seize";
    if (unit == 7) return "quatre-vingt-dix-sept";
    if (unit == 8) return "quatre-vingt-dix-huit";
    if (unit == 9) return "quatre-vingt-dix-neuf";
    
    return "";
}
string translate_number(long long n) {
    if (n == 0) return "zéro";
    
    vector<string> parts;
    
    long long millions = n / 1000000;
    long long thousands = (n / 1000) % 1000;
    long long rest = n % 1000;
    if (millions > 0) {
        string mil;
        if (millions == 1) {
            mil = "un million";
        } else {
            mil = translate_number(millions) + " millions";
        }
        parts.push_back(mil);
    }
    if (thousands > 0) {
        string thou;
        if (thousands == 1) {
            thou = "mille";
        } else {
            int h = thousands / 100;
            int r = thousands % 100;
            if (h > 0) {
                if (h == 1) {
                    thou = "cent ";
                } else {
                    thou = under_hundred(h) + " cent";
                    if (r == 0) thou += "s";
                    thou += " ";
                }
            }
            if (r > 0) {
                thou += under_hundred(r);
            }
        }
        parts.push_back(thou);
    }
    if (rest > 0) {
        if (millions > 0 || thousands > 0) {
        }
        int h = rest / 100;
        int r = rest % 100;
        string rest_str;
        
        if (h > 0) {
            if (h == 1) {
                rest_str = "cent";
            } else {
                rest_str = under_hundred(h) + " cent";
                if (r == 0) rest_str += "s";
            }
            if (r > 0) rest_str += " ";
        }
        if (r > 0) {
            rest_str += under_hundred(r);
        }
        parts.push_back(rest_str);
    }
    string result;
    for (size_t i = 0; i < parts.size(); i++) {
        if (i > 0) result += " ";
        result += parts[i];
    }
    
    return result;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        cout << translate_number(x) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 100000;

vector<int> primes;
vector<int> lpf; 

void sieve(int n) {
    lpf.resize(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > lpf[i] || i * p > n) break;
            lpf[i * p] = p;
        }
    }
}

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> res;
    while (x > 1) {
        int p = lpf[x];
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        res.push_back(make_pair(p, cnt));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(MAX_A);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    unordered_map<int, vector<int>> prime_powers;
    for (int i = 0; i < N; i++) {
        auto factors = factorize(A[i]);
        for (auto factor : factors) {
            int p = factor.first;
            int cnt = factor.second;
            prime_powers[p].push_back(cnt);
        }
    }

    long long total_cost = 0;
    for (auto it = prime_powers.begin(); it != prime_powers.end(); ++it) {
        int p = it->first;
        vector<int>& powers = it->second;
        
        int m = powers.size();
        vector<int> all_powers = powers;
        for (int k = 0; k < N - m; k++) {
            all_powers.push_back(0);
        }
        
        sort(all_powers.begin(), all_powers.end());
        int median = all_powers[N / 2];
        
        for (int v : powers) {
            total_cost += abs(v - median);
        }
        total_cost += (long long)(N - m) * abs(0 - median);
    }

    cout << total_cost << '\n';

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

vector<int> isprime(1000001, 1);  
vector<int> primes;
void ola(int n) {
    if (n < 2) return; 
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i <= n; i++) {  
        if (isprime[i]) primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            isprime[i * primes[j]] = 0;
            if (i % primes[j] == 0) break;  
        }
    }
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl; 
        return 0;
    }
    ola(n);
    int cnt = primes.size(); 
    cout << cnt + 1 << endl;  
    return 0;
}

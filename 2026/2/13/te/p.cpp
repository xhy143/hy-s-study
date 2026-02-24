#include <iostream>
#include <cmath>

// 快速幂取模
long long powmod(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// 普通快速幂（可能溢出，但 x 和 r2 都不太大时可用）
long long powll(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    const long long MOD1 = 911;
    const long long MOD2 = 1248679;
    const long long TARGET = 20000000;
    const long long MAX_X = 20021231;

    for (long long x = 0; x <= MAX_X; ++x) {
        long long r1 = powmod(x, x, MOD1);
        long long r2 = x % MOD2;
        long long p = powll(x, r2);
        if (r1 + p == TARGET) {
            std::cout << "Found x = " << x << std::endl;
            return 0;
        }
        // 可选：加进度提示
        // if (x % 1000000 == 0) std::cout << "checked " << x << std::endl;
    }
    std::cout << "No solution found." << std::endl;
    return 0;
}
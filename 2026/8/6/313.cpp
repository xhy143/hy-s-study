#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 58954411;

// 简单筛法，直接生成所有质数
vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    // 生成所有质数
    freopen("1.out","w",stdout);
    vector<int> primes = generatePrimes(MAX_N);
    
    // 输出数组定义
    cout << "int maxprime[3503795]={";
    
    // 处理i=0和i=1
    cout << "0,0";
    
    // 从i=2开始处理
    int primeIndex = 0; // 指向当前最大的质数
    for (int i = 2; i <= MAX_N; i++) {
        // 如果当前i等于下一个质数，更新primeIndex
        if (primeIndex + 1 < primes.size() && primes[primeIndex + 1] == i) {
            primeIndex++;
        }
        // 输出当前最大的质数
        cout << "," << primes[primeIndex];
    }
    
    cout << "};" << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <algorithm>  // 添加这个头文件以使用 min 函数
using namespace std;
using namespace std::chrono;

// 函数声明 - 修改参数类型为 long long
vector<int> sieveOfEratosthenes(long long n);  // 改为 long long
vector<int> eulerSieve(int n);  // 保持 int

int main() {
    long long n;  // 改为 long long 以匹配输入
    cout << "请输入上限 n: ";
    cin >> n;
    
    if (n < 2) {
        cout << "没有质数" << endl;
        return 0;
    }
    
    // 检查是否超过 int 范围
    if (n > INT_MAX) {
        cout << "警告：n 超过 int 最大值 (" << INT_MAX << ")" << endl;
        cout << "埃筛将使用 long long 计算，欧筛可能不准确" << endl;
    }
    
    // 测试埃拉托斯特尼筛法
    auto start1 = high_resolution_clock::now();
    vector<int> primes1 = sieveOfEratosthenes(n);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    
    cout << "\n埃拉托斯特尼筛法结果 (" << primes1.size() << " 个质数):" << endl;
    cout << "耗时: " << duration1.count() << " 微秒" << endl;
    
    // 测试欧拉筛法（如果 n 太大，只测试到 INT_MAX）
    if (n > INT_MAX) {
        cout << "\n欧拉筛法：n 太大，跳过计算（超过 int 范围）" << endl;
    } else {
        auto start2 = high_resolution_clock::now();
        vector<int> primes2 = eulerSieve((int)n);
        auto end2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(end2 - start2);
        
        cout << "\n欧拉筛法结果 (" << primes2.size() << " 个质数):" << endl;
        cout << "耗时: " << duration2.count() << " 微秒" << endl;
        
        // 验证结果是否一致
        if (primes1.size() != primes2.size()) {
            cout << "\n警告: 两种方法找到的质数数量不同!" << endl;
            cout << "埃筛: " << primes1.size() << " 个质数" << endl;
            cout << "欧筛: " << primes2.size() << " 个质数" << endl;
        } else {
            bool same = true;
            for (int i = 0; i < (int)primes1.size(); i++) {
                if (primes1[i] != primes2[i]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                cout << "\n验证: 两种方法结果一致" << endl;
            } else {
                cout << "\n警告: 两种方法结果不一致!" << endl;
            }
        }
    }
    
    // 可选：显示前20个质数
    if (!primes1.empty()) {
        cout << "\n前20个质数:" << endl;
        int count = min(20, (int)primes1.size());
        for (int i = 0; i < count; i++) {
            cout << primes1[i] << " ";
            if ((i + 1) % 10 == 0) cout << endl;
        }
        if (count % 10 != 0) cout << endl;
    }
    
    return 0;
}

// 埃拉托斯特尼筛法实现 - 修复版本
vector<int> sieveOfEratosthenes(long long n) {
    // 边界检查
    if (n < 2) return {};
    
    // 使用 vector<char> 避免 vector<bool> 的问题
    vector<char> isPrime(n + 1, 1);
    vector<int> primes;
    
    // 处理 0 和 1
    isPrime[0] = isPrime[1] = 0;
    
    // 计算平方根，避免重复计算
    long long sqrt_n = (long long)sqrt(n);
    
    for (long long i = 2; i <= sqrt_n; i++) {
        if (isPrime[i]) {
            // 从 i*i 开始标记
            // 检查是否溢出
            if (i > 3037000499LL) {  // sqrt(LLONG_MAX) 的近似值
                cout << "警告：i 太大可能导致溢出" << endl;
                break;
            }
            
            long long start = i * i;
            if (start < 0 || start > n) {
                // 溢出或超过 n
                continue;
            }
            
            for (long long j = start; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    
    // 收集质数
    for (long long i = 2; i <= n; i++) {
        if (isPrime[i]) {
            // 检查是否超过 int 范围
            if (i > INT_MAX) {
                cout << "警告：质数 " << i << " 超过 int 范围" << endl;
                // 可以选择跳过或继续
            }
            primes.push_back((int)i);
        }
    }
    
    return primes;
}

// 欧拉筛法实现 - 保持原样但添加检查
vector<int> eulerSieve(int n) {
    if (n < 2) return {};
    
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        
        for (int j = 0; j < (int)primes.size(); j++) {
            // 检查乘法是否溢出
            long long product = (long long)primes[j] * i;
            if (product > n) break;
            
            isPrime[primes[j] * i] = false;
            
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    
    return primes;
}
#include <bits/stdc++.h>

int main() {
    freopen("1.in", "w", stdout);
    const int count = 2097152;
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dis(
        std::numeric_limits<int>::min(),
        std::numeric_limits<int>::max()
    );

    for (int i = 0; i < count; ++i) {
        std::cout << dis(gen) << '\n';
    }

    return 0;
}

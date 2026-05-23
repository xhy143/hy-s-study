#include <bits/stdc++.h>
using namespace std;

// 生成随机连通图
vector<pair<int,int>> generateConnectedGraph(int n, int m) {
    vector<pair<int,int>> edges;
    // 先生成树
    for (int i = 1; i < n; i++) {
        edges.push_back({i-1, i});
    }
    // 随机加边
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, n-1);
    
    while ((int)edges.size() < m) {
        int u = dist(rng);
        int v = dist(rng);
        if (u == v) continue;
        // 检查是否已存在
        bool exists = false;
        for (auto &e : edges) {
            if ((e.first == u && e.second == v) || (e.first == v && e.second == u)) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            edges.push_back({u, v});
        }
    }
    return edges;
}

void writeTestCase(int testId, int n, int m, int a, int b, int c, 
                   vector<pair<int,int>> &edges, vector<int> &output) {
    string filename = "a" + to_string(testId);
    string infile = filename + ".in";
    string outfile = filename + ".out";
    
    // 写入输入文件
    FILE *fin = fopen(infile.c_str(), "w");
    fprintf(fin, "%d %d\n", n, m);
    fprintf(fin, "%d %d %d\n", a, b, c);
    for (auto &e : edges) {
        fprintf(fin, "%d %d\n", e.first, e.second);
    }
    fclose(fin);
    
    // 写入输出文件
    FILE *fout = fopen(outfile.c_str(), "w");
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%d%c", output[i], " \n"[i==n-1]);
    }
    fclose(fout);
    
    printf("Generated test case %d: n=%d, m=%d, a=%d, b=%d, c=%d\n", 
           testId, n, m, a, b, c);
}

int main() {
    // 测试点1：简单树
    {
        int n = 5, m = 4;
        vector<pair<int,int>> edges = {{0,1}, {1,2}, {2,3}, {3,4}};
        vector<int> output = {1, 1, 2, 2, 3};  // 合法划分示例
        writeTestCase(1, n, m, 2, 2, 1, edges, output);
    }
    
    // 测试点2：树，合法子树
    {
        int n = 7, m = 6;
        vector<pair<int,int>> edges = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,6}};
        vector<int> output = {1, 1, 1, 2, 2, 3, 3};
        writeTestCase(2, n, m, 3, 2, 2, edges, output);
    }
    
    // 测试点3：非树，直接DFS树上找到
    {
        int n = 6, m = 7;
        vector<pair<int,int>> edges = {{0,1}, {1,2}, {2,0}, {2,3}, {3,4}, {4,5}, {5,3}};
        vector<int> output = {1, 1, 2, 2, 3, 3};
        writeTestCase(3, n, m, 2, 2, 2, edges, output);
    }
    
    // 测试点4：非树，需要调整子树
    {
        int n = 8, m = 9;
        vector<pair<int,int>> edges = {{0,1}, {1,2}, {2,3}, {3,0}, {3,4}, 
                                        {4,5}, {5,6}, {6,7}, {7,4}};
        vector<int> output = {1, 1, 1, 1, 2, 2, 3, 3};
        writeTestCase(4, n, m, 4, 2, 2, edges, output);
    }
    
    // 测试点5：树，边界a刚好等于子树大小
    {
        int n = 10, m = 9;
        vector<pair<int,int>> edges;
        for (int i = 1; i < n; i++) {
            edges.push_back({i-1, i});
        }
        vector<int> output = {1, 1, 1, 2, 2, 2, 3, 3, 3, 3};
        writeTestCase(5, n, m, 3, 3, 4, edges, output);
    }
    
    // 测试点6：非树，point_g调整
    {
        int n = 9, m = 11;
        vector<pair<int,int>> edges = {{0,1}, {1,2}, {2,0}, {2,3}, {3,4}, 
                                        {4,5}, {5,3}, {5,6}, {6,7}, {7,8}, {8,5}};
        vector<int> output = {1, 1, 1, 1, 2, 2, 3, 3, 3};
        writeTestCase(6, n, m, 4, 2, 3, edges, output);
    }
    
    // 测试点7：树，n=20
    {
        int n = 20, m = 19;
        vector<pair<int,int>> edges;
        for (int i = 1; i < n; i++) {
            edges.push_back({i-1, i});
        }
        vector<int> output(n, 1);
        for (int i = 0; i < 7; i++) output[i] = 1;
        for (int i = 7; i < 14; i++) output[i] = 2;
        for (int i = 14; i < n; i++) output[i] = 3;
        writeTestCase(7, n, m, 7, 7, 6, edges, output);
    }
    
    // 测试点8：非树，链加一条回边
    {
        int n = 20, m = 20;
        vector<pair<int,int>> edges;
        for (int i = 1; i < n; i++) {
            edges.push_back({i-1, i});
        }
        edges.push_back({19, 0});
        vector<int> output(n, 1);
        for (int i = 0; i < 8; i++) output[i] = 1;
        for (int i = 8; i < 14; i++) output[i] = 2;
        for (int i = 14; i < n; i++) output[i] = 3;
        writeTestCase(8, n, m, 8, 6, 6, edges, output);
    }
    
    // 测试点9：复杂非树，多个环
    {
        int n = 15, m = 20;
        vector<pair<int,int>> edges = {{0,1}, {1,2}, {2,0}, {2,3}, {3,4}, 
                                        {4,5}, {5,2}, {5,6}, {6,7}, {7,8}, 
                                        {8,6}, {8,9}, {9,10}, {10,11}, {11,9}, 
                                        {11,12}, {12,13}, {13,14}, {14,12}, {14,8}};
        vector<int> output(n, 1);
        for (int i = 0; i < 5; i++) output[i] = 1;
        for (int i = 5; i < 10; i++) output[i] = 2;
        for (int i = 10; i < n; i++) output[i] = 3;
        writeTestCase(9, n, m, 5, 5, 5, edges, output);
    }
    
    // 测试点10：正常数据，n=100, m=200
    {
        int n = 100, m = 200;
        auto edges = generateConnectedGraph(n, m);
        vector<int> output(n, 1);
        // 随机分配，但保证至少两个集合连通
        for (int i = 0; i < n/3; i++) output[i] = 1;
        for (int i = n/3; i < 2*n/3; i++) output[i] = 2;
        for (int i = 2*n/3; i < n; i++) output[i] = 3;
        
        int a = 33, b = 33, c = 34;
        writeTestCase(10, n, m, a, b, c, edges, output);
    }
    
    printf("\nAll 10 test cases generated successfully!\n");
    printf("Files: a1.in/a1.out to a10.in/a10.out\n");
    
    return 0;
}
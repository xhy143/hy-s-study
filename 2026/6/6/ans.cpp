#include<cstdio>
using namespace std;

const int N = 2097152;

int main() {
    // 缓冲区需要足够大：数据约 20-30MB，用 32MB 确保安全
    char buf[1 << 25];  // 32MB 缓冲区
    size_t len = fread(buf, 1, sizeof(buf), stdin);
    char* p = buf;
    char* end = buf + len;
    
    char out[1 << 22];  // 4MB 输出缓冲区
    char* op = out;
    int sum = 0;
    
    for(int i = 0; i < N && p < end; i++) {
        // 跳过空白字符
        while(p < end && (*p == ' ' || *p == '\n' || *p == '\r')) p++;
        if(p >= end) break;
        
        // 解析整数
        int x = 0;
        int sign = 1;
        if(*p == '-') {
            sign = -1;
            p++;
        }
        while(p < end && *p >= '0' && *p <= '9') {
            x = x * 10 + (*p - '0');
            p++;
        }
        x *= sign;
        
        // 累加
        sum += x;
        
        // 输出
        op += sprintf(op, "%d\n", sum);
    }
    fwrite(out, 1, op - out, stdout);
    
    return 0;
}
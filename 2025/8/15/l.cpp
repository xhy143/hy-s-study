#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#define maxn 500010
using namespace std;
int d,n,m;
int a[maxn];
int l,r,mid,ans;
inline int read(){//我喜欢快读
    int num = 0;
    char c;
    bool flag = false;
    while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
        if (c == '-') flag = true;
    else
        num = c - '0';
    while (isdigit(c = getchar()))
    num = num * 10 + c - '0';
    return (flag ? -1 : 1) * num;
}

bool judge(int x){//judge函数，x代表当前二分出来的答案
    int tot = 0;//tot代表计数器，记录以当前答案需要移走的实际石头数
    int i = 0;//i代表下一块石头的编号
    int now = 0;//now代表模拟跳石头的人当前在什么位置
    while (i < n+1){//千万注意不是n，n不是终点，n+1才是
        i++;
        if (a[i] - a[now] < x)//判断距离，看二者之间的距离算差值就好
            tot++;//判定成功，把这块石头拿走，继续考虑下一块石头
        else
            now = i;//判定失败，这块石头不用拿走，我们就跳过去，再考虑下一块
    }
    if (tot > m)
        return false;
    else
        return true;
}

int main(){
    d = read();//d代表总长度，也就是右边界
    n = read();//n块石头
    m = read();//限制移走m块，思考的时候可别被这个m限制
    for (int i=1;i<=n;i++)
        a[i] = read();
    a[n+1] = d;//敲黑板划重点，再强调一遍，n不是终点
    l = 1;//l和r分别代表二分的左边界和右边界
    r = d;
    while (l <= r){//非递归式二分正常向写法，可理解为一般框架
        mid = (l+r) / 2;//这再看不出是啥意思可以退群了
        if (judge(mid)){//带入judge函数判断当前解是不是可行解
            ans = mid;
            l = mid + 1;//走到这里，看来是可行解，我们尝试看看是不是有更好的可行解
        }
        else
            r = mid - 1;//噫，你找了个非法解，赶紧回到左半边看看有没有可行解
    }
    cout << ans << endl;//最后的ans绝对是最优解
    return 0;
}

/**
* @runId: 517749
* @language: C++
* @author: 13418032657
* @submitTime: 2023-08-08 14:34:06
*/

/**
* @runId: 3253893
* @language: C++
* @author: 13418032657
* @submitTime: 2024-04-13 13:15:58
*/

/**
* @runId: 3254655
* @language: C++
* @author: 13418032657
* @submitTime: 2024-04-13 13:35:27
*/
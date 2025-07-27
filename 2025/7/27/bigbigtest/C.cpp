#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    int x=8,y=5;
    y=x^y;
    x=x^y;
    y=x^y;
    cout<<x<<y;
}
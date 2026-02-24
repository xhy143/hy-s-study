#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("scalerotate.in","r",stdin);
    freopen("scalerotate.out","w",stdout);
    int R, K, H, W;
    cin >> R >> K >> H >> W;
    vector<string> img(H);
    for (int i = 0; i < H; i++) {
        cin >> img[i];
    }
    int newH, newW;
    if (R == 0 || R == 180) {
        newH = H;
        newW = W;
    } else {
        newH = W;
        newW = H;
    }
    vector<string> rotated(newH, string(newW, ' '));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int r, c;
            if (R == 0) {
                r = i; c = j;
            } else if (R == 90) {
                r = j; c = H - 1 - i;
            } else if (R == 180) {
                r = H - 1 - i; c = W - 1 - j;
            } else { 
                r = W - 1 - j; c = i;
            }
            rotated[r][c] = img[i][j];
        }
    }
    vector<string> result(newH * K, string(newW * K, ' '));
    for (int r = 0; r < newH; r++) {
        for (int c = 0; c < newW; c++) {
            char ch = rotated[r][c];
            for (int dr = 0; dr < K; dr++) {
                for (int dc = 0; dc < K; dc++) {
                    result[r * K + dr][c * K + dc] = ch;
                }
            }
        }
    }
    for (auto line : result) {
        cout << line << endl;
    }
    
    return 0;
}
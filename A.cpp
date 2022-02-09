#include<iostream>
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int tb[1000][1000];
    int m, n, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        tb[x - 1][y - 1] = 1;
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << tb[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
#include<iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tb[1000][1000];
    int n, m, x, y;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y; x--; y--;
        if (tb[x][y] == 1 || tb[y][x] == 1) {
            cout << "YES";
            return 0;
        }
        tb[x][y] = 1;
    }
    cout << "NO";
    return 0;
}
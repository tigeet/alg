#include<iostream>
#include<vector>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, n; cin >> n;
    vector<vector<int>> v(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            v[i].push_back(x);

            if (i == j && x == 1) {
                cout << "NO";
                return 0;
            }
            
            if (i > j && v[i][j] != v[j][i]) {
                cout << "NO";
                return 0;
            }
        }
    }
    
    cout << "YES";
    return 0;
}
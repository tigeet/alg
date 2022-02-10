#include<iostream>
#include<vector>
#include<queue>

using namespace std;

enum color {WHITE, GRAY, BLACK};

typedef struct st *  V;
struct st {
    int i;
    int j;
    int color;
    string path;
};


vector<V> adj(vector<vector<V>> &G, V v, int n, int m) {
    int seq_j[4] = {-1, 1, 0, 0}; 
    int seq_i[4] = {0, 0, -1, 1};
    string dir[4] = {"L", "R", "U", "D"};
    vector<V> res;
    for (int p = 0; p < 4; ++p) {
        int i = v->i + seq_i[p];
        int j = v->j + seq_j[p];
        if (i >= 0 && j >= 0 &&  i < n && j  < m) {
            V v_ =  G[i][j];
            if ( v_ && v_->color == WHITE) {
                v_->color = GRAY;
                v_->path =  v->path + dir[p];
                res.push_back(v_);
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; 
    char c;
    cin >> n >> m;
    V start, finish;
    vector<vector<V>> G(n, vector<V>(m, nullptr));
    queue<V> Q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            V temp = new st {i, j, WHITE, ""};
            
            if (c == 'S') 
                start = temp;
            else if (c == 'T') 
                finish = temp;
             
            if (c != '#')
                G[i][j] = temp;
        }
    }

    Q.push(start);
    while (!Q.empty()) {
        V v = Q.front(); Q.pop();
        v->color = BLACK;

        if (v == finish) {
            cout << v->path.length() << "\n" << v->path;
            return 0;
        }
        for (auto v_ : adj(G, v, n, m)) {
            Q.push(v_);
        }
    }
    
    cout << -1;
    return 0;
}
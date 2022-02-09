#include<iostream>
#include<queue>
using namespace std;

enum cell_state {OBSTACLE = -1, S = -2, T = -3};

enum color {W, GRAY, B};
typedef struct st *  V;
struct st {
    
    vector<V> adj;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);

    int n, m, b, e;
    cin >> n >> m;
    
    queue<V> Q;
    vector<V> G(n);    

    for (int i = 0; i < n; ++i) {
        V v = new st {i + 1, W, 0, vector<V>(0)};
        G[i] = v;
    }


    for (int i = 0; i < m; ++i) {
        cin >> b >> e;
        V v1 = G[b - 1];
        V v2 = G[e - 1];
        v1->adj.push_back(v2);
        v2->adj.push_back(v1);
    }

    Q.push(G[0]);
    while (!Q.empty()) {
        V v = Q.front(); Q.pop();
        v->color = B;
        for (auto v_ : v->adj) {
            if (v_->color == W) {
                v_->d = v->d + 1;
                v_->color = GRAY;
                Q.push(v_);
            }
        }
    }

    for (auto v : G) {
        cout << v->d << " ";
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 
enum color {WHITE, GRAY, BLACK};
typedef struct st *  V;
struct st {
    int id;
    int color;
    vector<V> adj;
    V parent;
};


void DFS(V v, stack<V> &S) {
    v->color = GRAY;
    for (V u: v->adj) {
        if (u->color == WHITE)
            DFS(u, S);

    }
    v->color = BLACK;
    S.push(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
     
    int n, m, b, e;
    cin >> n >> m;
    vector<V> G(n, nullptr);
    stack<V> S;
    for (int i = 0; i < n; ++i) {
        V v = new st {i + 1, WHITE, vector<V>(0), 0};
        G[i] = v;
    }
 
    for (int i = 0; i < m; ++i) {
        cin >> b >> e;
        V v1 = G[b - 1];
        V v2 = G[e - 1];
        v1->adj.push_back(v2);
    }
    

    for (V v : G)
        if (v->color == WHITE)
            DFS(v, S);

    V v, u;
    bool flag = true;
    v = S.top(); S.pop();
    while (!S.empty()) {
        u = S.top();
        S.pop();

        bool c = false;
        for (auto adj : v->adj)
            if (adj->id == u->id) {
                c = true;
                break;
            }
        if (c == false) {
            flag = false;
            break;
        }

        v = u;
    }
    if (flag)
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}
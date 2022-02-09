#include<iostream>
#include<vector>
using namespace std;

int g = 0;
enum color {WHITE, GRAY, BLACK};

typedef struct st *  V;
struct st {
    int id;
    int color;
    int group;
    vector<V> adj;
};


void DFS_VISIT(vector<V> &G, V v, int g) {
    v->group = g;
    v->color = GRAY;
    for (auto u : v->adj) {
        if (u->color == WHITE) {
            DFS_VISIT(G, u, g);
        }
    }
    v->color = BLACK; // ?
}

void DFS(vector<V> &G) {
    for (auto v : G) {
        if (v->color == WHITE) {
            g += 1;
            DFS_VISIT(G, v, g);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
    
    int n, m, b, e; 
    cin >> n >> m;
    vector<V> G(n);    

    for (int i = 0; i < n; ++i) {
        V v = new st {i + 1, WHITE, 0, vector<V>(0)};
        G[i] = v;
    }

    for (int i = 0; i < m; ++i) {
        cin >> b >> e;
        V v1 = G[b - 1];
        V v2 = G[e - 1];
        v1->adj.push_back(v2);
        v2->adj.push_back(v1);
    }

    DFS(G);

    cout << g << "\n";
    for (int i = 0; i < n; ++i) {
        cout << G[i]->group << " ";
    }

    return 0;
}
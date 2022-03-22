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


bool DFS(V v, stack<int> &S) {
    v->color = GRAY;
    bool flag = true;
    for (V u: v->adj) {
        if (u->color == WHITE) {
            // u->parent = v;
            flag = flag && DFS(u, S);
        } else if (u->color == GRAY) {
            // u->parent = v;
            flag = false;
            break;
        }
    }
    v->color = BLACK;
    S.push(v->id);
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
     
    int n, m, b, e;
    cin >> n >> m;
    vector<V> G(n, nullptr);    
    stack<int> S;
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
    
    bool res = true;
    for (V v : G) {
        if (v->color == WHITE) {
            res = res  && DFS(v, S);
        }
    }
    if (res == true) {
        while (!S.empty()) {
            cout << S.top() << " ";
            S.pop();
        }
    } else {
        cout << -1;
    }
    return 0;
}
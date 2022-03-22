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

V c;
bool DFS(V v) {
    v->color = GRAY;
    bool flag = true;
    for (V u: v->adj) {
        if (u->color == WHITE) {
            u->parent = v;
            flag = flag && DFS(u);
        } else if (u->color == GRAY) {
            u->parent = v;
            c = u;
            flag = false;
            break;
        }
    }
    v->color = BLACK;
    return flag;
}


void print_path(V v, V c) {
    if (v->id != c->id) 
        print_path(v->parent, c);
    cout << v->id << " ";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
     
    int n, m, b, e;
    cin >> n >> m;
    vector<V> G(n, nullptr);    
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
            res = res  && DFS(v);
        }
    }
    if (res == true) {
        cout << "NO";
    } else {
        cout << "YES\n";
        print_path(c->parent, c);
        // auto obj = c->parent;
        // while (obj->id != c->id) {
        //     cout << obj->id << " ";
        //     obj = obj->parent;
        // }
        // cout << obj->id;
    }
    return 0;
}
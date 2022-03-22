#include<iostream>
#include<vector>
#include<stack>
using namespace std;
  
enum color {L, R};
typedef struct st *  V;
struct st {
    int id;
    int group;
    vector<V> adj;
};
 
int inv_group(V v) {
    if (v->group == L)
        return R;
    return L;
}
 
bool flag = true;
void set_group(V v) {
    for (auto u :v->adj) {
        if (u->group == 0) {
            u->group = inv_group(v);
            set_group(u);
        } else if (u->group == v->group) {
            flag = false;
            break;
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
      
    int n, m;
    cin >> n >> m;
    vector<V> G(n, nullptr);
    for (int i = 0; i < n; ++i) {
        V v = new st {i + 1, 0, vector<V>(0)};
        G[i] = v;
    }
 
    V v1, v2;
    int b, e;
    for (int i = 0; i < m; ++i) {
        cin >> b >> e;
        v1 = G[b - 1];
        v2 = G[e - 1];
        v1->adj.push_back(v2);
        v2->adj.push_back(v1);
    }
 
    for (auto vertex : G) {
        if (vertex->group == 0) {
            vertex->group = L;
            set_group(vertex);
            if (flag == false)
                break;
        }
    }
     
    if (flag) 
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
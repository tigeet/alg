#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 
enum color {WHITE, GRAY, BLACK};

vector<vector<int>> V1, V2;
vector<int> cl;
vector<int> gr;

void DFS(int v, stack<int> &S) {
    cl[v] = GRAY;
    for (int u: V1[v]) {
        // cout << u << " ";
        if (cl[u] == WHITE) {
            DFS(u, S);
        }
    }
    cl[v] = BLACK;
    S.push(v);
}

void F(int v, int g) {
    gr[v] = g;
    for (int u: V2[v]) {
        if (gr[u] == 0)
            F(u, g);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
     
    int n, m, b, e;
    cin >> n >> m;
    stack<int> S;
    V1 = vector<vector<int>> (n, vector<int>(0, 0));
    V2 = vector<vector<int>> (n, vector<int>(0, 0));
    gr = vector<int>(n, 0);
    cl = vector<int> (n, 0);

    for (int i = 0; i < m; ++i) {
        cin >> b >> e;
        --b; --e;
        V1[b].push_back(e);
        V2[e].push_back(b);
    }
    
    for (int v = 0; v < n; ++v) {
        if (cl[v] == WHITE) {
            DFS(v, S);
        }
    }

    int group = 0;
    while (!S.empty()) {
        int v = S.top(); S.pop();
        if (gr[v] == 0) {
            group++;
            F(v, group);
        }
    }

    cout << group << "\n";
    for (int g: gr) 
        cout << g << " ";
    return 0;
}
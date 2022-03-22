#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 
enum color {WHITE, GRAY, BLACK};

vector<vector<int>> V;
vector<int> cl;
vector<int> st;

void DFS(int v) {
    cl[v] = GRAY;
    int p = 2;
    for (int u: V[v]) {
        if (cl[u] == WHITE)
            DFS(u);
        if (st[u] == 2) {
            p = 1;
        }
    }
    
    st[v] = p;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
     
    int n, m, s, b, e;
    cin >> n >> m >> s;
    V = vector<vector<int>> (n, vector<int>(0, 0));
    st = vector<int>(n, 2);
    cl = vector<int> (n, 0);

    for (int i = 0; i < m; ++i) {
        cin >> b >> e;
        --b; --e;
        V[b].push_back(e);
    }
    DFS(s - 1);
    if (st[s - 1] == 1)
        cout << "First player wins";
    else
        cout << "Second player wins";
    return 0;
}
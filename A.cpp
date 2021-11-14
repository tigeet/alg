#include<iostream>
using namespace std;

int l[200001]{};
int r[200001]{};
int n, v;


void h(int i, int k) {
    v = max(v, k);
    if (l[i])
        h(l[i], k + 1);
    if (r[i])
        h(r[i], k + 1);    
}


int main() {
    freopen("assets/t.txt", "r", stdin);
    //freopen("assets/t.txt", "w", stdout);

    cin >> n;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t >> l[i] >> r[i];
        if (l[i])
            --l[i];
        if (r[i])
            --r[i];    
    }

    if (n) {
        h(0, 1);
        cout << v;
    } else 
        cout << 0;
}
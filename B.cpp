#include<iostream>
using namespace std;
#include<limits>
int k[200001]{};
int l[200001]{};
int r[200001]{};
int n, v;
int f = 1;




void correct(int p, int lb, int ub) {
    int t;
    if (l[p] != 0) {
        t = min(ub, k[p]);
        if (lb < k[l[p]] && k[l[p]] < t) {
            correct(l[p], lb, t);
        } else {
            f = 0;
            return ;
        }
    }

    if (r[p] != 0) {
        t = max(lb, k[p]);
        if (t< k[r[p]] && k[r[p]] < ub) {
            correct(r[p], t, ub);
        } else {
            f = 0;
            return ;
        }
    }
}

int main() {
    freopen("assets/t.txt", "r", stdin);
    //freopen("assets/t.txt", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> k[i] >> l[i] >> r[i];
        if (l[i])
            --l[i];
        if (r[i])
            --r[i];
    }
    
    
    correct(0, INT_MIN, INT_MAX);

    (f) ? cout << "YES\n" : cout << "NO\n";

    return 0;
}
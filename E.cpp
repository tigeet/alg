#include<iostream>
#include<fstream>
#include<random>
using namespace std;
 
  
int list[100000];
int n, k, q;
 
int binl(int x) {
    int l = -1;
    int r = n;
    int m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (x > list[m])
            l = m;
        else if (x <= list[m])
            r = m;       
    }
    return (r >= 0 && list[r] == x) ? r + 1: -1;
}
 
 
 
int binr(int x) {
    int l = -1; int r = n;
    int m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (x < list[m])
            r = m;
        else if (x >= list[m])
            l = m;
    }
 
    return (list[r - 1] == x) ? r: -1;
}
 
 
int main() {
    ifstream fin; fin.open("binsearch.in");
    ofstream fout; fout.open("binsearch.out");
     
    fin >> n;
    for (int i = 0; i < n; ++i)
        fin >> list[i];
    fin >> k;
    for (int i = 0; i < k; ++i) {
        fin >> q;
        fout << binl(q) << " " << binr(q) << "\n";
    }
    return 0;
}
#include<iostream>
#include<fstream>
#include <iomanip>
 
using namespace std;
 
double list[1000];
int n;
 
 
bool build(double x) {
    bool f = 1;
    list[1] = x;
    for (int i = 2; i < n; ++i) {
        list[i] = 2*(list[i - 1] + 1) - list[i - 2];
        if (list[i] < 0)
            f = 0;
    }
    return f;
     
}
 
 
 
void bin() {
    double l = 0; double r = list[0];
    double m;
    bool c;
    while (r - l > 0.00000001) {
        m = (l + r) / 2;
        c = build(m);
        if (c) 
            r = m;
        else
            l = m;   
    }
}
 
int main() {
    fstream fin; 
    fin.open("garland.in");
    ofstream fout; 
    fout.open("garland.out");
    fin >> n >> list[0];
 
    bin();
    fout << fixed;
    fout.precision(2);
    fout << list[n - 1];
    return 0;
}
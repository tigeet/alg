#include<fstream>
#include<iostream>
 
using namespace std;
 
 
 
int queue[1000000];
int l = 0, r = 0, n;
 
void push(int n) {
    queue[r++] = n;
}
 
int pop() {
    return queue[l++];
}
 
 
int main(){ 
    fstream fin; fin.open("queue.in");
    ofstream fout; fout.open("queue.out");
    int v; char c;
 
    fin >> n;
 
    for (int i = 0; i < n; ++i) {
        fin >> c;
        if (c == '+') {
            fin >> v;
            push(v);
        }
        else fout << pop() << '\n';
    }
 
 
    return 0;
}
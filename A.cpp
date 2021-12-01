#include<fstream>
#include<iostream>
 
using namespace std;
 
 
 
int stack[1000000];
int p = 0, n;
 
void push(int n) {
    stack[p++] = n;
}
 
int pop() {
    return stack[--p];
}
 
 
int main(){ 
    ifstream fin; fin.open("stack.in");
    ofstream fout; fout.open("stack.out");
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
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
 
 
int stack[100];
int p = 0;
 
int pop() {
    return stack[--p];
}
 
 
void push(int x) {
    stack[p++] = x;
}
 
 
 
int main () {
    ifstream fin; fin.open("postfix.in");
    ofstream fout; fout.open("postfix.out");
    char c; int t;
    string s; getline(fin, s);
    for (int i = 0; i < s.length(); ++i) {
        c = s[i];
        if (c == '+')
            push(pop() + pop());
        else if (c == '-') {
            t = pop();
            push(pop() - t);
        }
        else if (c == '*') {
            push(pop() * pop());
        }
        else if ('0' <= c  && c <= '9') {
            push(c - '0');
        }
    }
 
    fout << pop();
 
    return 0;
}
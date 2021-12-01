#include<iostream>
#include<fstream>
#include<string>
using namespace std;
 
char stack[1000];
int p = 0;
 
void push(char c) {
    stack[p++] = c;
}
 
char pop() {
    if (p == 0) 
        return '\0';
    else
        return stack[--p];
}
 
int main() {
    ifstream fin; fin.open("brackets.in");
    ofstream fout; fout.open("brackets.out");
 
     
    string line;
    while (getline(fin, line)) {
        p = 0; bool f = 1;
        for (int i = 0; i < line.length() && f; ++i) {
            char c = line[i];
            if (c == '(' || c == '[') {
                push(c);
            } else if (c == ']') {
                char t = pop();
                if (t == '\0' || t != '[')
                    f = 0;
            } else if (c == ')') {
                char t = pop();
                if (t == '\0' || t != '(')
                    f = 0;
            }
        }
        (f && !p) ? fout << "YES\n" : fout << "NO\n";
    }
    return 0;
}
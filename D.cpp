#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
using namespace std;

void put(int x);
int get();
void putReg(char c, int x);
int getReg(char c);

queue<int> q;
vector<string> com;
map<string, int> label;
int reg[26]{0};
int c = 0;
int n = 0;

int main() {
    freopen("assets/t.txt", "r", stdin);

    string s;
    while (cin >> s) {
        com.push_back(s);
        if (s[0] == ':')
            label[s.substr(1, s.length() - 1)] = n;
        n++;
    }
    bool f = 1;
    char t, r1, r2;
    while (c < n && f) {
        s = com[c];
        t = s[0];
        switch(t) {
            case '+':
                put(get() + get());
                ++c;
                break;
            case '-':
                put(get() - get());
                ++c;
                break;
            case '*':
                put(get() * get());
                ++c;
                break;
            case '/':
                put(get() / get());
                ++c;
                break;
            case '%':
                put(get() % get());
                ++c;
                break;
            case '>': 
                r1 = s[1];
                putReg(r1, get());
                ++c;
                break;
            
            case '<': 
                r1 = s[1];
                put(getReg(r1));
                ++c;
                break;
            
            case 'P': 
                if (s == "P")
                    cout << get() << "\n";
                else {
                    r1 = s[1];
                    cout << getReg(r1) << "\n";
                }
                ++c;
                break;
            
            case 'C': 
                if (s == "C")
                    cout << (char) get() << "\n";
                else {
                    r1 = s[1];
                    cout << (char) getReg(r1) << "\n";
                }
                ++c;
                break;
            case ':': 
                ++c;
                break;
            case 'J':
                c = label[s.substr(1, s.length() - 1)];
                break;
            case 'Z': 
                r1 = s[1];
                if (getReg(r1) == 0)
                    c = label[s.substr(2, s.length() - 2)];
                else ++c;
                break;
            case 'E': 
                r1 = s[1]; 
                r2 = s[2];
                if (getReg(r1) == getReg(r2))
                    c = label[s.substr(3, s.length() - 3)];
                else ++c;
                break;
            
            case 'G':
                r1 = s[1]; 
                r2 = s[2];
                if (getReg(r1) > getReg(r2))
                    c = label[s.substr(3, s.length() - 3)];
                else ++c;
                break;
            case 'Q':
                f = 0;
                break;
            default:
                put(stoi(s));
                ++c;
                break;
        }


    }
}

void put(int x) {
    q.push(x);
}

int get() {
    int t = q.front();
    q.pop();
    return t;
}

void putReg(char c, int x) {
    reg[c - 'a'] = x;
}

int getReg(char c) {
    return reg[c - 'a'];
}
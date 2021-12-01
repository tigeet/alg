#include<iostream>
#include<vector>
#include<string>
using namespace std;
   
typedef struct st* Obj;
struct st {
    string key;
    string val;
    Obj next;
    Obj prev;
};
   
const int m = 100000;
Obj table[m]{};
   
int divhash(string key) {
    int k = 0;
    for (char c: key)    
        k = (k * CHAR_MAX + c) % m; 
    return k;
}
   
Obj build(string key, string value) {
    Obj obj = new st;
    obj->key = key;
    obj->val = value;
    obj->next = 0;
    obj->prev = 0;
    return obj;
}
   
Obj search(string key) {
    int h = divhash(key);
    Obj obj = table[h];
    while (obj && obj->key != key) {
        obj = obj->next;
    }
    return obj;
}
   
Obj insert(string key, string val) {
    Obj obj = search(key);
    if (obj == 0) {
        int h = divhash(key);
        obj = build(key, val);
   
        obj->next = table[h];
        obj->prev = 0;
        if (table[h])
            table[h]->prev = obj;
   
        table[h] = obj;
    } else {
        obj->val = val;
    }
    return obj;
}
   
void del(string key) {
    Obj obj = search(key);
    if (obj) {
        int h = divhash(key);
        if (table[h] == obj) {
            table[h] = obj->next;
        } else {
            if (obj->next)
                obj->next->prev = obj->prev;
            obj->prev->next = obj->next;
        }
    }
}
   
int main() {
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
      
    string s, x, y;
    while (cin >> s >> x) {
        if (s == "put") {
            cin >> y;
            insert(x, y);
        } else if (s == "get") {
            Obj obj = search(x);
            if (obj)
                cout << obj->val << "\n";
            else
                cout << "none\n"; 
        } else if (s == "delete") {
            del(x);
        }
    }
    return 0;
}
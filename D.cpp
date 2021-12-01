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
       
const int h = 1000, w = 10000;
Obj table[h][w]{};
       
int divhash(string key, int p) {
    int k = 0;
    for (char c: key)    
        k = (k * CHAR_MAX + c) % p; 
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
   
Obj search(string key, string val) {
    int h_ = divhash(key, h);
    int w_ = divhash(val, w);
    Obj obj = table[h_][w_];
    while (obj) {
        if ( obj->key == key && obj->val == val)
            break;
        obj = obj->next;
    }
    return obj;
}
       
Obj insert(string key, string val) {
    Obj obj = search(key, val);
    if (!obj) {
        int h_ = divhash(key, h);
        int w_ = divhash(val, w);
        obj = build(key, val);
    
        obj->next = table[h_][w_];
        obj->prev = 0;
        if (table[h_][w_])
            table[h_][w_]->prev = obj;
    
        table[h_][w_] = obj;
    }
    return obj;
}
       
void del(string key, string val) {
    Obj obj = search(key, val);
    if (obj) {
        int h_ = divhash(key, h);
        int w_ = divhash(val, w);
        if (table[h_][w_] == obj) {
            table[h_][w_] = obj->next;
            if (obj->next)
                obj->next->prev = 0;
        } else {
            if (obj->next)
                obj->next->prev = obj->prev;
            obj->prev->next = obj->next;
        }
    }
}
  
void deleteall(string key) {
    int h_ = divhash(key, h);
    for (int i = 0; i < w; ++i) {
        Obj obj = table[h_][i];
        Obj temp;
        while (obj) {
            temp = obj;
            if (obj->key == key) {
                if (table[h_][i] == obj) {
                    table[h_][i] = obj->next;
                    if (obj->next)
                        obj->next->prev = 0;
                } else {
                    if (obj->next)
                        obj->next->prev = obj->prev;
                    obj->prev->next = obj->next;
                }
            }
            obj = temp->next;
        }
    }
}
void get(string key) {
    int h_ = divhash(key, h);
    int c = 0; string s = "";
    for (const auto &t : table[h_]) {
        Obj obj = t;
        while (obj) {
            if (obj->key == key) {
                ++c;
            }
            obj = obj->next;
        }
    }
    cout << c;
    for (const auto &t : table[h_]) {
        Obj obj = t;
        while (obj) {
            if (obj->key == key) {
                cout << " " << obj->val;
            }
            obj = obj->next;
        }
    }
    cout << '\n';
}
    
int main() {
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            table[i][j] = 0;
  
    string s, x, y;
    while (cin >> s >> x) {
        if (s == "put") {
            cin >> y;
            insert(x, y);
        } else if (s == "get") {
            get(x);
        } else if (s == "delete") {
            cin >> y;
            del(x, y);
        } else if (s == "deleteall") {
            deleteall(x);
        }
    }
    return 0;
}
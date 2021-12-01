#include <iostream>
#include <vector>
#include <string.h>
 
using namespace std;
 
int divhash(int key) {
    return abs(key % 1000001);
}
 
struct Obj {
    Obj* next;
    int key;
};
 
bool exists(vector <Obj*>& table, int key) {
    int h = divhash(key);
    Obj* obj = table[h];
    bool res = false;
 
    while (obj != NULL) {
        if (obj->key == key) {
            res = true;
            break;
        }
        obj = obj->next;
    }
 
    return res;
}
 
void insert(vector <Obj*>& table, int key) {
    Obj* obj, * obj1;
    int h = divhash(key);
 
    if (exists(table, key))
        return;
 
    obj = table[h];
 
    if (obj == NULL) {
        obj1 = new Obj;
        obj1->key = key;
        obj1->next = NULL;
        table[h] = obj1;
    }
    else {
        while (obj->next != NULL)
            obj = obj->next;
 
        obj1 = new Obj;
        obj1->key = key;
        obj1->next = NULL;
        obj->next = obj1;
    }
}
 
void del(vector <Obj*>& table, int key) {
    int h = divhash(key);
    Obj* obj = table[h], *obj1 = NULL;
 
    if (obj == NULL)
        return;
 
    while (obj != NULL) {
        if (obj->key == key) {
            if (obj1 == NULL) {
                table[h] = obj->next;
                delete obj;
            }
            else {
                obj1->next = obj->next;
                delete obj;
            }
            return;
        }
        obj1 = obj;
        obj = obj->next;
    }
}
 
int main(void) {
    vector <Obj*> table(1000001);
 
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s; int key;
    while (cin >> s) {
        if (s == "insert") {
            cin >> key;
            insert(table, key);
        }
        else if (s == "exists") {
            cin >> key;
            if (exists(table, key)) 
                cout << "true\n";
            else
                cout << "false\n";
        }
        else if (s == "delete") {
            cin >> key;
            del(table, key);
        }
    }
 
    return 0;
}
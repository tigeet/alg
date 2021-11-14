#include<iostream>
using namespace std;

typedef struct lf * Leaf;
struct lf {
    int key;
    Leaf parent;
    Leaf left;
    Leaf right;
};

Leaf successor(Leaf x);
Leaf predeccessor(Leaf x);
void transpl(Leaf u, Leaf v);
Leaf build(int x);
void insert(Leaf p, Leaf x);
Leaf search(int x);
Leaf min(Leaf x);
Leaf max(Leaf x);
void del(Leaf x);
Leaf prev(int x);
Leaf next(int x);
Leaf add(int x);
Leaf root = 0;


int main() {
    freopen("assets/t.txt", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    string s; int x; Leaf f;

    while (cin >> s >> x) {
        if (s == "insert") {
            add(x);
        } else if (s == "exists") {
            f = search(x);
            if (f)
                cout << "true\n";
            else 
                cout << "false\n";
        } else if (s == "next") {
            f = next(x);
            if (f)
                cout << f->key << "\n";
            else 
                cout << "none\n";
        } else if (s == "prev") {
            f = prev(x);
            if (f)
                cout << f->key << "\n";
            else 
                cout << "none\n";
        } else if (s == "delete") {
            f = search(x);
            if (f)
                del(f);
        }
    }
    return 0;
}


Leaf build(int x) {
    Leaf leaf = new lf;
    leaf->key = x;
    leaf->left = 0;
    leaf->right = 0;
    leaf->parent = 0;
    return leaf;
}

Leaf add(int x) {
    Leaf lf = search(x);
    if (lf == 0) {
        lf = build(x);
        if (root)
            insert(root, lf);
        else root = lf;
    }
    return lf;
}

void insert(Leaf p, Leaf x) {
    if (x->key < p->key) {
        if (p->left)
            insert(p->left, x); 
        else {
            p->left = x;
            x->parent = p;
        }
    } else {
        if (p->right)
            insert(p->right, x); 
        else {
            p->right = x;
            x->parent = p;
        }
    }
}

Leaf search(int x) {
    Leaf leaf = root;
    while (leaf && leaf->key != x) {
        if (x < leaf->key)
            leaf = leaf->left;
        else leaf = leaf->right;
    }
    return leaf;
}

Leaf min(Leaf x) {
    while (x->left) {
        x = x->left;
    }
    return x;
}

Leaf max(Leaf x) {
    while (x->right) {
        x = x->right;
    }
    return x;
}

void del(Leaf x) {
    if (x->left == 0)
        transpl(x, x->right);
    else if (x->right == 0)
        transpl(x, x->left);
    else {
        Leaf y = min(x->right);
        if (y->parent != x) {
            transpl(y, y->right);
            y->right = x->right;
            y->right->parent = y;
        }
        transpl(x, y);
        y->left = x->left;
        y->left->parent = y;
    }
    
    delete(x);
}

Leaf next(int x) {
    Leaf a = add(x);
    Leaf b = successor(a);
    del(a);
    return b;
}

Leaf prev(int x) {
    Leaf a = add(x);
    Leaf b = predeccessor(a);
    del(a);
    return b;
}

void transpl(Leaf u, Leaf v) {
    if (u->parent == 0)
        root = v;
    else if (u->parent->left == u)
        u->parent->left = v;
    else 
        u->parent->right = v;
    if (v) 
        v->parent = u->parent;
}

Leaf successor(Leaf x) {
    if (x->right)
        return min(x->right);

    Leaf y = x->parent;

    while (y && x == y->right) {
        x = y;
        y = y->parent;
    }

    return y;
}

Leaf predeccessor(Leaf x) {
    if (x->left)
        return max(x->left);
    Leaf y = x->parent;
    while (y && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}
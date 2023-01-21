#include <iostream>
using namespace std;

struct tnode {
    struct tnode* left;
    struct tnode* right;
    struct tnode* father;
    int data;
};
typedef struct tnode* TREE;

TREE getnode() {
    TREE node;
    node = (TREE)malloc(sizeof(struct tnode));
    return node;
}

TREE maketree(int x) {
    TREE t;
    t = getnode();
    t->left = NULL;
    t->right = NULL;
    t->father = NULL;
    t->data = x;
    return t;
}

void setLeft(TREE tree, int x) {
    if (tree->left != NULL)
        cout << "Left node is full\n";
    else
    {
        TREE p;
        p = maketree(x);
        p->father = tree;
        tree->left = p;
    }
}

void setRight(TREE tree, int x) {
    if (tree->right != NULL)
        cout << "Left node is full\n";
    else
    {
        TREE p;
        p = maketree(x);
        p->father = tree;
        tree->right = p;
    }
}

void set(TREE tree, int x) {
    TREE p, q;
    p = q = tree;
    while (x != p->data && q != NULL) {
        p = q;
        if (x < p->data) {
            q = p->left;
        }
        else {
            q = p->right;
        }
    }
    if (x == p->data)
        cout << "The input number already exists.\n";
    else if (x < p->data) {
        setLeft(p, x);
    }
    else {
        setRight(p, x);
    }
}// Binary Tree Set Function. Small number to the left, big number to the right

void ldr(TREE tree) {
    TREE q;
    q = tree;
    if (q != NULL) {
        ldr(q->left);
        cout << q->data << " ";
        ldr(q->right);
    }

}//Left - Data - Right scan

void lrd(TREE tree) {
    TREE q;
    q = tree;
    if (q != NULL) {
        lrd(q->left);
        lrd(q->right);
        cout << q->data << " ";
    }
}//Left - Right - Data scan

void dlr(TREE tree) {
    TREE q;
    q = tree;
    if (q != NULL) {
        cout << q->data << " ";
        dlr(q->left);
        dlr(q->right);
    }
}// Data - Left - Right scan

int main()
{
    TREE test = maketree(100);
    set(test, 50);
    set(test, 150);
    set(test, 75);
    set(test, 125);
    set(test, 175);
    set(test, 25);
    set(test, 10);
    set(test, 5);
    ldr(test);
    cout << "" << endl;
    lrd(test);
    cout << "" << endl;
    dlr(test);
}
/*
                            100
                     50            150
                  25     75     125   175
               10
             5

             LDR : 5 10 25 50 75 100 125 150 175 
             LRD : 5 10 25 75 50 125 175 150 100
             DLR : 100 50 25 10 5 75 150 125 175 
*/

#include <algorithm>
#include <iostream>
using namespace std;

class bstree {
  public:
    bstree(); /* κατασκευαστής: κατασκευάζει ένα κενό ΔΔΑ */
    int height(); /* επιστρέφει το ύψος του ΔΔΑ (το κενό ΔΔΑ έχει ύψος 0) */
    void insert(int x); /* εισάγει τον αριθμό x στο ΔΔΑ */
    int search(int x); /* ψάχνει τον αριθμό x στο ΔΔΑ και επιστρέφει το επίπεδο στο οποίο
   βρίσκεται (η ρίζα βρίσκεται στο επίπεδο 1) ή 0 αν δεν υπάρχει */
    int min();      /* επιστρέφει το ελάχιστο στοιχείο του ΔΔΑ */
    int max();      /* επιστρέφει το μέγιστο στοιχείο του ΔΔΑ */
    void inorder(); /* εκτυπώνει τα στοιχεία του ΔΔΑ με ενδοδιατεταγμένη διάσχιση */
    void preorder(); /* εκτυπώνει τα στοιχεία του ΔΔΑ με προδιατεταγμένη διάσχιση */
    void postorder(); /* εκτυπώνει τα στοιχεία του ΔΔΑ με μεταδιατεταγμένη διάσχιση */

  private:
    struct node {
        int info;
        node *left;
        node *right;
    };

    node *root;

    int height(node *t);
    node *insert(node *t, int x);
    int search(node *t, int x, int level);
    void inorder(node *t);
    void preorder(node *t);
    void postorder(node *t);
};

bstree::bstree() {
    root = nullptr;
}

int bstree::height(node *t) {
    if (t == nullptr) return 0;

    return 1 + std::max(height(t->left), height(t->right));
}

int bstree::height() {
    return height(root);
}

bstree::node *bstree::insert(node *t, int x) {
    if (t == nullptr) {
        node *p = new node;
        p->info = x;
        p->left = p->right = nullptr;
        p->left = p->right = nullptr;

        return p;
    }

    if (t->info > x)
        t->left = insert(t->left, x);
    else if (t->info < x)
        t->right = insert(t->right, x);

    return t;
}

void bstree::insert(int x) {
    root = insert(root, x);
}

int bstree::search(node *t, int x, int level) {
    if (t == nullptr) return 0;
    if (t->info == x) return level;

    if (x < t->info) return search(t->left, x, level + 1);
    return search(t->right, x, level + 1);
}

int bstree::search(int x) {
    return search(root, x, 1);
}

int bstree::min() {
    node *q = root;

    if (q == nullptr) return 0;

    while (q->left != nullptr) {
        q = q->left;
    }

    return q->info;
}

int bstree::max() {
    node *q = root;

    if (q == nullptr) return 0;

    while (q->right != nullptr) {
        q = q->right;
    }

    return q->info;
}

void bstree::inorder(node *t) {
    if (t == nullptr) return;

    inorder(t->left);
    cout << t->info << " ";
    inorder(t->right);
}

void bstree::preorder(node *t) {
    if (t == nullptr) return;

    cout << t->info << " ";
    preorder(t->left);
    preorder(t->right);
}

void bstree::postorder(node *t) {
    if (t == nullptr) return;

    postorder(t->left);
    postorder(t->right);
    cout << t->info << " ";
}

void bstree::inorder() {
    inorder(root);
}

void bstree::preorder() {
    preorder(root);
}

void bstree::postorder() {
    postorder(root);
}

int main() {
    int n, m, k, x;
    char ch;

    bstree bst;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;

        bst.insert(x);
    }

    cout << bst.height() << endl;
    cout << bst.min() << " " << bst.max() << endl;

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> x;

        if (i > 0) cout << " ";
        cout << bst.search(x);
    }
    cout << endl;

    bst.inorder();
    cout << "end" << endl;

    bst.preorder();
    cout << "end" << endl;

    bst.postorder();
    cout << "end" << endl;

    return EXIT_SUCCESS;
}

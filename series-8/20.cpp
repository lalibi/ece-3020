#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class list {
  public:
    list(); /* κατασκευαστής: κατασκευάζει μία κενή λίστα */
    bool empty();           /* ελέγχει αν η λίστα είναι κενή */
    int size();             /* επιστρέφει το μέγεθος της λίστας */
    void add(int k, int x); /* εισάγει το στοιχείο x στη θέση k της λίστας */
    int get(int k); /* επιστρέφει την τιμή του στοιχείου στη θέση k της λίστας */
    void remove(int k); /* διαγράφει το στοιχείο στη θέση k της λίστας */
    int searchMF(int x); /*  */

  private:
    struct node {
        int info;
        node *next;
    };

    int length;
    node *head;
};

list::list() {
    length = 0;
    head = nullptr;
}

bool list::empty() {
    return length == 0;
}

int list::size() {
    return length;
}

void list::add(int k, int x) {
    if (k < 1 || k > length + 1) exit(EXIT_FAILURE);

    node *p = new node;
    p->info = x;

    if (k == 1) {
        p->next = head;
        head = p;
    } else {
        node *q = head;
        for (int i = 1; i < k - 1; i++) {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }

    length += 1;
}

int list::get(int k) {
    if (k < 1 || k > length) exit(EXIT_FAILURE);

    node *q = head;
    for (int i = 1; i < k; i++) {
        q = q->next;
    }

    return q->info;
}

void list::remove(int k) {
    if (k < 1 || k > length) exit(EXIT_FAILURE);

    node *p;

    if (k == 1) {
        p = head;
        head = head->next;
    } else {
        node *q = head;
        for (int i = 1; i < k - 1; i++) {
            q = q->next;
        }

        p = q->next;
        q->next = p->next;
    }

    delete p;

    length -= 1;
}

int list::searchMF(int x) {
    node *q = head;

    int k = 1;
    while (q != nullptr && q->info != x) {
        q = q->next;
        k += 1;
    }

    if (q != nullptr) {
        remove(k);
        add(1, x);

        return k;
    }

    return 0;
}

int main() {
    int n, m, k, x;
    char ch;

    cin >> n;

    list l;

    for (int i = 0; i < n; i++) {
        cin >> k;
        cin >> x;

        l.add(k, x);
    }

    cin >> m;

    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> x;

        sum += l.searchMF(x);
    }

    cout << sum << endl;

    return EXIT_SUCCESS;
}

#include <iostream>
using namespace std;

class queue {
  public:
    queue(); /* κατασκευαστής: κατασκευάζει μία κενή ουρά */
    bool empty();        /* ελέγχει αν η ουρά είναι κενή */
    void enqueue(int x); /* εισάγει ένα στοιχείο στην ουρά */
    int dequeue(); /* αφαιρεί ένα στοιχείο από μια μη κενή ουρά */
    int peek(); /* επιστρέφει (χωρίς να αφαιρεί) το πρώτο στοιχείο μιας μη κενής ουράς */

  private:
    struct node {
        int info;
        node *next;
    };
    node *front, *rear;
};

queue::queue() {
    front = rear = nullptr;
}

bool queue::empty() {
    return front == nullptr;
}

void queue::enqueue(int x) {
    node *p = new node;
    p->info = x;
    p->next = nullptr;

    if (front == nullptr)
        front = p;
    else
        rear->next = p;

    rear = p;
}

int queue::dequeue() {
    node *p = front;

    int result = front->info;

    if (front == rear) rear = nullptr;
    front = front->next;

    delete p;

    return result;
}

int queue::peek() {
    return front->info;
}

int main() {
    int x;
    char ch;

    queue q;

    do {
        cin >> x;

        if (cin.fail()) exit(EXIT_FAILURE);
        if (x == 0) exit(EXIT_FAILURE);

        q.enqueue(x);

        cin.get(ch);
    } while (ch != '\n');

    int cp = 0, cn = 0;
    int pp = 0, pn = 0;
    bool pasc = true, pdesc = true;
    bool nasc = true, ndesc = true;

    while (!q.empty()) {
        x = q.dequeue();

        if (x > 0) {
            cp += 1;

            if (pp != 0) {
                if (x > pp)
                    pdesc = false;
                else
                    pasc = false;
            }

            pp = x;
        } else if (x < 0) {
            cn += 1;

            if (pn != 0) {
                if (abs(x) > abs(pn))
                    ndesc = false;
                else
                    nasc = false;
            }

            pn = x;
        } else {
            exit(EXIT_FAILURE);
        }
    }

    if (cp == cn && ((pasc && nasc) || (pdesc && ndesc))) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

class queue {
  public:
    queue();             /* κατασκευαστής: κατασκευάζει μία κενή ουρά */
    bool empty();        /* ελέγχει αν η ουρά είναι κενή */
    void enqueue(int x); /* εισάγει ένα στοιχείο στην ουρά */
    int dequeue();       /* αφαιρεί ένα στοιχείο από μια μη κενή ουρά */
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

    if (front == nullptr) front = p;
    else rear->next = p;

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
    bool f = true;

    queue qp, qn;

    while (scanf("%d", &x) == 1) {
        if (x > 0) {
            if (qn.empty()) {
                qp.enqueue(x);
            } else if (x == abs(qn.peek())) {
                qn.dequeue();
            } else {
                f = false;
                break;
            }
        } else if (x < 0) {
            if (qp.empty()) {
                qn.enqueue(x);
            } else if (abs(x) == qp.peek()) {
                qp.dequeue();
            } else {
                f = false;
                break;
            }
        } else {
            exit(EXIT_FAILURE);
        }
    }

    if (f && qp.empty() && qn.empty()) {
        // cout << "yes" << endl;
        printf("yes\n");
    } else {
        // cout << "no" << endl;
        printf("no\n");
    }

    return EXIT_SUCCESS;
}

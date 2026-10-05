#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Problem 2
void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << ' ';
        current = current->next;
    }
}

// Problem 3
Node* createList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 1; i <= n; i++) {
        Node* newNode = new Node(i);
        if (head == nullptr) {
            head = tail = newNode;
        }else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;

}

// Problem 4
Node* insertFront(Node* head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
    return head;
}

Node* insertMiddle(Node* head, int value) {
    Node* current = head;
    for (int i = 1; i < 50; i++) {
        current = current->next;
    }
    Node* newNode = new Node{value, current->next};
    current->next = newNode;
    return head;
}

Node* insertBack(Node* head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Problem 5
Node* deleteFront(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* current = head;
    for (int i = 1; i < 49; i++) {
        current = current->next;
    }
    Node* temp = current->next;
    if (temp != nullptr) {
        current->next = temp->next;
        delete temp;
    }
    return head;
}

Node* deleteBack(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    return head;
}

// Problem 6
int sumList(Node* head) {
    int sum = 0;
    Node* current = head;
    while (current != nullptr) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}



int main() {
    //  Problem 1 and 2

    // Node* n1 = new Node(10, nullptr);
    // Node* n2 = new Node(20, nullptr);
    // Node* n3 = new Node(30, nullptr);
    // Node* n4 = new Node(40, nullptr);
    // Node* n5 = new Node(50, nullptr);

    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;

    // cout << n1->data << endl;
    // cout << n2->data << endl;
    // cout << n1->next->data << endl;

    // cout << n3->data << endl;
    // cout << n1->next->next->data << endl;
    // cout << n2 ->next->data << endl;

    // cout << n1->next->next->next->data << endl;
    // cout << n4->data << endl;

    // cout << n1->next->next->next->next->data << endl;

    // printList(n1);

    // delete n1;
    // delete n2;
    // delete n3;
    // delete n4;
    // delete n5;

    //  Problem 3
    // Node* head = createList(100);
    // printList(head);
    //
    // //deletion
    // while (head != nullptr) {
    //     Node* temp = head;
    //     head = head->next;
    //     delete temp;
    // }


    //  Problem 4
    Node* head = createList(100);

    head = insertFront(head, 0);
    head = insertMiddle(head, 500);
    head = insertBack(head, 101);

    printList(head);

    cout << endl;


    //  Problem 5
    head = deleteFront(head);
    head = deleteBack(head);
    head = deleteMiddle(head);

    printList(head);

    cout << endl;

    //  Problem 6
    Node* sumHead = nullptr;
    Node* sumTail = nullptr;
    cout << "How many elements should sum be calculated: ";
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {

        Node* newNode = new Node{i, nullptr};

        if (sumHead == nullptr) {
            sumHead = newNode;
            sumTail = newNode;
        }
        else {
            sumTail->next = newNode;
            sumTail = newNode;
        }
    }

    cout << "List: ";
    printList(sumHead);

    cout << "\nSum: " << sumList(sumHead) << endl;

    delete sumHead;
    delete sumTail;

    return 0;
}
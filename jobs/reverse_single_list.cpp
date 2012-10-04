#include <iostream>
using namespace std;

struct NODE{
    int data;
    NODE * next;
};


NODE* createList(int len) {
    NODE *head = NULL;
    NODE *tail = NULL;
    for (int i = 0; i < len; i++) {
        NODE *newNode = new NODE;
        newNode->data = i;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = NULL;
    return head;
}

NODE* reverseList(NODE *head) {
    if (head == NULL || head->next == NULL)
        return head;
    NODE *newHead = NULL;
    NODE *temp = NULL;
    while(head != NULL) {
        temp = head;
        head = head->next;
        temp->next = newHead;
        newHead = temp;
    }
    return newHead;
}

void print(NODE *head) {
    while (head) {
        cout << head->data << endl;
        head = head->next;
    }
}


int main() {
    NODE *head = createList(10);
    print(head);
    head = reverseList(head);
    print(head);
    return 0;
}


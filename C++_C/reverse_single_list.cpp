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
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}


NODE* createList1(int len) 
{
    NODE *head = NULL;
    NODE *tail = NULL;
    NODE *tmp = NULL;
    int i = 0;
    if (len > 1)
    {
        head = new NODE;
        head->next = NULL;
        head->data = 0;
        tail = head;
        for (i = 1; i < len; i++)
        {
            tmp = new NODE;
            tmp->data = i;
            tmp->next = NULL;
            tail->next = tmp;
            tail = tail->next;
        }
    }
    return head;
}


NODE* reverseList(NODE *head) {
    if (head == NULL || head->next == NULL)
        return head;
    NODE *newHead = NULL;
    NODE *tmp = NULL;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        tmp->next = newHead;
        newHead = tmp;
    }
    return newHead;
}

void print(NODE *head) {
    cout << "the list is:" << endl;
    while (head) {
        cout << head->data << endl;
        head = head->next;
    }
}


int main() {
    //NODE *head = createList(10);
    NODE *head = createList1(10);
    print(head);
    head = reverseList(head);
    print(head);
    return 0;
}


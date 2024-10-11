#include "dlist.h"

int sumLarger(node* head) {
    if (head == nullptr) {
        return 0;
    }

    int sum = 0;

    for (node* current = head; current != nullptr; current = current->next) {
        if (current->data > head->data) {
            sum += current->data;
        }
    }

    return sum + sumLarger(head->next);
}

int copyLarger(node* head, node*& newHead) {
    if (head == nullptr) {
        newHead = nullptr;
        return 0;
    }

    int total = 0;

    if (head->data > head->previous->data) {
        node* newNode = new node;
        newNode->data = head->data;
        newNode->previous = nullptr;
        newNode->next = nullptr;

        if (newHead == nullptr) {
            newHead = newNode;
        }

        if (newNode->previous != nullptr) {
            newNode->previous->next = newNode;
        }
        newNode->next = nullptr;
        newNode->previous = nullptr;

        total = 1 + copyLarger(head->next, newNode->next);
    }
    else {
        total = copyLarger(head->next, newHead);
    }

    return total;
}


// Linked List

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

class Node {
public:
    int value = 0;
    Node *next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node *head = nullptr;

    void add(int value) {
        Node *newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void remove(int value) {
        if (head == nullptr) {
            return;
        }
        if (head->value == value) {
            head = head->next;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr) {
            if (temp->next->value == value) {
                temp->next = temp->next->next;
                return;
            }
            temp = temp->next;
        }
    }

    void print() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

#endif
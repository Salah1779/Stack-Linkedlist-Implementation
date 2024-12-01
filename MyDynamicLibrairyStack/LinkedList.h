#pragma once

#include <iostream>
#include "Node.h"
using namespace std;

template <class MyType>
class LinkedList {
private:
    Node<MyType>* head;

public:
    LinkedList();
    void append(MyType val);
    void clear();
    ~LinkedList();
    void insertHead(MyType val);
    void deleteHead(MyType* deleted);
    bool isEmpty() const;
    void insertAt(int position, MyType val);
    bool deleteValue(MyType val);
    bool deleteAt(int position, MyType* deleted);
    void display() const;
};

template <class MyType>
inline LinkedList<MyType>::LinkedList() {
    head = nullptr;
}

// Append a value to the list
template <class MyType>
inline void LinkedList<MyType>::append(MyType val) {
    Node<MyType>* newNode = new Node<int>(val);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node<MyType>* temp = head;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
}

// Clear the entire list
template <class MyType>
inline void LinkedList<MyType>::clear() {
    Node<MyType>* current = head;
    while (current != nullptr) {
        Node<MyType>* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

// Destructor
template <class MyType>
inline LinkedList<MyType>::~LinkedList() {
    clear();
}

// Insert at the head
template <class MyType>
inline void LinkedList<MyType>::insertHead(MyType e) {
    Node<MyType>* newNode = new Node<int>(e);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        newNode->setNext(head);
        head = newNode;
    }
}

// Delete the head
template <class MyType>
inline void LinkedList<MyType>::deleteHead(MyType* deleted) {
    if (isEmpty()) {
        throw std::underflow_error("List is empty");
    }
    Node<MyType>* tmp = head;
    *deleted = tmp->getVal();
    head = tmp->getNext();
    delete tmp;
}

// Check if the list is empty
template <class MyType>
inline bool LinkedList<MyType>::isEmpty() const {
    return head == nullptr;
}

// Insert at a given position
template <class MyType>
inline void LinkedList<MyType>::insertAt(int position, MyType val) {
    if (position < 0) {
        throw std::invalid_argument("Position must be non-negative");
    }

    Node<MyType>* newNode = new Node<int>(val);
    if (position == 0) {
        newNode->setNext(head);
        head = newNode;
        return;
    }

    Node<MyType>* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; ++i) {
        current = current->getNext();
    }

    if (current == nullptr) {
        throw std::out_of_range("Position is out of bounds");
    }

    newNode->setNext(current->getNext());
    current->setNext(newNode);
}

// Delete the first occurrence of a value
template <class MyType>
inline bool LinkedList<MyType>::deleteValue(MyType val) {
    if (isEmpty()) {
        return false; // List is empty
    }

    if (head->getVal() == val) {
        Node<MyType>* temp = head;
        head = head->getNext();
        delete temp;
        return true;
    }

    Node<MyType>* current = head;
    while (current->getNext() != nullptr && current->getNext()->getVal() != val) {
        current = current->getNext();
    }

    if (current->getNext() == nullptr) {
        return false; // Value not found
    }

    Node<MyType>* temp = current->getNext();
    current->setNext(temp->getNext());
    delete temp;
    return true;
}

// Delete an element at a specific position
template <class MyType>
inline bool LinkedList<MyType>::deleteAt(int position, MyType* deleted) {
    if (position < 0 || isEmpty()) {
        return false;
    }

    if (position == 0) {
        deleteHead(deleted);
        return true;
    }

    Node<MyType>* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; ++i) {
        current = current->getNext();
    }

    if (current == nullptr || current->getNext() == nullptr) {
        return false; // Position out of range
    }

    Node<MyType>* temp = current->getNext();
    *deleted = temp->getVal();
    current->setNext(temp->getNext());
    delete temp;
    return true;
}

template <class MyType>
void LinkedList<MyType>::display() const {
    if (isEmpty()) {
        cout << "The list is empty." << endl;
        return;
    }

    Node<MyType>* current = head;
    cout << "LinkedList: ";
    while (current != nullptr) {
        current->display(); cout << "->";
        current = current->getNext();
    }
    cout << "NULL\n" << endl;
}

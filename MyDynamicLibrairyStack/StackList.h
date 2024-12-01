#pragma once
#include "Node.h"
#include <iostream>
#include <vector>

template <class MyType>
class StackList {
private:
    Node<MyType>* head;

public:
    StackList() : head(nullptr) {}
    ~StackList();

    bool isEmpty() const;
    void Pop(MyType* deleted);
    void Push(MyType value);
    void Push(vector<MyType> values);
    void display();
    void clear();
};

// Check if the stack is empty
template <class MyType>
inline bool StackList<MyType>::isEmpty() const {
    return head == nullptr;
}

// Pop an element from the stack
template <class MyType>
inline void StackList<MyType>::Pop(MyType* deleted) {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    Node<MyType>* tmp = head;
    *deleted = tmp->getVal(); 
    head = tmp->getNext();
    delete tmp;
}

template<class MyType>
inline void StackList<MyType>::Push(vector<MyType> values)
{
	for (int i = 0; i < values.size(); i++)
	{
		Push(values[i]);
	}
}

// Push an element onto the stack
template <class MyType>
inline void StackList<MyType>::Push(MyType value) {
    Node<MyType>* newNode = new Node<MyType>(value);
    newNode->setNext(head);
    head = newNode;
}

// Display the stack elements while respecting the stack principle
template <class MyType>
inline void StackList<MyType>::display() {
    if (isEmpty()) {
        std::cout << "The stack is empty." << std::endl;
        return;
    }

    StackList<MyType> tempStack; // Temporary stack to hold elements
    MyType value;

    // Display the elements and transefer them from the original stack to the temporary stack
    std::cout << "Stack (top to bottom): ";
    while (!isEmpty()) {
        Pop(&value);
        std::cout << value << " ";
        tempStack.Push(value);
    }



    //Restore the elements back to the original stack
    while (!tempStack.isEmpty()) {
        tempStack.Pop(&value);
        Push(value);               
    }

    std::cout << std::endl;
}

template<class MyType>
inline void StackList<MyType>::clear()
{
	while (!isEmpty()) {
        MyType temp;
		Pop(&temp);
	}
    
}


// Destructor to free allocated memory
template <class MyType>
StackList<MyType>::~StackList() {
    clear();   
}

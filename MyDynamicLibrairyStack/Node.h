#pragma once
#include <iostream>

template <class MyType>
class Node {
private:
    MyType elem;   
    Node<MyType>* next;     
public:
    Node(MyType val); 
    void display() const; 
    MyType getVal() const;
	Node<MyType>* getNext() const;
	void setNext(Node* next);   
};

// Constructor
template <class MyType>
inline Node<MyType>::Node(MyType val) : elem(val), next(nullptr) {}

// Display method
template <class MyType>
inline void Node<MyType>::display() const {
    std::cout << elem;
}

template<class MyType>
inline MyType Node<MyType>::getVal() const
{
    return elem;
}

template<class MyType>
inline Node<MyType>* Node<MyType>::getNext() const
{
    return next;
}

template<class MyType>
inline void Node<MyType>::setNext(Node* n)
{
    next = n;
}

// Stacktest2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <pch.h>


int main() {

    /// General Stack implemented with linked list
    try {
        StackList<int> stack; // Create a stack of integers

        // Create a vector of integers to push onto the stack
        std::vector<int> values = { 10, 20, 30, 40, 50 };

        // Push the vector of values onto the stack
        stack.Push(values);

        // Display the stack elements
        std::cout << "Initial stack contents: ";
        stack.display();

        // Pop an element from the stack
        int poppedValue;
        stack.Pop(&poppedValue);
        std::cout << "Popped value: " << poppedValue << std::endl;

        // Display the stack again after popping
        std::cout << "Stack after popping one element: ";
        stack.display();

        // Clear the stack
        stack.clear();
        std::cout << "Stack after clearing: ";
        stack.display();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    cout << "\n\n********************************************************************\n" << endl;


// Create a linked list of integers
LinkedList<int> list;

// Display the empty list
std::cout << "Initial list: ";
list.display();

// Test append
std::cout << "Appending values 10, 20, 30 to the list." << std::endl;
list.append(10);
list.append(20);
list.append(30);
list.display();

// Test insertHead
std::cout << "Inserting 5 at the head." << std::endl;
list.insertHead(5);
list.display();

// Test insertAt
std::cout << "Inserting 15 at position 2." << std::endl;
list.insertAt(2, 15);
list.display();

// Test deleteHead
std::cout << "Deleting the head of the list." << std::endl;
int deletedValue;
list.deleteHead(&deletedValue);
std::cout << "Deleted value: " << deletedValue << std::endl;
list.display();

// Test deleteValue
std::cout << "Deleting value 20 from the list." << std::endl;
if (list.deleteValue(20)) {
    std::cout << "Value 20 deleted successfully." << std::endl;
}
else {
    std::cout << "Value 20 not found in the list." << std::endl;
}
list.display();

// Test deleteAt
std::cout << "Deleting the element at position 1." << std::endl;
if (list.deleteAt(1, &deletedValue)) {
    std::cout << "Deleted value at position 1: " << deletedValue << std::endl;
}
else {
    std::cout << "Failed to delete at position 1." << std::endl;
}
list.display();

// Test isEmpty
std::cout << "Checking if the list is empty." << std::endl;
if (list.isEmpty()) {
    std::cout << "The list is empty." << std::endl;
}
else {
    std::cout << "The list is not empty." << std::endl;
}

// Test clear
std::cout << "Clearing the list." << std::endl;
list.clear();
std::cout << "List after clearing: ";
list.display();




    return 0;
}






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

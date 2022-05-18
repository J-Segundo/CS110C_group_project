#ifndef LLIST_H
#define LLIST_H

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "list.h"
#include "link.h"
#include <iostream>
#include "utilities.h"

// Linked list implementation
template <typename E> class LList: public List<E> {
private:
    Link<E>* head; // Pointer to list header
    Link<E>* tail; // Pointer to last element
    Link<E>* curr; // Access to current element
    int cnt; // Size of list
    void init() { // private initialization helper method
        curr = tail = head = new Link<E>; // At first all 3 point to an empty single node
        cnt = 0;
    }
    void removeall() { // private helper method. Return link nodes to free store or to FreelistSL
        while(head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
public:
    LList(int size = 10) {
        init(); // Size here is just a place holder varible just to complay with the ADT.
    }
    ~LList() { // Be very careful when you copy from pdf the tilde will not get copied properly so be sure to replace with actual
        removeall(); // Destructor
    }
    void clear() {
        removeall();
        init(); // Clear list
    }
    // Insert "it" at current position
    void insert(const E& it) {
        // std::cout << "Its in" << std::endl;

        curr->next = new Link<E>(it, curr->next); // if FreelistSL, then this new operator is overloaded
        if (tail == curr) tail = curr->next; // New tail
        cnt++;
    }
    void append(const E& it) { // Append "it" to list
        tail = tail->next = new Link<E>(it, NULL);
        cnt++;
    }
    // Remove and return current element
    E remove() {
        Assert(curr->next != NULL, "No element");
        E it = curr->next->element; // Remember value
        Link<E>* ltemp = curr->next; // Remember link node
        if (tail == curr->next) tail = curr; // Reset tail
        curr->next = curr->next->next; // Remove from list
        delete ltemp; // Reclaim space
        cnt--; // Decrements the count
        return it;
    }
    // Place curr at list start
    void moveToStart() {
        curr = head;
    }
    // Place curr at list end
    void moveToEnd(){
        curr = tail;
    }
    // Move curr one step left; no change if already at front
    void prev() {
        if (curr == head) return; // No previous element
        Link<E>* temp = head;
        // March down list until we find the previous element
        while (temp->next!=curr) temp=temp->next;
        curr = temp;
    }
    // Move curr one step right; no change if already at end
    void next(){
        if (curr != tail) curr = curr->next;
    }
    int length() const {
        return cnt; } // Return length
    // Return the position of the current element
    int currPos() const {
        Link<E>* temp = head; // We start from head
        int i;
        for (i=0; curr != temp; i++)
            temp = temp->next; // Traversing the list till we find curr
        return i;
    }
    // Move down list to "pos" position
    void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
    }
    const E& getValue() const { // Return current element
        Assert(curr->next != NULL, "No value");
        return curr->next->element;
    }
    bool isAtEnd() { return curr == tail; }
};

#endif // LLIST_H

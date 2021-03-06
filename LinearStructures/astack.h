#ifndef ASTACK_H
#define ASTACK_H

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "stack.h"
#include "utilities.h"

// Array-based stack implementation
template <typename E> class AStack: public Stack<E> {
private:
  int maxSize; // Maximum size of stack
  int top; // Index for top element
  E *listArray; // Array holding stack elements
public:
  AStack(int size = 10) {
    maxSize = size;
    top = 0;
    listArray = new E[size];
  }
  ~AStack() {// Destructor
    delete [] listArray;
  }
  void clear() {
    top = 0; // Reinitialize
  }
  void push(const E& it) { // Put "it" on stack
    Assert(top != maxSize, "Stack is full");
    listArray[top++] = it;
  }
  E pop() { // Pop top element
    Assert(top != 0, "Stack is empty");
    return listArray[--top];
  }
  const E& topValue() const { // Return top element
    Assert(top != 0, "Stack is empty");
    return listArray[top-1];
  }
  int length() const {
    return top;
  } // Return length
};


#endif // ASTACK_H

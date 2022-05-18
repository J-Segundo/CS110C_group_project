#include "link.h"
#include "dlink.h"
#include "alist.h"
#include "llist.h"
#include "dllist.h"
#include "astack.h"
#include "lstack.h"
#include "aqueue.h"
#include "lqueue.h"

#include <iostream>

int main(int argc, char *argv[])
{
    // Start of code relevant to slides 2-10 of Linear_structures slides
    std::cout << "Start testing concepts covered in slides 2-10" <<  std::endl;
    AList<int> int_array_list(20); // Creation
    for (int i = 0; i < 10; i++) // Filling up by appending
    {
        int_array_list.append(i);// Try this with i > 20 and see that at i = 21 (> maxSize) you will see the assertion failing with the message "Assertion Failed: List capacity exceeded"
    }
    int_array_list.moveToStart(); // Curr was at the end
    std::cout << "Testing: int_array_list.getValue() to print: ";
    for (int i = 0; i < int_array_list.length(); i++) // Verfication: append works as expected
    {
        int_array_list.moveToPos(i);
        std::cout << int_array_list.getValue() << ", ";
    }
    std::cout << std::endl;
    std::cout << "Testing: int_array_list.remove() to remove 5th: ";
    int_array_list.moveToPos(5);
    int_array_list.remove(); // Remove 5th element
    for (int i = 0; i < int_array_list.length(); i++) // Verfication: remove works as expected
    {
        int_array_list.moveToPos(i);
        std::cout << int_array_list.getValue() << ", ";
    }
    std::cout << std::endl;
    std::cout << "Testing: int_array_list.insert() to insert 30 at 5th: ";
    int_array_list.moveToPos(5); // Change the current to 5
    int_array_list.insert(30); // Insert 30 at 5
    for (int i = 0; i < int_array_list.length(); i++) // Verfication: Insert works as expected
    {
        int_array_list.moveToPos(i);
        std::cout << int_array_list.getValue() << ", ";
    }
    std::cout << std::endl;
    std::cout << "End testing concepts covered in slides 2-10" <<  std::endl<< std::endl;
    // End of code relevant to slides 2-10 of Linear_structures slides

    // Start of code relevant to slides 11-12 of Linear_structures slides
    std::cout << "Start testing concepts covered in slides 11-12" <<  std::endl;
    LList<int> int_linked_list;   // Creation
    for (int i = 0; i < 10; i++) // Filling up by appending
    {
        int_linked_list.append(i);
    }
    int_linked_list.moveToStart(); // Curr was at the end
    std::cout << "Testing: int_linked_list.getValue() to print: ";
    for (int i = 0; i < int_linked_list.length(); i++) // Verfication: append works as expected
    {
        int_linked_list.moveToPos(i);
        std::cout << int_linked_list.getValue() << ", ";
    }
    std::cout << std::endl;
    std::cout << "Testing: int_linked_list.remove() to remove 5th: ";
    int_linked_list.moveToPos(5);
    int_linked_list.remove(); // Remove 5th element
    for (int i = 0; i < int_linked_list.length(); i++) // Verfication: remove works as expected
    {
        int_linked_list.moveToPos(i);
        std::cout << int_linked_list.getValue() << ", ";
    }
    std::cout << std::endl;
    std::cout << "Testing: int_linked_list.insert() to insert 30 at 5th: ";
    int_linked_list.moveToPos(5); // Change the current to 5
    int_linked_list.insert(30); // Insert 30 at 5
    for (int i = 0; i < int_linked_list.length(); i++) // Verfication: Insert works as expected
    {
        int_linked_list.moveToPos(i);
        std::cout << int_linked_list.getValue() << ", ";
    }
    std::cout << std::endl;
    std::cout << "End testing concepts covered in slides 11-12" <<  std::endl<< std::endl;
    // End of code relevant to slides 11-12 of Linear_structures slides

    // Start of code relevant to slides 13 of Linear_structures slides
    std::cout << "Start testing concepts covered in slides 13" <<  std::endl;
    DLList<int> int_doubly_linked_list;
    for (int i = 0; i < 10; i++) // Filling up by appending
    {
        int_doubly_linked_list.append(i);
    }
    int_doubly_linked_list.moveToStart(); // Curr was at the end
    std::cout << "Testing: int_doubly_linked_list.getValue() to print: ";
    for (int i = 0; i < int_doubly_linked_list.length(); i++) // Verfication: append works as expected
    {
        int_doubly_linked_list.moveToPos(i);
        std::cout << int_doubly_linked_list.getValue() << ", ";
    }
    std::cout << std::endl;
    std::cout << "Testing: int_doubly_linked_list.remove() to remove 5th: ";
    int_doubly_linked_list.moveToPos(5);
    int_doubly_linked_list.remove(); // Remove 5th element
    for (int i = 0; i < int_doubly_linked_list.length(); i++) // Verfication: remove works as expected
    {
        int_doubly_linked_list.moveToPos(i);
        std::cout << int_doubly_linked_list.getValue() << ", ";
    }
    std::cout << std::endl;
    std::cout << "Testing: int_doubly_linked_list.insert() to insert 30 at 5th: ";
    int_doubly_linked_list.moveToPos(5); // Change the current to 5
    int_doubly_linked_list.insert(30); // Insert 30 at 5
    for (int i = 0; i < int_doubly_linked_list.length(); i++) // Verfication: Insert works as expected
    {
        int_doubly_linked_list.moveToPos(i);
        std::cout << int_doubly_linked_list.getValue() << ", ";
    }
    std::cout << std::endl;

    // Start of code relevant to slides 13 of Linear_structures slides
    std::cout << "Start testing concepts covered in slides 13" <<  std::endl;
    LStack <char> str1;
    std::string input_string = "programming";
    for (int i = 0; i < input_string.length(); i++){
        str1.push(input_string.at(i));
    }
    std::string reversed_string = "";

    for (int i = 0; i < input_string.length(); i++){
        reversed_string += str1.pop(); // Building the reversed string as we pop
    }
    std::cout << "Reversed string for the string " <<input_string << " is " << reversed_string << std::endl; // print reversed
    std::cout << std::endl;

    std::cout << "\n\nStarting queue demo ...." << "\n \n";

    // Queue demo
    LQueue <int> int_stack;
    for (int i = 0; i < 10; i++){
        int_stack.enqueue(i*i); // Insert
    }

    for (int i = 0; i < 10; i++){
        std::cout << "Removed " << i << " th " << " value is " << int_stack.dequeue() << std::endl; // Dequeue operation
    }


    std::cout << "All is good" << "\n";

}

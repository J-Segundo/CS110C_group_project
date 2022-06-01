//  Group Project CS110C
//  Created by Juan Segundo on 4/28/22.
//

/*

 The objective of this project is to represent a series of numeric type (both integer and double) data (a "data object" from now on) that offers access to few statistics (mentioned below) according to properties below:

 1.  Typical data object has a lot of duplicate entries
 2.  There is no limit to the number of unique data elements inside
 3.  data object supports simple statistics such as mean, standard deviation, min and
 4.  fastest possible access to above statistics is paramount; Big-Theta(1) access
 5.  Above statistics also represent a part of the state of the data object
 6.  Both fast access and saving space is paramount; developer must strive to use the smallest space possible for storage and must give Big-Theta(1) access to above statistics when demanded
 7.  In addition to above mentioned states, your data structure must support below operations:

        A. Update operations: not frequent compared to  frequent demands of statistics. Therefore, okey if they are expensive operations like O(n):
                i.   append: append new data. Update exist number of duplication or append from the end if new
                ii.  removem: remove m number of a given data element only if m is less than or equal to current amount of   repetitions, n
                iii. empty: delete all data
                iv.  feed: append from from any standard C++ container (any that supports iteration) data type (std::array, std::vector, std::set, etc)).   This may be bit hard. Search about this and really have a meaningful discussion within the team.  Only one feed method is allowed: this means no overloaded feed methods
        B. search (fastest possible among the choices what we have  discussed in the class): must return the location of the first occurrence and repetition. For example, if the first occurrence of the search data value, 20 is 3  and there are 10 of 20s, then you must return 3 and 10 as the search result of 20
        C. array index operator, []: access each unique element through an index: overload the array index operator ([]) so that the ith data element in an instance of your data object, db can be accessed like db[i]
        D. length_unique: number of unique elements in your data object
        E. length_total: total number of elements in your data object
        F. unique_set: return all the unique elements as an std::set
        G. getters (all must be) and in floating point type:
                i.   get_ mean: returns the mean value of the current entire data set
                ii.  get_SD: returns the standard deviation  of the current entire data set
                iii. get_min: returns the minimum data item in the current entire data set
                iv.  get_max: returns the maximum data item in the current entire data set

 Below are requirements and restrictions:

 1.  The principle data structure must be the most qualified linear structure we discussed so far in the class. So in the implementation you must use the code provided in Canvas
 2.  Updates (append, feed, removem) to the data object is possible though rare. However, the demands for above statistics is very frequent (You now understand why we need Big-Theta(1))
 3.  Though you must try to save space, your most important task is to give access to above statistics; we are sacrificing the space for speed. In regard of this you are allowed to use other data structures and algorithms provided in the standard C++. You are not allowed to use any third party or external libraries (like boost)
 4.  Calculation of above statistics must be private internal operations. This means you have to calculate and update them as you create, insert, append, removem, and feed operations
 5.  Creation: only two constructors:

        A. default: just empty data object
        B. create by adding data items from any standard C++ container (any that supports iteration) data type (std::array, std::vector, std::set, etc)). This may be bit hard. Search about this and really have a meaningful discussion within the team

 6.  Removem: remove 1 to any (m) number of data item from the data object. You must validate the existence of m number of data item before the removal
 7.  The data is heavily duplicated. In situations like this we discussed storing pointers as a solution in the class
 8.  You are not allowed to use any C/C++ math libraries
 9.  Write your entire solutions with the class name "Simple_stat" in a single header named "simple_stat.h" file and test it in a separate main program

 10. In the same project since you will be using linear structures headers linked here, make sure those headers contain the copyright note, "

 // From the software distribution accompanying the textbook

 // "A Practical Introduction to Data Structures and Algorithm Analysis,

 // Third Edition (C++)" by Clifford A. Shaffer.

 // Source code Copyright (C) 2007-2011 by Clifford A. Shaffer."
 This is very important as your project in GitHub is open source.
 I updated code zip file I posted with this note. So if you download
 the latest linked here you are good to go.


 */

#include <iostream>
#include <vector>
#include <set>
#include "simple_stat.h"

int main(int argc, char *argv[])
{
  Simple_stat <int, 10> test;

  // Testing appending and statistics operations
  test.append(6);
  test.append(2);
  test.append(2);
  test.append(3);
  test.append(3);
  test.append(4);
  test.append(2);
  test.append(10);
  test.printAll();
  test.print_unique();
  test.print_num_repetitions();
  test.print_all_stats();

  std::cout << "\nTesting feed:\n";
  // Testing the feed method and constructor
  std::vector <float> v = {3, 4, 3, 5, 6, 9, 10, 4, 3, 3, 8};
  Simple_stat <float, 15, std::vector<float>> test2;
  test2.feed(v);

  test2.printAll();
  test2.print_all_stats();
  std::set<float> set = test2.unique_set();

}


//  get_mean: returns the mean value of the current entire data set
//  get_SD: returns the standard deviation  of the current entire data set
//  get_min: returns the minimum data item in the current entire data set
//  get_max: returns the maximum data item in the current entire data set

    


# CS110C_group_project
CS110C group project

To test and run:

    g++ main.cpp main
    ./main

In this group project you will utilize a suitable linear data structure you  learned in linear structures lesson to create a specialized data structure dedicated to represent highly duplicated numeric data with very frequent demand for simple statistics (mentioned in the problem statement) as a C++ class template. Your specialized data structure will offer

time access to those simple statistics. Updates to this data structure is very rare. So it is ok, if they may be expensive operations like O(n).

Due to the limited time we have in the class, I may be able to give few day after the last day if any group need more time.
General instructions:

    Problem statement is located below
    Pick a group leader and mention his name to your instructor 
    Create a github project and on board all the members
    Create a good communication channel (could be through you Canvas group itself or your choice of third party like Slack, etc.
    Create a checklist of to do items and follow UMPIRE process to plan your solution
    Sit down as a group and discuss strategies and architecture the project
    Draw your UML diagram, both your Simple_stat class UML and entire class interaction UML. We didn't cover UML as a lesson. But it is very easy to learn. I can give you more guidance. 
    Once you have a rough idea what to do, please setup a group meeting with me through office hour so that I can give further guidance.

Learning objectives:

    Study and apply linear structures learned in the class
    Study and apply C++ standard containers
    Study and apply C++ templates
    Custom design of data structures
    Draw UML class and class interaction diagrams
    Learn simple statistics operations 
    Learn Git and GitHub operations

Problem statement:

The objective of this project is to represent a series of numeric type (both integer and double) data (is called "data object" from now on) that offers

access to few statistics (mentioned below)  according to below properties:

    typical data object has a lot of duplicate entries 
    there is no limit to the number of unique data elements inside
    data object supports simple statistics such as meanLinks to an external site.,  standard deviationLinks to an external site., min and max
    fastest possible access to above statistics is paramount; 

access 
so above statistics also represent a part of the state of the data object
both fast access and saving space is paramount; developer must strive to use the smallest space possible for storage and must give
access to above statistics when demanded
In addition to above mentioned states, your data structure must support below operations:

    Update operations: not frequent compared to  frequent demands of statistics. Therefore, okey if they are expensive operations like O(n):
        append: append new data. Update exist number of duplication or append from the end if new
        removem: remove m number of a given data element only if m is less than or equal to current amount of repetitions, n
        empty: delete all data
        feed: append from from any standard C++ container (any that supports iteration) data type (std::array, std::vector, std::set, etc)). This may be bit hard. Search about this and really have a meaningful discussion within the team.  Only one feed method is allowed: this means no overloaded feed methods
    search (fastest possible among the choices what we have  discussed in the class): must return the location of the first occurrence and repetition. For example, if the first occurrence of the search data value, 20 is 3  and there are 10 of 20s, then you must return 3 and 10 as the search result of 20
    array index operator, []: access each unique element through an index: overload the array index operator ([]) so that the ith data element in an instance of your data object, db can be accessed like db[i]
    length_unique: number of unique elements in your data object
    length_total: total number of elements in your data object
    unique_set: return all the unique elements as an std::set
    getters (all must be 

        ) and in floating point type:
            get_ mean: returns the mean value of the current entire data set 
            get_SD: returns the standard deviation  of the current entire data set
            get_min: returns the minimum data item in the current entire data set
            get_max: returns the maximum data item in the current entire data set 

Below are requirements and restrictions:

    The principle data structure must be the most qualified linear structure we discussed so far in the class. So in the implementation you must use the code provided in Canvas
    Updates (append, feed, removem) to the data object is possible though rare. However, the demands for above statistics is very frequent (You now understand why we need 

)
Though you must try to save space, your most important task is to give

    access to above statistics; we are sacrificing the space for speed. In regard of this you are allowed to use other data structures and algorithms provided in the standard C++. You are not allowed to use any third party or external libraries (like boost)
    Calculation of above statistics must be private internal operations. This means you have to calculate and update them as you create, insert, append, removem, and feed operations
    Creation: only two constructors:
        default: just empty data object
        create by adding data items from any standard C++ container (any that supports iteration) data type (std::array, std::vector, std::set, etc)). This may be bit hard. Search about this and really have a meaningful discussion within the team
    Removem: remove 1 to any (m) number of data item from the data object. You must validate the existence of m number of data item before the removal 
    The data is heavily duplicated. In situations like this we discussed storing pointers as a solution in the class
    You are not allowed to use any C/C++ math libraries
    Write your entire solutions with the class name "Simple_stat" in a single header named "simple_stat.h" file and test it in a separate main program

    In the same project since you will be using linear structures headers linked here, make sure those headers contain the copyright note, "

    // From the software distribution accompanying the textbook

    // "A Practical Introduction to Data Structures and Algorithm Analysis,

    // Third Edition (C++)" by Clifford A. Shaffer.

    // Source code Copyright (C) 2007-2011 by Clifford A. Shaffer."
    This is very important as your project in GitHub is open source.
    I updated code zip file I posted with this note. So if you download
    the latest linked here you are good to go.

Submission:

    Each group member must have a GitHub account and must show in the project as an active contributor
    Good readme.md page in github 
    Complete UML class diagram for Simple_stat class and overall class interaction diagram for the entire project
    Please submit as both a link to github project and as a zipped file version including the UML diagrams as the answer to this assignment

Testing criteria: (I will not penalize for missing this particular test)

        Create a random integer std::vector of size 1000 between 90 and 100 and use it create a Simple_stat object and verify the length_unique, length_total, mean, get_max, get_min and get_SD operations 
        Test feed operation; Create another random integer std::vector of size 10 between 90 and 100 and feed it to above object and verify the increases of length_unique, length_total
        Create a random double std::vector of size 1000 between 90 and 100 and use it create another Simple_stat object and verify the length_unique, length_total, mean, get_max, get_min and get_SD operations
        Test removem operation: remove any m number (lets us say 10)  duplicated numbers from the first integer Simple_stat object above and verify the length_unique, length_total, mean, get_max, get_min operations 

Rubric:

    60 points for only a relevant submission (based on UML, class declaration and correct object construction )

getters and statistic calculations: 10 points
Proper handling of duplicates: 10 points
Feed operation: 10 points
Removem operation: 10 points 
20 point extra credit for the winner of the speed and space test (I will design a criteria for this)
10 point extra credit for the first runner up of the speed and space test
5 point extra credit for the second runner up of the speed and space test

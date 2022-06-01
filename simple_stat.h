#ifndef SIMPLE_STAT_H
#define SIMPLE_STAT_H

#include "math.h"

#include "LinearStructures/link.h"
#include "LinearStructures/dlink.h"
#include "LinearStructures/alist.h"
#include "LinearStructures/llist.h"
#include "LinearStructures/dllist.h"
#include "LinearStructures/astack.h"
#include "LinearStructures/lstack.h"
#include "LinearStructures/aqueue.h"
#include "LinearStructures/lqueue.h"

// We define our simple_stat class template here
// We will use this class to represent our data object
// The template will use parameter N to represent the maximum size of the data object
// The class will use a link based data structure to store the data
template <typename T, int N>
class Simple_stat {
  // We require O(1) access to the statistics so we store these invidiual values as private members
  private:
    // We store the mean, standard deviation, min, and max as the type double
    double mean;
    double SD;
    double min;
    double max;
    double sum;
    double size;
    // We store all of the values within an array based list of type T as defined in the header file
    // An array based list has the best access time to the data and space efficiency for a known number of data elements
    // This is expected to be any number data type (int, double, etc)
    // N is the maximum size of the data object
    // Because we want to store only unique data elements but also record the number of repetitions we must two arrays, one for the data and one for the number of repetitions
    // We use a pointer to dynamically allocated memory to store the data
    AList<T>* unique_data = new AList<T>(N);
    // This is more space efficient than storing the same repeated data assuming the data has an average repetitions per value of greater than 2
    AList<int>* num_repetitions = new AList<int>(N);
  public:
    // We define the constructor and destructor as well as the getters and setters for the above statistics and adding data
    // The default constructor sets all statistics to 0
    Simple_stat(){
      mean = 0;
      SD = 0;
      min = 0;
      max = 0;
      sum = 0;
      size = 0;
    }
    // We also create a constructor that takes in a container of type T and adds the data to the data object
    // This constructor is expected to be used for feeding data from a container
    Simple_stat(const T& container){
      mean = 0;
      SD = 0;
      min = 0;
      max = 0;
      sum = 0;
      size = 0;
      // We use the feed method to add the data from the container
      feed(container);
    }
    // We define the destructor
    ~Simple_stat(){
      // We delete the unique_data and num_repetitions arrays
      delete unique_data;
      delete num_repetitions;
    }
    // We define the getters for the statistics
    double get_mean(){
      return mean;
    }
    double get_SD(){
      return SD;
    }
    double get_min(){
      return min;
    }
    double get_max(){
      return max;
    }

    // We define the feed method that adds data to the data object
    // This method is expected to be used for feeding data from a container
    void feed(const T& container){
      // We use the insert method to add the data from the container
      for(auto it = container.begin(); it != container.end(); ++it){
        insert(*it);
      }
      // We use the calculate method to calculate the statistics
      calculate();
    }
    // We define the insert method that adds a data item to the data object
    // This method is expected to be used for adding data from a container
    void insert(const T& data){
      if(check_unique(data)){
        // If the data is unique we add it to the unique_data array
        unique_data->append(data);
        // We add 1 to the number of repetitions for the data
        num_repetitions->append(1);
      }
      else{
        // If the data is not unique we add 1 to the number of repetitions for the data
        unique_data->moveToStart();
        num_repetitions->moveToStart();
        for(int i = 0; i < unique_data->length(); i++){
          if(unique_data->getValue() == data){
            num_repetitions->moveToPos(i);
            // Store the previous number of repetitions because you have to remove it and reinsert it to change it but when you do you can't read the value anymore, this bug took hours to find
            int prev = num_repetitions->getValue();
            num_repetitions->remove();
            num_repetitions->insert(prev + 1);
            break;
          }
          unique_data->next();
        }
      }
      size++;
      // calculate();
    }

    void printAll(){
      unique_data->moveToStart();
      num_repetitions->moveToStart();
      std::cout << "All numbers: ";
      for(int i = 0; i < unique_data->length(); i++){
        // Repeat the data the number of times it is repeated
        for(int j = 0; j < num_repetitions->getValue(); j++){
          std::cout << unique_data->getValue() << " ";
        }
        unique_data->next();
        num_repetitions->next();
      }
      std::cout << std::endl;
    }

    void print_unique(){
      unique_data->moveToStart();
      std::cout << "Unique: ";
      for(int i = 0; i < unique_data->length(); i++){
        std::cout << unique_data->getValue() << " ";
        unique_data->next();
      }
      std::cout << std::endl;
    }

    void print_num_repetitions(){
      num_repetitions->moveToStart();
      std::cout << "Repetitions: ";
      for(int i = 0; i < num_repetitions->length(); i++){
        std::cout << num_repetitions->getValue() << " ";
        num_repetitions->next();
      }
      std::cout << std::endl;
    }

    void calculate(){
      // We use the calculate_mean method to calculate the mean
      mean = calculate_mean();
      // We use the calculate_SD method to calculate the standard deviation
      SD = calculate_SD();
      // We use the calculate_min method to calculate the minimum
      min = calculate_min();
      // We use the calculate_max method to calculate the maximum
      max = calculate_max();
    }

    double get_sum(){
      // We use the get_sum method to calculate the sum
      int sum = 0;
      unique_data->moveToStart();
      num_repetitions->moveToStart();
      for(int i = 0; i < unique_data->length(); i++){
        sum += unique_data->getValue() * num_repetitions->getValue();
        unique_data->next();
        num_repetitions->next();
      }
      return sum;
    }

    int getLength(){
      return unique_data->length();
    }

    int getTotalLength(){
      return size;
    }

    bool check_unique(const T& data){
      // We use the check_unique method to check if the data is unique
      if(unique_data->length() == 0){
        return true;
      }
      unique_data->moveToStart();
      for(int i = 0; i < unique_data->length(); i++){
        if(unique_data->getValue() == data){
          return false;
        }
        unique_data->next();
      }
      return true;
    }

    double calculate_mean(){
      /*
       How do we get the mean?
       The mean is found by adding up things together then dividing by the number of things
       */

      // We use the get_sum method to get the sum of the data object
      double sum = get_sum();
      // size is a private variable which is automatically incremented on insert
      return sum/size;
    }

    double calculate_SD(){

      /*
       How do we calculate standard

      Standard deviation is found using the formula (Sum of (value of a data set minus the mean of the data set))^2)/(n-1)
       This means that we are depend on the function/result of the equation for mean.

       */

      // We use the get_mean method to get the mean of the data object
      double mean = calculate_mean();

      // Move the lists to the start
      unique_data->moveToStart();
      num_repetitions->moveToStart();
      double SD = 0;
      // Loop through the unique data points
      for(int i = 0; i < unique_data->length(); i++){
        // Add the square of the difference between the data and the mean multiplied by the number of repititions for each data point
        SD += pow((unique_data->getValue() - mean), 2) * num_repetitions->getValue();
        unique_data->next();
        num_repetitions->next();
      }
      // Divide the sum by the number of items minus 1, then sqrt that to get the final standard deviation and return it
      return sqrt(SD/(getTotalLength() - 1));
    }

    double calculate_min(){
      /*
       How do we obtain the minimum data item in the data set...
       We loop through the data set and keep track of the minimum value
       If the current value is less than the current minimum value we replace the current minimum value with the current value
      */
      unique_data->moveToStart();
      double localmin = unique_data->getValue();
      for(int i = 0; i < unique_data->length(); i++){
        if(unique_data->getValue() < localmin){
          localmin = unique_data->getValue();
        }
        unique_data->next();
      }
      return localmin;
    }

    double calculate_max(){
      /* Same as min but we keep track of the maximum data item
      */
      unique_data->moveToStart();
      double localmax = unique_data->getValue();
      for(int i = 0; i < unique_data->length(); i++){
        if(unique_data->getValue() > localmax){
          localmax = unique_data->getValue();
        }
        unique_data->next();
      }
      return localmax;
    }

};

#endif

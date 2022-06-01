// Group Project CS110C
// Created by Diana Skripnechenko

  /*
   From the software distribution accompanying the textbook
   
  "A Practical Introduction to Data Structures and Algorithm Analysis,
  Third Edition (C++)" by Clifford A. Shaffer.
  
  Source code Copyright (C) 2007-2011 by Clifford A. Shaffer."
  
  This is very important as your project in GitHub is open source.
  I updated code zip file I posted with this note. So if you download
  the latest linked here you are good to go.
 */

// Okay, This is my try.

#pragma 
#ifndef SIMPLE_STATS_H
#define SIMPLE_STATS_H

#include <iostream>
#include <vector>
#include <set>
#include <iterator> 
#include "sorting_algorithm.h"
#include "pair.h"


template <typename T>
class simple_stats {
private:
        std::vector<pair<T>> vec;
        int cnt;
        T sum;

        void devchecksum() {
                T sumcheck = 0;
                for (pair<T> v : vec) {
                        sumcheck += ((v.value) * v.freq);
                }
                if (sumcheck != sum) {
                        std::cout << "dev, you've got sum problem" << std::endl;
                }
        }
        void devcheckcnt() {
                int cntcheck = 0;
                for (pair<T> v : vec) {
                        cntcheck += v.freq;
        
        double standardDeviation;
        void calc_sd() {
                double pre_SD = 0;
                calc_mean();

                for (int i = 0; i < vec.size();i++) {
                        for (int j = 1; j <= vec[i].freq; j++) {
                                pre_SD += pow(vec[i].value - this->mean, 2.0);
                        }
                }
                standardDeviation = sqrt(pre_SD/ (double)cnt);
        }
        

public:
        simple_stats(int size = 10) { 
                
                vec.reserve(25);
                cnt = 0;
                sum = 0;
        }
        
        void append(T input) {
                int itIndex = NULL;
                if (cnt != 0) {
                        itIndex = ibsearch(input);
                }
                if (itIndex >= 0 && cnt > 0) {
                        vec[itIndex].freq++;
                }
                else if (itIndex < 0 || cnt == 0) {
                        pair<T> somepair(input, 1);
                        vec.push_back(somepair);
                }
                cnt++;
                sum += input;


                
                calc_mean();
                calc_sd();
                
                calc_mode(true);
                if(cnt != 1)
                        insertionSort(vec, 0, vec.size() - 1); 
                                                                                           
                calc_median();
                                                                   
        }
                }
                if (cnt != cntcheck) {
                        std::cout << "dev, I bet if it's money 


        
        std::vector<pair<T>> modes;
        std::vector<T> mode; 

        void calc_mode(bool updatingonly = false) {
                int n;
                if (updatingonly == false) {
                        modes.push_back(vec[0]);
                        n = 1;
                }
                else if (updatingonly == true) {
                        n = vec.size() - 1; 
                }

                if (modes.size() < 1) {
                        modes.push_back(vec[0]);
                }

                for (; n < vec.size() && vec.size() > 1; n++) {
                        if (vec[n].freq > modes[0].freq) {
                                modes.clear();
                                modes.push_back(vec[n]);
                        }
                        else if (vec[n].freq == modes[0].freq) {
                                if(vec[n].value != modes[0].value)
                                        modes.push_back(vec[n]); 
                        }
                        else {
                                
                        }
                }
                if (modes.size() == vec.size()) {
                        modes.clear(); 
                                           
                }
                
                mode.resize(modes.size());
                
                for (int n = 0; n < modes.size(); n++) {
                        mode.push_back(modes[n].value);
                }

        }
        
        T median; 
        void calc_median() {
                int medianIndex = vec.size() / 2;
                if (vec.size() % 2 != 0) {
                        median = vec[medianIndex].value; 
                }
                else if (vec.size() % 2 == 0) {
                        median = (vec[medianIndex].value + vec[medianIndex - 1].value) / 2;
                }
        }

        
        double mean;
        void calc_mean() {
                mean = sum / (double) cnt;
        }

        
        double standardDeviation;
        void calc_sd() {
                double pre_SD = 0;
                calc_mean();

                for (int i = 0; i < vec.size();i++) {
                        for (int j = 1; j <= vec[i].freq; j++) {
                                pre_SD += pow(vec[i].value - this->mean, 2.0);
                        }
                }
 can count that right" << std::endl;
                }
        
        int length_total() {
                int lengthTotal =0;
                for (pair<T> v : vec) {
                        lengthTotal += v.freq;
                }
                return lengthTotal;
        }

        
        std::set<T> unique_set() {
                std::set<T> uniqueSet;
                for (pair<T> v : vec) {
                        uniqueSet.insert(v.value);
                }
                return uniqueSet;
        }
        
        
        
        std::vector<T> get_mode() {
                return mode;
        }


        
        T get_median() {
                return median;
        }

        
        T get_mean() {
                return mean;
        }
        }
        
        T get_mean() {
                return mean;
        }

        
        double get_SD() {
                return standardDeviation;
        }

        
        T get_min() {
                return vec[0].value;
        }

        
        T get_max() {
                return vec[vec.size() - 1].value; 
        }



        void printallelements() {
                std::cout << "Printing all simple_stats class elements" << std::endl;
                for (pair<T> v : vec) {
                        std::cout << v.value << ", " << v.freq << "   ";
                }
                std::cout << "\n";

        }

        template <typename E>
        int ibsearch(const E& it) { 
                int leftBound, rightBound, middleItem;
                leftBound = 0;
                rightBound = vec.size() - 1;
                while (leftBound <= rightBound) {
                        middleItem = leftBound + ((rightBound - leftBound) / 2);
                        if (vec[middleItem].value == it) {
                                return middleItem;
                        }
                        else if (vec[middleItem].value > it) {
                                rightBound = middleItem - 1;
                        }
                        else if (vec[middleItem].value < it) {
                                leftBound = middleItem + 1;
                        }
                }
                return -1;
        }

};

#endif


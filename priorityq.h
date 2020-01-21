#include <iostream>

using namespace std;

#include "node.h"

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

class PriorityQueue { 
  public:
    PriorityQueue() { 
      aheap = new Item[2];
      keys = new int[2];
      size = 0;
      capacity = 2;
      totalKeys = 0;
    } 
    PriorityQueue(Item *array, int length) { 
      if (!array) 
        return;

      if (aheap) 
        delete [] aheap;
      if (keys) 
        delete [] keys;
      
      //slides say make capcity = length *2 but if we are not adding to the heap
      //why make it twice the size? And even if we change that later the push
      //function will adjust the capcity.
      size = length;
      capacity = length;
      totalKeys = length;
      aheap = new Item[length];
      keys = new int[length]; 
      for (int i = 0; i < length; i++) { 
        aheap[i] = array[i];
        //keys[array[i].key] = i;
      }
      //from slide
      for (int i = size/2; i >= 0; i--) { 
        reheapifyDown(i);
      }     
      for (int i = 0; i < length; i++) {
        keys[aheap[i].key] = i;
      }
    } 
    ~PriorityQueue() {//deconstructor
       delete [] aheap;
       delete [] keys;
    }
    int getCapacity();
    int getSize();
    bool push(int akey, int apr);
    void reheapifyUp(int i);
    void reheapifyDown(int i); 
    void print();
    Item getMin();
    void pop();
    bool updatePriority(int akey, int apr);
  private:
    Item *aheap = NULL;
    int *keys = NULL;//pointer to array whose indices represent keys
    int size;//total number of items in heap
    int capacity;//actual size of array to which heap points
    int totalKeys;//max number of keys

};

#endif

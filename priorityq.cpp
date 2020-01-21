#include <iostream>
#include <algorithm>

using namespace std;
#include "priorityq.h"
#include "node.h"

int PriorityQueue::getSize() {
  return size;
}

int PriorityQueue::getCapacity() {
  return capacity;
} 

bool PriorityQueue::push(int akey, int apr) {
  if (akey != size) 
    return false;

  if (size == capacity) { 
    Item *tmpheap = new Item[size * 2];
    int *tmpkeys = new int[size * 2];
    for (int i = 0; i < size; i++) { 
      tmpheap[i] = aheap[i];
      tmpkeys[i] = keys[i];
    } 
    delete [] aheap;
    delete [] keys;
    //now keys and aheap point to the new tmpkeys tmpheap
    keys = tmpkeys;
    aheap = tmpheap;
    capacity = size *2;
  } 
  keys[size] = size;
  aheap[size] = Item(akey, apr);
  //cout << "test" << endl;
  reheapifyUp(size);
  totalKeys++;
  size++;
  return true;
} 

//in slides 
void PriorityQueue::reheapifyDown(int i) {
  int left = (2*i) + 1;  //index of left child
  int right = (2*i) + 2;  //index of right child
  int amin = i;
  if (left >= size && right >= size)
    return;  //node is a leaf

  if (left < size && aheap[left].getPriority() < aheap[i].getPriority()) { 
    amin = left;
  } 
  
  if (right < size && aheap[right].getPriority() < aheap[amin].getPriority()) { 
    amin = right;
  } 
  
  if (amin != i) {
    swap (aheap[amin], aheap[i]);
    reheapifyDown(amin);
  } 
} 

void PriorityQueue::reheapifyUp(int i) { 
  int parent = (i - 1)/2;
  
  if (aheap[parent].priority > aheap[i].priority) {
    swap(aheap[parent], aheap[i]);
    swap(keys[aheap[i].key], keys[aheap[parent].key]);
    reheapifyUp(parent);
  } 
} 

void PriorityQueue::print() {
  for (int i = 0; i < size; i++) {
    cout << aheap[i].getPriority() << " ";
  } cout << '\n';
  for (int i = 0; i < size; i++) { 
    cout << aheap[i].key << " ";
  } cout << '\n';
  for (int i = 0; i <= totalKeys - 1; i++) { 
    cout << keys[i] << " ";
  } cout << '\n';
} 

Item PriorityQueue::getMin() {
  Item min;
  min = aheap[0];
  return min;  
} 

void PriorityQueue::pop() {
  int beginningIndex = 0;
  if (size == 0) { 
    return;
  } 
  else { 
    swap (aheap[size - 1] , aheap[beginningIndex]);
    size--;
    reheapifyDown(beginningIndex);
    for (int k = 0; k < size; k++) { 
      keys[aheap[k].key] = k;
    } 
  }
}  

bool PriorityQueue::updatePriority(int akey, int apr) {
  if (aheap[keys[akey]].getPriority() < apr) 
    return false;
  
  else if (aheap[keys[akey]].getPriority() > apr) {
    aheap[keys[akey]].priority = apr;
    reheapifyUp(keys[akey]);
    return true;
  } 
  
  //apr is equal etc returns false as well.
  return false;
} 







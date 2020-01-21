#include <iostream>

using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item{
  public: 
    Item() : key(0), priority(0) {} ;
    Item(int akey, int apriority) {
      key = akey; priority = apriority;
    } 

    int key;
    int priority;
    int getPriority() {return priority;}
};

#endif

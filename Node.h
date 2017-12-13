/*
Class Node. Stores a student value, and a pointer to the next node in the linked list
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;
class Node{
 public:
  //constructor, no arguments. The default state of VALUE and NEXT are both NULL
  Node();
  //desctructor
  ~Node();
  //returns the Student that the node stores
  Student* getValue();
  //use this to set the Student
  void setValue(Student* s);
  //returns the next node in the list 
  Node* getNext();
  //use this to set the  next node  
  void setNext(Node* n);

 private:
  //The student that is contained in this element of the list accessed via getValue() and setValue(Student* s)
  Student* value;
  //The next element in the list
  Node* next;
  
  //***NOTE: both VALUE and NEXT are initialized at NULL

};
#endif

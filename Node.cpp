#include <iostream>
#include "Node.h"

using namespace std;
Node::Node(){
  value = NULL;
  next = NULL;
}
Node::~Node(){
  delete value;
}
Student* Node::getValue(){
  return value;
}
void Node::setValue(Student* s){
  value = s;
}
Node* Node::getNext(){
  return next;
}
void Node::setNext(Node* n){
  next = n;
}

 



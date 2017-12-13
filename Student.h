#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;
class Student{
 public:
  //constructor
  Student(char* name, int id, float gpa);
  char* getName();
  int getID();
  float getGPA();
  void printS();
 private:
  char* name;
  float gpa;
  int id;

};
#endif

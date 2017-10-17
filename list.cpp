/*
Student List allows a user to input and keep track of student information
Mihira Sogal
10/17/2017
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;
//this struct is used to store name ,gpa, and id for all students
struct student{
  char name[80];
  int id;
  float gpa;
};

void addStudent(char name[], int id, float gpa, vector<student*> *nvector);

int main(){
  vector<student*> students;
  vector<student*> *studentptr = &students;
  
  bool inuse = true;
  while(inuse){
    //get input on what the user wants to do
    char action[20];
    cout<<"Type in what you want to do"<<endl;
    cin.get(action, 20);
    cin.ignore(80, '\n');
    //if user wants to add a student, prompt and collect the information for that student, then add it to the vector
    if(strcmp(action, "ADD")==0){
      char *name = new char[80];
      int id = 0;
      float gpa = 0.0;
      cout<<"Name of student: "<<endl;
      cin.get(name, 80);
      cin.ignore(100, '\n');
      cout<<"Student ID Number: "<<endl;
      cin>>id;
      cin.ignore(80,'\n');
      cout<<"GPA of Student: " <<endl;
      cin>>gpa;
      cin.ignore(80, '\n');
      // cout<<"Adding student... "<<"Name: "<<name<<"ID: "<<id<<"GPA: "<<gpa <<endl;
      addStudent(name, id, gpa, studentptr);
      // cout<<"Student added"<<endl;
    }
    //if user wants to print, go through the array, and print the info for each student
    if(strcmp(action,"PRINT")==0){
      if(!studentptr->empty()){
	for(vector<student*>::iterator it = studentptr->begin(); it != studentptr->end(); it++){
	  cout<<(*it)->name<<","<<(*it)->id<<","<<setprecision(3) << (*it)->gpa<<endl;
	}
	//if there are no students in the array, notify the user
      }else{
	cout<<"No Students entered!"<<endl;
      }
    }
    //exit the loop
    if(strcmp(action, "QUIT")==0){
      cout<<"Exiting..."<<endl;
      inuse = false;
    }
    //delete a student based in the ID that the user gives you
    if(strcmp(action, "DELETE")==0){
	cout<<"Enter the ID of the student you wish to delete"<<endl;
	int ID = 0;
	cin>>ID;
	cin.ignore(80, '\n');
	for(vector<student*>::iterator it = studentptr->begin(); it != studentptr->end(); it++){
	  if((*it)->id==ID){
	    delete (*it);
	    studentptr->erase(it);
	    break;
	  }
	}
	cout<<"Student # "<<ID<<" removed"<<endl;
    }
  }
  cout<<"EXITED LOOP"<<endl;
  
  return 0;
}

void addStudent(char sname[80], int sid, float sgpa, vector<student*> *nvector ){
  // cout<<"ENTERED ADDSTUDENT"<<endl;
  // cout<<"Creating new student"<<endl;
  student *newst = new student();
  // cout<<"Student created"<<endl;
  // cout<<"Copying name"<<endl;
  strcpy((newst->name),sname);
  // cout<<"Name copied"<<endl;
  // cout<<"Copying ID"<<endl;
  newst->id = sid;
  // cout<<"id copied"<<endl;
  // cout<<"Copying GPA"<<endl;
  newst->gpa = sgpa;
  // cout<<"gpa copied"<<endl;
  // cout<<"pushing student"<<endl;
  (*nvector).push_back(newst);
  //  cout<<"Student pushed"<<endl;
}

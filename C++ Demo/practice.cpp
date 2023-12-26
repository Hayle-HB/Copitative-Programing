#include <iostream>
#include <fstream>
using namespace std;
/*You are tasked with creating a program to manage a student database. 
Each student has the following attributes: name, roll number, age, and GPA 
. Design a C++ program that uses a structure to represent a student's information 
and provides the following functionality:

    Create a new student record and save it to a file.
    Display the details of a specific student given their roll number.
    Calculate and display the average GPA of all students in the database.
    Allow the user to update the details of a student.
    Provide a menu-driven interface for the user to interact with the program.

You should implement this program using functions for each of the above tasks,
 use a structure to represent student data, and use a template for reading and writing data to/from a file.*/
struct Student {  
  string name;
  int roll_num;
  int age;
  double GPA;
};

void create_data_in_to_file(string filename, Student &stu){
     ofstream outData(filename);
 if(!outData){
  cerr << "Unable to open ";
}
    outData << stu.name << "\t" << stu.age << "\t" << stu.roll_num << "\t" << stu.GPA << endl;
   outData.close();
}

void display(string filename, Student stu){
  ifstream inData(filename);
  if(!inData){
  cerr << "Unable to open ";
}
cout << "Name  Age  Roll num  GPA \n";
string line;
  while(getline(inData, line)){
    cout << line << endl;
  }
}

int main(){

Student stu;

string filename = "newfile.txt";

cout << "Enter records \n";
cout << "Name : ";
cin >> stu.name;
cout << "Enter age ";
cin >> stu.age;
cout << "Enter roll numebr ";
cin >> stu.roll_num;
stu.GPA = 4;

create_data_in_to_file(filename, stu);
display(filename, stu);

  return 0;
}


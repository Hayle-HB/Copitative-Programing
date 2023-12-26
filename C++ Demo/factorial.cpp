#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;







// ANSI escape codes for changing text colors and making text bold
const char* colors[] = {
    "\x1B[31;1m", // Red (bold)
    "\x1B[32;1m", // Green (bold)
    "\x1B[33;1m", // Yellow (bold)
    "\x1B[34;1m", // Blue (bold)
};

int Number_of_student;
struct Student
{
  string name;
  int ID;
  double grade[5];
};

void accept_student_record(const char* filename){
    ofstream file(filename, ios::app);
    if(!file){
        cerr << "Unable to open!";
        return;
    }

    cout <<"Enter the number of student in the class :\n";
         cout << "~: ";
         cin >> Number_of_student;
    Student stu[Number_of_student];
    cout << "Enter The data of a studnt \n"; 
    for(int i = 0; i < Number_of_student; i++){
        cout << "Student data for student "<< i+1 << endl;
        cin.ignore();
        cout << "Name: ";
        getline(cin, stu[i].name);

        cout << "ID : ";
        cin >> stu[i].ID;
    file << stu[i].name << "\t" <<  stu[i].ID  << "\t";
    cout << "Mark of the courses : \n";
    for(int j =0; j < 5; j++){
     cout <<"Mark " << j+1 << ": ";
     cin >> stu[i].grade[j];
     file <<  stu[i].grade[j] << "\t";
    }
    file << endl;
        }
   cout << "\x1B[1m" << "\x1B[31m" << "\nThe student record added successfully" << "\x1B[0m" <<endl;
   file.close();
}
void display_Student_record(const char* filename){
    ifstream file(filename);


    if(!file){
        cerr << "Unable to open:";
    }
     string line;
             cout << "\n\nThe Information of the class data is \n";
        cout << "Name \t ID \t \tGrades \n";
    while(getline(file, line)){
        istringstream iss(line);
        Student stu;
        
        iss >> stu.name >> stu.ID >> stu.grade[0]>> stu.grade[1] >> stu.grade[2] >> stu.grade[3] >> stu.grade[4];

        cout << stu.name  << "    " << stu.ID  << "    " << stu.grade[0] <<"    " 
              <<  stu.grade[1] << "    " << stu.grade[2] <<"  " 
              <<  stu.grade[3] << "    " <<  stu.grade[4];
              cout << endl;
    }
              cout << endl;
              cout << endl;
 

   file.close();


}
void Average_of_each_student(const char* filename){

    ifstream file(filename);
    if(!file){
        cerr << "Unable to open! ";
        return;
    }
   string line;
   Student stu;

   double CLASS_AVERAGE = 0;
   double CLASS_TOTAL = 0;
    while (getline(file, line))
    {    

        istringstream iss(line);
        iss >> stu.name >> stu.ID >> stu.grade[0]>> stu.grade[1] >> stu.grade[2] >> stu.grade[3] >> stu.grade[4];
        double Average = 0;
        double total = 0;
        for(int i = 0; i < 5; i++){
            total += stu.grade[i];
           }
        Average = total/5.0;
    cout << "\n\nInformation of the srudent : \n";
        cout  << "Name : " << stu.name << endl;
        cout  << "ID : " << stu.ID << endl;
        cout  << "Marks : \n\t";
        for(int i = 0; i < 5; i++){
            cout << " " << stu.grade[i];
           }
        cout << endl;

        cout << "Average Mark    " << Average << endl;

        CLASS_TOTAL+= Average;    
    }

    CLASS_AVERAGE = CLASS_TOTAL/Number_of_student;


    cout  <<"\n CLASS AVERAGE MARK IS " << CLASS_AVERAGE << "\n\n";
    
    file.close();
}
void search_student_record(const char* filename){
    ifstream file(filename);
    if(!file){
        cerr << "Unable to open!";
        return;
    }
    string name;
    cout <<"Enter The name of the student \n";
    cout << "~ : ";
    cin >> name;

    bool found = false;

    string line;
    while(getline(file, line)){
        istringstream iss(line);
        Student stu;
        iss >> stu.name >> stu.ID >> stu.grade[0]>> stu.grade[1] >> stu.grade[2] >> stu.grade[3] >> stu.grade[4];

        if(stu.name == name){
            found = true;
        cout << "\nName : " << stu.name
             <<"\nID No`: " << stu.ID
             <<"\nMarks : \n  \t";
             for(int i =0; i < 5; i++){
                cout << stu.grade[i] << " ";
             }
             cout << endl << endl;
        }
    }
    if(!found){
        cout << "\nThe student is not found in the file : \n";
        return;
    }

    file.close();

}
void update_student_record(const char* filename) {
    ifstream file(filename);
    ofstream tempfile("tempfile.txt");

    string name;
    cout << "Enter student name that you want to modify:\n";
    cout << "~: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, name);

    string line;
    bool found = false;
    Student stu;

    while (getline(file, line)) {
        istringstream iss(line);
        iss >> stu.name >> stu.ID >> stu.grade[0] >> stu.grade[1] >> stu.grade[2] >> stu.grade[3] >> stu.grade[4];

        if (name == stu.name) {
            cout << "Enter the updated data for the student record:\n";
            cout << "Enter Name: ";
            getline(cin, stu.name);
            cout << "Enter ID: ";
            cin >> stu.ID;

            cout << "Enter Marks:\n";
            for (int i = 0; i < 5; i++) {
                cout << "Enter Mark " << i + 1 << ": ";
                cin >> stu.grade[i];
            }

            tempfile << stu.name << " " << stu.ID << " ";
            for (int i = 0; i < 5; i++) {
                tempfile << stu.grade[i] << " ";
            }
            tempfile << endl;

            found = true;
        } else {
            tempfile << line << endl;
        }
    }

    file.close();
    tempfile.close();

    if (found) {
        cout << "The data has been successfully updated.\n";
    } else {
        cout << "Student with the name '" << name << "' was not found.\n";
    }

    remove(filename);
    rename("tempfile.txt", filename);
}
void delete_student_record(const char* filename) {
    ifstream file(filename);
    ofstream tempfile("tempfile.txt");

    string name;
    cout << "Enter the name of the student you want to delete:\n";
    cout << "~: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, name);

    string line;
    bool found = false;
    Student stu;

    while (getline(file, line)) {
        istringstream iss(line);
        iss >> stu.name >> stu.ID >> stu.grade[0] >> stu.grade[1] >> stu.grade[2] >> stu.grade[3] >> stu.grade[4];

        if (name == stu.name) {
            found = true;
        } else {
            tempfile << line << endl;
        }
    }

    file.close();
    tempfile.close();

    if (found) {
        cout << "The student record for '" << name << "' has been deleted.\n";
    } else {
        cout << "Student with the name '" << name << "' was not found.\n";
    }

    remove(filename);
    rename("tempfile.txt", filename);
}
int main(){

int op;
const char* filename = "DDDDD.txt";
do{
cout 
    << "Enter your choice\n"
    <<"1.Accept Info : \n"
    <<"2.Display Recors\n"
    <<"3.Calculate Average of each student and the whole Class\n"
    <<"4.Search student record by Name \n"
    <<"5.Update student record\n"
    <<"6.Delete student record\n"
    <<"7.\n"
    <<"8.Exit the program\n";
cin >> op;


switch (op)
{
case 1:    accept_student_record(filename);
    break;
case 2:    display_Student_record(filename);
    break;
case 3:    Average_of_each_student(filename);
    break;
case 4:
        search_student_record(filename);
    break;
case 5:
       update_student_record(filename);
    break;
case 6:
    delete_student_record(filename);
    break;
case 7:
    break;
case 8:
cout << "Existing the program...";
    break;
default:
cout << "Incorrect input try again \n";
    break;
}
}while(op!=8);






    return 0;
}
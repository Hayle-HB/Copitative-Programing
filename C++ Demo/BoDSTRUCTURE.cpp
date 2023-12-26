/*Given a structure a specification to store the details of 10 students (rollno, name,
marks in five subject, BoD which it’s type is Date struct), write a program to input
each students detail using function and perform the following;
a) Compute average score for each student and print the students’ details in
tabular format along with their scores
b) Determine and print students details who scored average mark below 50*/
#include <iostream>
#include <string>

using namespace std;

// Define a Date struct to store the date of birth
struct Date {
    int day;
    int month;
    int year;
};

// Define a Student struct to store student details
struct Student {
    int rollno;
    string name;
    int marks[5]; // Marks in five subjects
    Date dob;     // Date of birth
};

// Function to input details of a single student
void inputStudentDetails(Student& student) {
    cout << "Enter Roll Number: ";
    cin >> student.rollno;
    cin.ignore(); // Clear the newline character from the input buffer
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Enter Date of Birth (dd mm yyyy): ";
    cin >> student.dob.day >> student.dob.month >> student.dob.year;

    cout << "Enter Marks in Five Subjects: ";
    for (int i = 0; i < 5; ++i) {
        cin >> student.marks[i];
    }
}

// Function to calculate the average score of a student
double calculateAverageScore(const Student& student) {
    double total = 0;
    for (int i = 0; i < 5; ++i) {
        total += student.marks[i];
    }
    return total / 5.0;
}

int main() {
    const int numStudents = 2;
    Student students[numStudents];

    // Input details of 10 students
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for Student " << i + 1 << ":" << endl;
        inputStudentDetails(students[i]);
    }

    // Print students' details along with their scores and calculate averages
    cout << "\nStudent Details and Scores:" << endl;
    cout << "Roll No\tName\tDate of Birth\tSubject Scores\tAverage Score" << endl;
    for (int i = 0; i < numStudents; ++i) {
        double average = calculateAverageScore(students[i]);
        cout << students[i].rollno << "\t" << students[i].name << "\t"
             << students[i].dob.day << "/" << students[i].dob.month << "/"
             << students[i].dob.year << "\t";
        for (int j = 0; j < 5; ++j) {
            cout << students[i].marks[j] << "\t";
        }
        cout << average << endl;

        // Check if the average score is below 50 and print if necessary
        if (average < 50) {
            cout << students[i].name << " scored below 50 in average." << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define the Student structure
struct Student {
    int rollno;
    string name;
    float marks;
};

// Function to get student record from user
void getRecord(Student &s) {
    cout << "Enter the roll number: ";
    cin >> s.rollno;
    cout << "Enter name: ";
    cin.ignore(); // Ignore any previous newline character
    getline(cin, s.name);
    cout << "Enter mark: ";
    cin >> s.marks;
}

// Function to display a student record
void displayRecord(const Student &s) {
    cout << "Roll number: " << s.rollno << endl;
    cout << "Name: " << s.name << endl;
    cout << "Mark: " << s.marks << endl;
}

// Function to write student records to a file
bool writeRecordsToFile(const string &filename, const Student *students, int n) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return false;
    }

    for (int i = 0; i < n; i++) {
        outFile << students[i].rollno << " " << students[i].name << " " << students[i].marks << endl;
    }

    outFile.close();
    return true;
}

// Function to read student records from a file and display them
bool readRecordsFromFile(const string &filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }

    Student s;

    cout << "Student Records:" << endl;
    while (inFile >> s.rollno >> s.name >> s.marks) {
        displayRecord(s);
        cout << endl;
    }

    inFile.close();
    return true;
}

int main() {
    int n;
    cout << "Enter the number of student records you want to enter: ";
    cin >> n;

    // Dynamic memory allocation for an array of Student objects
    Student *students = new Student[n];

    for (int i = 0; i < n; i++) {
        getRecord(students[i]);
    }

    if (writeRecordsToFile("Test.txt", students, n)) {
        cout << "Records written to file successfully." << endl;
    }

    if (readRecordsFromFile("Test.txt")) {
        cout << "Records read from file successfully." << endl;
    }

    // Free dynamically allocated memory
    delete[] students;

    return 0;
}

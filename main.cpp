#include <iostream>
#include <string>

using namespace std;

// Define a class called "Student"
class Student {
public:
    // Attributes of a student
    string name;
    int age;
    int reg_no;
    string program;
    int semester;
    int roll_no;
    int attendance;
    int marks[5]; // Array to hold marks in 5 subjects

    // Function to get details from the user
    void getDetails() {
        cout << "Enter student details:\n";

        cout << "Name: ";
        cin >> name;

        cout << "Age: ";
        cin >> age;

        cout << "Registration Number: ";
        cin >> reg_no;

        cout << "Program: ";
        cin >> program;

        cout << "Semester: ";
        cin >> semester;

        cout << "Roll Number: ";
        cin >> roll_no;

        cout << "Attendance (%): ";
        cin >> attendance;

        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Mark " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    // Function to show all details of the student
    void showDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Reg No: " << reg_no << endl;
        cout << "Program: " << program << endl;
        cout << "Semester: " << semester << endl;
        cout << "Roll No: " << roll_no << endl;
        cout << "Attendance: " << attendance << "%" << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    // Function to show only the student's name
    void showName() const {
        cout << "Name: " << name << endl;
    }

    // Function to show the attendance percentage
    void showAttendance() const {
        cout << "Attendance: " << attendance << "%" << endl;
    }

    // Function to calculate total marks
    int totalMarks() const {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        return sum;
    }
};

// Function to display the top 5 students by total marks
void showTop5(Student students[], int size) {
    Student top5[5]; // Array to store the top 5 students

    for (int i = 0; i < 5 && i < size; i++) {
        const Student* topStudent = nullptr;
        int maxMarks = -1;

        for (int j = 0; j < size; j++) {
            // Check if this student is already in top5 to avoid duplicates
            bool alreadySelected = false;
            for (int k = 0; k < i; k++) {
                if (&students[j] == &top5[k]) {
                    alreadySelected = true;
                    break;
                }
            }

            // Update topStudent if this student has higher marks and is not already selected
            if (!alreadySelected && students[j].totalMarks() > maxMarks) {
                maxMarks = students[j].totalMarks();
                topStudent = &students[j];
            }
        }

        if (topStudent) {
            top5[i] = *topStudent; // Add the top student to the top5 array
        }
    }

    // Display the top 5 students
    cout << "Top 5 Students by Marks:" << endl;
    for (int i = 0; i < 5 && i < size; i++) {
        cout << "Rank " << i + 1 << ": ";
        top5[i].showDetails();
    }
}

int main() {
    const int studentCount = 5;
    Student students[studentCount]; // Array to hold students

    // Get details for each student
    for (int i = 0; i < studentCount; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        students[i].getDetails();
    }

    // Display options to user
    int option;
    do {
        cout << "\nMenu:\n";
        cout << "1. Show details of all students\n";
        cout << "2. Show name of all students\n";
        cout << "3. Show attendance of all students\n";
        cout << "4. Show top 5 students by total marks\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                for (int i = 0; i < studentCount; i++) {
                    cout << "\nDetails of student " << i + 1 << ":\n";
                    students[i].showDetails();
                }
                break;

            case 2:
                cout << "\nNames of all students:\n";
                for (int i = 0; i < studentCount; i++) {
                    students[i].showName();
                }
                break;

            case 3:
                cout << "\nAttendance of all students:\n";
                for (int i = 0; i < studentCount; i++) {
                    students[i].showAttendance();
                }
                break;

            case 4:
                showTop5(students, studentCount);
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (option != 5);

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Student {
public:

    string name;
    int age;
    int reg_no;
    string program;
    int semester;
    int roll_no;
    int attendance;
    int marks[5];

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

    void showName() const {
        cout << "Name: " << name << endl;
    }

    void showAttendance() const {
        cout << "Attendance: " << attendance << "%" << endl;
    }

    int totalMarks() const {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        return sum;
    }
};

void showTop5(Student students[], int size) {
    Student top5[5]; // Array to store the top 5 students

    for (int i = 0; i < 5 && i < size; i++) {
        const Student* topStudent = nullptr;
        int maxMarks = -1;

        for (int j = 0; j < size; j++) {

            bool alreadySelected = false;
            for (int k = 0; k < i; k++) {
                if (&students[j] == &top5[k]) {
                    alreadySelected = true;
                    break;
                }
            }

                        if (!alreadySelected && students[j].totalMarks() > maxMarks) {
                maxMarks = students[j].totalMarks();
                topStudent = &students[j];
            }
        }

        if (topStudent) {
            top5[i] = *topStudent;
        }
    }

    cout << "Top 5 Students by Marks:" << endl;
    for (int i = 0; i < 5 && i < size; i++) {
        cout << "Rank " << i + 1 << ": ";
        top5[i].showDetails();
    }
}

int main() {
    const int studentCount = 5;
    Student students[studentCount];

    for (int i = 0; i < studentCount; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        students[i].getDetails();
    }

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

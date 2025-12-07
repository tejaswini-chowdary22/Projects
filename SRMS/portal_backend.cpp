#include <bits/stdc++.h>
using namespace std;

// ------------------- STUDENT CLASS -------------------
class Student {
public:
    string name, contact, gender, cls, section, address;
    string roll;  // CHANGED from int to string
    int age;
    int currentSem;
    vector<float> semMarks;
    float cgpa;

    void input() {
        cin.ignore();  // clear buffer once

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Roll Number (Ex: AP24110011890): ";
        cin >> roll;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Contact Number: ";
        cin >> contact;

        cout << "Enter Gender: ";
        cin >> gender;

        cout << "Enter Class: ";
        cin >> cls;

        cout << "Enter Section: ";
        cin >> section;

        cin.ignore(); // clear buffer before address input
        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Current Semester: ";
        cin >> currentSem;

        int subjects;
        cout << "Enter number of subjects in this semester: ";
        cin >> subjects;

        semMarks.clear();
        cout << "Enter marks of each subject:\n";
        for (int i = 0; i < subjects; i++) {
            float m;
            cout << "Subject " << (i + 1) << ": ";
            cin >> m;
            semMarks.push_back(m);
        }

        cout << "Enter Overall CGPA: ";
        cin >> cgpa;
    }

    void display() const {
        cout << "\n---------------------------------------\n";
        cout << "Name          : " << name << endl;
        cout << "Roll Number   : " << roll << endl;
        cout << "Age           : " << age << endl;
        cout << "Contact       : " << contact << endl;
        cout << "Gender        : " << gender << endl;
        cout << "Class & Sec   : " << cls << " - " << section << endl;
        cout << "Address       : " << address << endl;
        cout << "Current Sem   : " << currentSem << endl;

        cout << "Marks         : ";
        for (float m : semMarks) cout << m << " ";
        cout << endl;

        cout << "Overall CGPA  : " << cgpa << endl;
        cout << "---------------------------------------\n";
    }
};

// ------------------- MANAGER CLASS -------------------
class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        s.input();
        students.push_back(s);
        cout << "\nStudent added successfully!\n";
    }

    void addMultiple() {
        int n;
        cout << "How many students to add? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "\nEntering details for student " << (i + 1) << ":\n";
            addStudent();
        }
    }

    void displayAll() {
        if (students.empty()) {
            cout << "\nNo student records found.\n";
            return;
        }
        for (const auto &s : students) s.display();
    }

    void searchStudent() {
        string r;
        cout << "Enter roll number to search: ";
        cin >> r;

        for (auto &s : students) {
            if (s.roll == r) {
                cout << "\nStudent Found:\n";
                s.display();
                return;
            }
        }
        cout << "\nStudent not found!\n";
    }

    void updateStudent() {
        string r;
        cout << "Enter roll number to update: ";
        cin >> r;

        for (auto &s : students) {
            if (s.roll == r) {
                cout << "\nEnter new details for this student:\n";
                s.input();
                cout << "\nRecord updated successfully!\n";
                return;
            }
        }
        cout << "\nStudent not found!\n";
    }

    void deleteStudent() {
        string r;
        cout << "Enter roll number to delete: ";
        cin >> r;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].roll == r) {
                students.erase(students.begin() + i);
                cout << "\nStudent deleted successfully!\n";
                return;
            }
        }
        cout << "\nStudent not found!\n";
    }
};

// ------------------- SIGNUP + LOGIN SYSTEM -------------------
class LoginSystem {
private:
    string username;
    string password;

public:
    void signup() {
        cout << "\n------ SIGN UP ------\n";
        cout << "Create Username: ";
        cin >> username;
        cout << "Create Password: ";
        cin >> password;
        cout << "\nSignup Successful! Please Login.\n";
    }

    bool login() {
        string u, p;

        cout << "\n------ LOGIN ------\n";
        cout << "Enter Username: ";
        cin >> u;
        cout << "Enter Password: ";
        cin >> p;

        if (u == username && p == password) {
            cout << "\nLogin Successful!\n";
            return true;
        } else {
            cout << "\nInvalid Credentials! Try again.\n";
            return false;
        }
    }
};

// ------------------- MAIN PROGRAM -------------------
int main() {
    LoginSystem loginSys;
    StudentManager sm;

    loginSys.signup();

    while (!loginSys.login()) {
        cout << "Please try logging in again.\n";
    }

    int choice;

    while (true) {
        cout << "\n======================\n";
        cout << " STUDENT MANAGEMENT\n";
        cout << "======================\n";
        cout << "1. Add Student\n";
        cout << "2. Add Multiple Students\n";
        cout << "3. Display All Students\n";
        cout << "4. Search Student\n";
        cout << "5. Update Student\n";
        cout << "6. Delete Student\n";
        cout << "7. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: sm.addStudent(); break;
            case 2: sm.addMultiple(); break;
            case 3: sm.displayAll(); break;
            case 4: sm.searchStudent(); break;
            case 5: sm.updateStudent(); break;
            case 6: sm.deleteStudent(); break;
            case 7:
                cout << "\nLogging out... Goodbye!\n";
                exit(0);
            default:
                cout << "\nInvalid choice! Try again.\n";
        }
    }
    return 0;
}
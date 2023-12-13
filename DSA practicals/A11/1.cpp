/*
Department maintains a student information. The file contains roll number, name, division and address. Allow user to add, delete information of student. Display information  of  particular  employee.  If  record  of  student  does  not  exist  an  appropriate message is displayed. If it is, then the system displays the student details. Use sequential file to main the data.
Program for performing various operations on Sequential File organisation.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student 
{
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudent() 
{
    ofstream file("student_info.txt", ios::app);
    
    Student student;
    
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, student.name);
    
    cout << "Enter division: ";
    getline(cin, student.division);
    
    cout << "Enter address: ";
    getline(cin, student.address);
    
    file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    
    file.close();
    
    cout << "Student information added successfully." << endl;
}

void deleteStudent() {
    ifstream inputFile("student_info.txt");
    ofstream outputFile("temp.txt", ios::app);
    
    int rollNumber;
    cout << "Enter the roll number of the student to delete: ";
    cin >> rollNumber;
    
    bool found = true;
    Student student;
    
    while (inputFile.read(reinterpret_cast<char*>(&student), sizeof(Student)))
    {
        if (student.rollNumber != rollNumber)
        {
            outputFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
        } else
        {
            found = true;
        }
    }
    
    inputFile.close();
    outputFile.close();
    
    if (found)
    {
        remove("student_info.txt");
        rename("temp.txt", "student_info.txt");
        cout << "Student information deleted successfully." << endl;
    } else 
    {
        remove("temp.txt");
        cout << "Student record not found." << endl;
    }
}

void displayStudent() {
    ifstream file("student_info.txt");
    
    int rollNumber;
    cout << "Enter the roll number of the student to display: ";
    cin >> rollNumber;
    
    bool found =true;
    Student student;
    
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student)))
    {
        if (rollNumber == student.rollNumber)
        {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
       
    }
    
    if (rollNumber != student.rollNumber) {
        cout << "Student record not found." << endl;
    }
      file.close();
}

int main() 
{
    int choice;
    
    do {
        cout << "-------------------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Exit" << endl;
        cout << "-------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        
        cout << endl;
    } while (choice != 4);
    
    return 0;
}
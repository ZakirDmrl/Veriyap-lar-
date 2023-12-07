#include <iostream>
#include <stdlib.h>

using namespace std;

enum Gender { Male, Female };

typedef struct DataStruct {
    Gender gender;
    int ID;
    char* name;
    float wage;
} Data;

typedef struct ListStruct {
    Data* data;
    struct ListStruct* next;
} List;

short int Menu() {
    // system("CLS");
    cout << "1 => Add Employee" << endl;
    cout << "2 => Remove Employee" << endl;
    cout << "3 => List Employees" << endl;
    cout << "4 => Raise Wage" << endl;
    cout << "5 => Exit Program" << endl;
    short int ch;
    cin >> ch;
    return ch;
}

void AddEmployee(List*& head, Data* newdata);
void RemoveEmployee(List*& head, int id);
void ListEmployees(List* head);
void RaiseWages(List* head, float percentage);

int main(int argc, char** argv) {

    List* head = nullptr;
    Data* newData = new Data{ Male, 1, "John", 50000.0 };

    while (1) {
        int ch = Menu();
        switch (ch) {
        case 1: 
            AddEmployee(head, newData);
            break;
        case 2:
            RemoveEmployee(head, 1);
            break;
        case 3:
            ListEmployees(head);
            break;
        case 4:
          
            RaiseWages(head, 0.10);
            break;
        case 5:
            exit(1);
            break;
        default:
            cout << "Please enter an integer between 1 and 5!" << endl;
            break;
        }
    }

    return 0;
}

void AddEmployee(List*& head, Data* newdata) {
    List* newNode = new List;
    newNode->data = newdata;
    newNode->next = head;
    head = newNode;
}

void RemoveEmployee(List*& head, int id) {
    List* current = head;
    List* previous = nullptr;

    while (current != nullptr && current->data->ID != id) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Employee with ID " << id << " not found." << endl;
        return;
    }

    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current->data;
    delete current;
}

void ListEmployees(List* head) {
    if (head == nullptr) {
        cout << "Employee list is empty." << endl;
        return;
    }

    List* current = head;

    while (current != nullptr) {
        cout << "ID: " << current->data->ID << ", Name: " << current->data->name << ", Wage: " << current->data->wage << endl;
        current = current->next;
    }
}

void RaiseWages(List* head, float percentage) {
    List* current = head;

    while (current != nullptr) {
        current->data->wage += current->data->wage * percentage;
        current = current->next;
    }
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to create a new phonebook
void CreatePhonebook(const string& fileName) {
    ofstream file(fileName, ios::trunc);
    if (!file) {
        cerr << "Error: Unable to create file \"" << fileName << "\".\n";
        return;
    }
    file.close();
}

// Function to view the phonebook
void ViewPhonebook(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Error: Unable to open file \"" << fileName << "\".\n";
        return;
    }

    string line;
    cout << "\nPhonebook contents:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Function to add a new entry
void AddEntry(const string& fileName, const string& surname, const string& name, const string& phone, int day, int month, int year) {
    ofstream file(fileName, ios::app);
    if (!file) {
        cerr << "Error: Unable to open file \"" << fileName << "\".\n";
        return;
    }

    file << surname << " " << name << " " << phone << " "
        << day << " " << month << " " << year << "\n";
    file.close();
}

// Function to search friends by birth month
void ShowByMonth(const string& fileName, int searchMonth) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Error: Unable to open file \"" << fileName << "\".\n";
        return;
    }

    string surname, name, phone;
    int day, month, year;
    bool found = false;

    cout << "\nFriends born in month " << searchMonth << ":\n";
    while (file >> surname >> name >> phone >> day >> month >> year) {
        if (month == searchMonth) {
            cout << surname << " " << name << " " << phone << " "
                << day << "." << month << "." << year << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No friends born in this month.\n";
    }

    file.close();
}

// Function to display the menu
void DisplayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Create a new phonebook\n";
    cout << "2. View the phonebook\n";
    cout << "3. Add a new entry\n";
    cout << "4. Search by birth month\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    string fileName;
    cout << "Enter the name of the phonebook file: ";
    cin >> fileName;

    int choice;
    do {
        DisplayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            CreatePhonebook(fileName);
            cout << "Phonebook has been created.\n";
            break;
        }
        case 2: {
            ViewPhonebook(fileName);
            break;
        }
        case 3: {
            string surname, name, phone;
            int day, month, year;

            cout << "Enter surname: ";
            cin >> surname;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phone;
            cout << "Enter birth date (day, month, year): ";
            cin >> day >> month >> year;

            AddEntry(fileName, surname, name, phone, day, month, year);
            cout << "Entry has been successfully added.\n";
            break;
        }
        case 4: {
            int searchMonth;
            cout << "Enter the month to search for (1-12): ";
            cin >> searchMonth;
            if (searchMonth < 1 || searchMonth > 12) {
                cout << "Error: Month must be between 1 and 12.\n";
            }
            else {
                ShowByMonth(fileName, searchMonth);
            }
            break;
        }
        case 5: {
            cout << "Program terminated.\n";
            break;
        }
        default:
            cout << "Error: Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}


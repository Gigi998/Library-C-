#include <iostream>
#include <string>
#include <vector>

#include "./include/Librarian.h"

using namespace std;

void showMenu() {
  cout << "\n📚 Library Management System 📚\n";
  cout << "--------------------------------\n";
  cout << "1️⃣ Register Student\n";
  cout << "2️⃣ Add Book\n";
  cout << "3️⃣ Issue Book\n";
  cout << "4️⃣ Return Book\n";
  cout << "5️⃣ View All Books\n";
  cout << "6️⃣ View Students\n";
  cout << "7 Rate book\n";
  cout << "8 Exit\n";
  cout << "--------------------------------\n";
  cout << "Choose an option: ";
}

void authForm(string& name, string& password) {
  cout << "Enter user name: ";
  cin >> name;

  cout << "Enter password: ";
  cin >> password;
}

int main() {
  Library myLibrary;
  Librarian librarian;

  string name, password;
  bool isProgramRunning = true;

  authForm(name, password);

  if (!librarian.authenticate(name, password)) {
    cout << "Wrong email or password!!" << endl;
    authForm(name, password);
  }

  librarian.userDetails();

  while (isProgramRunning) {
    showMenu();
    int choice = 0;
    cin >> choice;
    cin.ignore();

    string bookTitle, studentName;
    int studentId, bookId;

    switch (choice) {
      case 1:
        cout << "Enter student name: ";
        cin >> studentName;
        librarian.registerStudent(myLibrary, studentName);
        break;
      case 2:
        cout << "Enter book title: ";
        getline(cin, bookTitle);
        librarian.addBook(myLibrary, bookTitle);
        break;
      case 3:
        cout << "Enter student Id: ";
        cin >> studentId;
        cout << "Enter the book Id: ";
        cin >> bookId;
        librarian.issueBook(myLibrary, studentId, bookId);
        break;
      case 4:
        cout << "Enter student Id: ";
        cin >> studentId;
        cout << "Enter the book Id: ";
        cin >> bookId;
        librarian.returnBook(myLibrary, studentId, bookId);
        break;
      case 5:
        myLibrary.getAllBooks();
        break;
      case 6:
        librarian.getStudents(myLibrary);
        break;
      case 7:
        int rate;
        cout << "Enter rate(number): ";
        cin >> rate;
        cout << "Enter the book Id: ";
        cin >> bookId;
        librarian.rateBook(myLibrary, bookId, rate);
        break;
      case 8:
        cout << "Exiting" << endl;
        isProgramRunning = false;
        break;
      default:
        cout << "Selected option invalid";
        break;
    }
  }
  return 0;
}
#include "./include/Student.h"

#include <iostream>
#include <string>

using namespace std;

Student::Student(int id, string name)
    : id(id), issuedBook(nullptr), User(name) {}

bool Student::hasIssuedBook() { return issuedBook; }

int Student::getId() { return id; }

Book* Student::getIssuedBook() { return issuedBook; }

void Student::userDetails() {
  cout << "-----------------------------" << endl;
  cout << "ID: " << id << ", Name: " << name << endl;
  if (issuedBook) {
    cout << "Issued book: ";
    issuedBook->getBookDetails();
  } else {
    cout << "Noissued book" << endl;
  };
}

void Student::issueBook(Book* book) { issuedBook = book; }

void Student::returnBook() { issuedBook = nullptr; }

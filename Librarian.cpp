#include "./include/Librarian.h"

#include <iostream>
#include <string>
using namespace std;

Librarian::Librarian(string name, string password)
    : password(password), User(name) {}

// Default constr
Librarian::Librarian() : password("admin"), User("admin") {}

bool Librarian::authenticate(const string& name, const string& password) {
  if (this->password == password && this->name == name) {
    cout << "Authenticated" << endl;
    return true;
  }
  return false;
}

void Librarian::registerStudent(Library& library, string name) {
  library.registerStudent(name);
}

void Librarian::addBook(Library& library, string title) {
  library.addBook(title);
}

void Librarian::issueBook(Library& library, int studentId, int bookId) {
  library.issueBook(studentId, bookId);
}

void Librarian::returnBook(Library& library, int studentId, int bookId) {
  library.returnBook(studentId, bookId);
}

void Librarian::rateBook(Library& library, int bookId, int rate) {
  library.rateBook(bookId, rate);
}

void Librarian::getStudents(Library& library) { library.getStudents(); }

void Librarian::userDetails() {
  cout << "------------------" << endl;
  cout << "Admin name: " << name << endl;
}

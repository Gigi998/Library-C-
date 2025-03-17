#include "./include/Library.h"

#include <iostream>
#include <string>
using namespace std;

// PRIVATE
// FindMember and Findbook are pointers becaouse they can be nullPtr if there
// is no record
Student* Library::findStudent(int& studentId) {
  for (Student& student : students) {
    if (student.getId() == studentId) {
      return &student;
    }
  }
  return nullptr;
}

Book* Library::findBook(int& bookId) {
  for (Book& book : books) {
    if (book.getId() == bookId) {
      return &book;
    }
  }
  return nullptr;
}

// When this function finish it will call destruct
void Library::addBook(string& title) {
  // This will trigger copy constructor call
  books.push_back(Book(books.size() + 1, title));
  cout << "Book added: " << title << endl;
}

void Library::registerStudent(string& name) {
  students.push_back(Student(students.size() + 1, name));
  cout << "Student added: " << name << endl;
}

void Library::issueBook(int& studentId, int& bookId) {
  Student* student = findStudent(studentId);
  Book* book = findBook(bookId);

  if (!book || !student) {
    cout << "Wrong student or book id, item not found" << endl;
    return;
  }

  if (student->hasIssuedBook()) {
    cout << "Student already has borrowed a book" << endl;
    return;
  }

  if (book->getBookIssueStatus()) {
    cout << "Book is already borrowed buy someone else" << endl;
    return;
  }

  book->issueBook();
  student->issueBook(*book);
  cout << "Book issued" << endl;
}

void Library::returnBook(int& studentId, int& bookId) {
  Student* student = findStudent(studentId);
  Book* book = findBook(bookId);

  if (!book || !student) {
    cout << "Wrong student or book id, item not found" << endl;
    return;
  }

  if (!student->hasIssuedBook()) {
    cout << "Student hasn't issued any book" << endl;
    return;
  }

  if (!book->getBookIssueStatus()) {
    cout << "Book is not issued" << endl;
    return;
  }

  if (book != student->getIssuedBook()) {
    cout << "Issued student book and sent book hasn't match" << endl;
    return;
  }

  book->returnBook();
  student->returnBook();
  cout << "Book returned" << endl;
  return;
}

void Library::rateBook(int& bookId, int& rate) {
  Book* book = findBook(bookId);

  if (!book) {
    cout << "Wrong book id, book not found" << endl;
    return;
  }

  book->rateBook(rate);
  cout << "Book rated with: " << rate << endl;
}

void Library::getStudents() {
  cout << "STUDENTS" << endl;
  for (Student& student : students) {
    student.userDetails();
  }
}

// PUBLIC
void Library::getAllBooks() {
  cout << "BOOKS" << endl;
  for (Book& book : books) {
    book.getBookDetails();
  }
}

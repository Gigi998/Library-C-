#include <iostream>
#include <vector>

using namespace std;

#include "./Student.h"

class Library {
 private:
  vector<Student> students;
  vector<Book> books;

  // FindStudent and Findbook are pointers becaouse they can be nullPtr if there
  // is no record
  Student* findStudent(int studentId);

  Book* findBook(int bookId);

  void addBook(string& title);

  void registerStudent(string& name);

  void issueBook(int studentId, int bookId);

  void returnBook(int studentId, int bookId);

  void getStudents();

  void rateBook(int bookId, int rate);

 public:
  void getAllBooks();

  friend class Librarian;
};
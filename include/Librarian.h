#include <iostream>
#include <vector>

#include "./Library.h"

using namespace std;

class Librarian : public User {
 private:
  string password;

 public:
  Librarian(string name, string password);

  // Default constr
  Librarian();

  bool authenticate(const string& name, const string& password);

  void registerStudent(Library& library, string name);

  void addBook(Library& library, string title);

  void issueBook(Library& library, int studentId, int bookId);

  void returnBook(Library& library, int studentId, int bookId);

  void getStudents(Library& library);

  void userDetails();
};
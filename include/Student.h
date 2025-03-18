#include <iostream>
#include <string>

#include "./Book.h"
#include "./User.h"

using namespace std;

class Student : public User {
 private:
  int id;
  // It is pointer and not a reference, becaouse it can be reassigned and can
  // be null
  Book* issuedBook;

 public:
  Student(int id, string name);

  bool hasIssuedBook();

  int getId();

  Book* getIssuedBook();

  void userDetails();

  void issueBook(Book* book);

  void returnBook();
};
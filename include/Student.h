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

  // Here we are expecting reference becaouse we want valid book value,
  // reference must be valid object
  void issueBook(Book& book);

  void returnBook();
};
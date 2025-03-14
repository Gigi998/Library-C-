#include <iostream>
#include <string>

using namespace std;

class Book {
 private:
  int id;
  string title;
  bool isIssued;

 public:
  Book(int id, string title);

  int getId() const;
  bool getBookIssueStatus() const;
  void getBookDetails();

  void issueBook();
  void returnBook();
};
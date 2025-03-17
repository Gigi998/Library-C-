#include <iostream>
#include <string>

using namespace std;

class Book {
 private:
  int id;
  string title;
  bool isIssued;
  int ratesCounter;
  int* rates;

  float getAvarageRate();

 public:
  Book(int id, string title);

  // Destructor
  ~Book();

  // Copy constr
  Book(const Book& original);

  int getId() const;
  bool getBookIssueStatus() const;
  void getBookDetails();

  void issueBook();
  void returnBook();

  void rateBook(int rate);
};
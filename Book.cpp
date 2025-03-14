#include "./include/Book.h"

#include <iostream>
#include <string>

using namespace std;

Book::Book(int id, string title) : id(id), title(title), isIssued(false) {}

int Book::getId() const { return id; }

bool Book::getBookIssueStatus() const { return isIssued; }

void Book::getBookDetails() {
  cout << "ID: " << getId() << ", Title: " << title
       << ", Isissued: " << isIssued << endl;
}

void Book::issueBook() { isIssued = true; }
void Book::returnBook() { isIssued = false; }

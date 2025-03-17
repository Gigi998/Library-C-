#include "./include/Book.h"

#include <iostream>
#include <string>

using namespace std;

Book::Book(int id, string title) {
  this->id = id;
  this->title = title;
  this->isIssued = false;
  this->ratesCounter = 3;
  this->rates = new int[ratesCounter];
  rates[0] = 11;
  rates[1] = 24;
  rates[2] = 33;
}
// Destruct
Book::~Book() {
  delete[] rates;
  rates = nullptr;
  cout << "Destruct" << endl;
}

// // Copy constr
Book::Book(const Book& original) {
  this->id = original.id;
  this->title = original.title;
  this->isIssued = false;
  this->ratesCounter = original.ratesCounter;
  // Must create new dynamic array
  this->rates = new int[ratesCounter];
  for (int i = 0; i < ratesCounter; i++) {
    rates[i] = original.rates[i];
  }
  cout << "copy construct" << endl;
}

float Book::getAvarageRate() {
  int sum = 0;
  for (int i = 0; i < ratesCounter; i++) {
    sum += rates[i];
  }

  float avgSum = sum / ratesCounter;
  return avgSum;
}

int Book::getId() const { return id; }

bool Book::getBookIssueStatus() const { return isIssued; }

void Book::getBookDetails() {
  cout << "ID: " << getId() << ", Title: " << title
       << ", Isissued: " << isIssued << ", Avarage rate: " << getAvarageRate()
       << endl;
}

void Book::issueBook() { isIssued = true; }
void Book::returnBook() { isIssued = false; }

void Book::rateBook(int& rate) {
  ratesCounter += 1;
  rates[ratesCounter] = rate;
}

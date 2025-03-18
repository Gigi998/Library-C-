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
  rates[0] = 10;
  rates[1] = 20;
  rates[2] = 30;
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
    // Another way of dereferencing array values
    sum += *(rates + i);
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

void Book::rateBook(int newRate) {
  int* newRates =
      new int[ratesCounter + 1];  // Crete new array with extra space
  for (int i = 0; i < ratesCounter; i++) {
    newRates[i] = *(rates + i);  // Copy existing values
  }

  newRates[ratesCounter] = newRate;  // Add new rate

  delete[] rates;  // delete old rate

  rates = newRates;  // asign newRates to rates

  ratesCounter++;  // increase count
}

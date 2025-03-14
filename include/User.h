#include <iostream>
#include <string>

using namespace std;

class User {
 protected:
  string name;

 public:
  User(string name);

  virtual void userDetails() = 0;
};
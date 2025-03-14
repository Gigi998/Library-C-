#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Plan
// 1. Classes: Book, Student, Library, Librarian
class Book {
 private:
  int id;
  string title;
  bool isIssued;

 public:
  Book(int id, string title) : id(id), title(title), isIssued(false) {}

  int getId() const { return id; }

  bool getBookIssueStatus() const { return isIssued; };

  void getBookDetails() {
    cout << "ID: " << getId() << ", Title: " << title
         << ", Isissued: " << isIssued << endl;
  }

  void issueBook() { isIssued = true; }
  void returnBook() { isIssued = false; }
};

class User {
 protected:
  string name;

 public:
  User(string name) : name(name) {}

  virtual void userDetails() = 0;
};

class Student : public User {
 private:
  int id;
  // It is pointer and not a reference, becaouse it can be reassigned and can be
  // null
  Book* issuedBook;

 public:
  Student(int id, string name) : id(id), issuedBook(nullptr), User(name) {}

  bool hasIssuedBook() { return issuedBook; }

  int getId() { return id; }

  Book* getIssuedBook() { return issuedBook; }

  void userDetails() {
    cout << "-----------------------------" << endl;
    cout << "ID: " << id << ", Name: " << name << endl;
    if (issuedBook) {
      cout << "Issued book: ";
      issuedBook->getBookDetails();
    } else {
      cout << "Noissued book" << endl;
    };
  }

  // Here we are expecting reference becaouse we want valid book value,
  // reference must be valid object
  void issueBook(Book& book) { issuedBook = &book; }

  void returnBook() { issuedBook = nullptr; }
};

class Library {
 private:
  vector<Student> students;
  vector<Book> books;

  // FindMember and Findbook are pointers becaouse they can be nullPtr if there
  // is no record
  Student* findStudent(int& studentId) {
    for (Student& student : students) {
      if (student.getId() == studentId) {
        return &student;
      }
    }
    return nullptr;
  }

  Book* findBook(int& bookId) {
    for (Book& book : books) {
      if (book.getId() == bookId) {
        return &book;
      }
    }
    return nullptr;
  }

  void addBook(string& title) {
    books.push_back(Book(books.size() + 1, title));
    cout << "Book added: " << title << endl;
  }

  void registerStudent(string& name) {
    students.push_back(Student(students.size() + 1, name));
    cout << "Student added: " << name << endl;
  }

  void issueBook(int& studentId, int& bookId) {
    Student* student = findStudent(studentId);
    Book* book = findBook(bookId);

    if (!book || !student) {
      cout << "Wrong student or book id, item not found" << endl;
      return;
    }

    if (student->hasIssuedBook()) {
      cout << "Student already has borrowed a book" << endl;
      return;
    }

    if (book->getBookIssueStatus()) {
      cout << "Book is already borrowed buy someone else" << endl;
      return;
    }

    book->issueBook();
    student->issueBook(*book);
    cout << "Book issued" << endl;
  }

  void returnBook(int& studentId, int& bookId) {
    Student* student = findStudent(studentId);
    Book* book = findBook(bookId);

    if (!book || !student) {
      cout << "Wrong student or book id, item not found" << endl;
      return;
    }

    if (!student->hasIssuedBook()) {
      cout << "Student hasn't issued any book" << endl;
      return;
    }

    if (!book->getBookIssueStatus()) {
      cout << "Book is not issued" << endl;
      return;
    }

    if (book != student->getIssuedBook()) {
      cout << "Issued student book and sent book hasn't match" << endl;
      return;
    }

    book->returnBook();
    student->returnBook();
    cout << "Book returned" << endl;
    return;
  }

  void getStudents() {
    cout << "STUDENTS" << endl;
    for (Student& student : students) {
      student.userDetails();
    }
  }

 public:
  void getAllBooks() {
    cout << "BOOKS" << endl;
    for (Book& book : books) {
      book.getBookDetails();
    }
  };

  friend class Librarian;
};

class Librarian : public User {
 private:
  string password;

 public:
  Librarian(string name, string password) : password(password), User(name) {}

  bool authenticate(const string& name, const string& password) {
    if (this->password == password && this->name == name) {
      cout << "Authenticated" << endl;
      return true;
    }
    return false;
  }

  void registerStudent(Library& library, string name) {
    library.registerStudent(name);
  }

  void addBook(Library& library, string title) { library.addBook(title); }

  void issueBook(Library& library, int studentId, int bookId) {
    library.issueBook(studentId, bookId);
  }

  void returnBook(Library& library, int studentId, int bookId) {
    library.returnBook(studentId, bookId);
  }

  void getStudents(Library& library) { library.getStudents(); }

  void userDetails() {
    cout << "------------------" << endl;
    cout << "Admin name: " << name << endl;
  }
};

void showMenu() {
  cout << "\n📚 Library Management System 📚\n";
  cout << "--------------------------------\n";
  cout << "1️⃣ Register Student\n";
  cout << "2️⃣ Add Book\n";
  cout << "3️⃣ Issue Book\n";
  cout << "4️⃣ Return Book\n";
  cout << "5️⃣ View All Books\n";
  cout << "6️⃣ View Students\n";
  cout << "--------------------------------\n";
  cout << "Choose an option: ";
}

void authForm(string& name, string& password) {
  cout << "Enter user name: ";
  cin >> name;

  cout << "Enter password: ";
  cin >> password;
}

int main() {
  Library myLibrary;

  Librarian librarian("admin", "admin");
  string name, password;

  authForm(name, password);

  if (!librarian.authenticate(name, password)) {
    cout << "Wrong email or password!!" << endl;
    authForm(name, password);
  }

  librarian.userDetails();

  while (true) {
    showMenu();
    int choice = 0;
    cin >> choice;
    cin.ignore();

    string bookTitle, studentName;
    int studentId, bookId;

    switch (choice) {
      case 1:
        cout << "Enter student name: ";
        cin >> studentName;
        librarian.registerStudent(myLibrary, studentName);
        break;
      case 2:
        cout << "Enter book title: ";
        getline(cin, bookTitle);
        librarian.addBook(myLibrary, bookTitle);
        break;
      case 3:
        cout << "Enter student Id: ";
        cin >> studentId;
        cout << "Enter the book Id: ";
        cin >> bookId;
        librarian.issueBook(myLibrary, studentId, bookId);
        break;
      case 4:
        cout << "Enter student Id: ";
        cin >> studentId;
        cout << "Enter the book Id: ";
        cin >> bookId;
        librarian.returnBook(myLibrary, studentId, bookId);
        break;
      case 5:
        myLibrary.getAllBooks();
        break;
      case 6:
        librarian.getStudents(myLibrary);
        break;
      default:
        cout << "Selected option invalid";
        break;
    }
  }
  return 0;
}
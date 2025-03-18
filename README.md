# **Library Management Project**

This project is designed to help understand and apply key **C++ concepts**, including:

- **Pointers**
- **Dynamic Arrays**
- **OOP Principles** (Encapsulation, Inheritance, Polymorphism)
- **Copy Constructor & Destructor**
- **Virtual & Pure Virtual Functions**
- **Memory Management & Leak Prevention**
- **Valgrind Leak Detection**

## **Features**

- Registering new students
- Adding new books
- Issuing books to students
- Returning books
- Rating books

## **Initial Login Credentials**

- **Username:** `admin`
- **Password:** `admin`

## **Project Structure**

The project is divided into several classes:

- **Book** – Represents a book, including details like title, author, and rating.
- **User** – A base class representing system users.
- **Student** – A derived class from `User`, representing students who can borrow books.
- **Library** – The **core manager class**, responsible for handling book creation, student registration, book issuing, and returns.
- **Librarian** – The **interface to the library**, ensuring that only librarians can perform administrative tasks.

The **Library** class contains the main business logic, while the **Librarian** class acts as a controller, calling library methods to perform actions.

This project provides hands-on experience in **object-oriented design, memory management, and best coding practices** in C++.

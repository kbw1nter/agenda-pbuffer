# 📒 Contact List (pBuffer)

A simple contact list manager written in C using **a single dynamic memory allocation** and **no declared variables**, other than the `pBuffer`.

## 📋 Description

**Contact List (pBuffer)** is a menu-driven program that allows users to manage a list of contacts — including name, age, and email — using only one dynamically allocated memory buffer (`pBuffer`). The project was developed with strict constraints:

* ❌ No declared variables (other than the `pBuffer` pointer).
* ✅ Only **one call to `malloc`** throughout the entire program (with occasional `realloc`).
* ✅ All logic handled via **pointer arithmetic**.

This project serves as a unique challenge in manual memory management and low-level programming in C.

## 🎮 How It Works

1. The program starts by allocating a `pBuffer` that holds:

   * Three integers:

     * Counter for number of people
     * Menu option
     * Utility variable (e.g. for loop/search)
   * Temporary areas:

     * 50 bytes for name input
     * 50 bytes for email input
2. The user can:

   * Add contacts (name, age, email)
   * Remove contacts by name
   * Search for contacts
   * List all contacts
   * Exit the program
3. Each contact is stored in the buffer as:

   * 50 bytes for name
   * 4 bytes for age
   * 50 bytes for email
4. Memory is reallocated dynamically as contacts are added or removed.

## 🏗️ Project Structure

The project contains a single source file:

```
ContactList/
└── agenda_pbufferf.c  # All logic and data in one file and one buffer
```

### agenda\_pbufferf.c

* Main program logic and loop.
* All data is handled through `pBuffer` using casting and offset calculations.
* Uses `fgets`, `scanf`, `strcpy`, `strcmp`, and `memcpy` to handle strings and memory.

## 🚀 How to Run

1. **Compile the program:**

   ```bash
   gcc agenda_pbufferf.c -o agenda
   ```

2. **Run the program:**

   ```bash
   ./agenda
   ```

## 💻 Sample Output

```
+==========================================+
|             CONTACT LIST                 |
+==========================================+
|  1 - Add New Person                      |
|  2 - Remove Existing Person              |
|  3 - Search for Specific Person          |
|  4 - View All People                     |
|  5 - Exit Program                        |
+==========================================+
Your choice: 1

=== ADDING NEW PERSON ===
Enter full name: Alice Johnson
Enter age: 29
Enter email: alice@example.com
Success! Person added. Total: 1 person(s)
```

## 🎲 Features

* **Single malloc**: All memory management is done with one `malloc` and `realloc`.
* **Zero declared variables**: All data is stored in the buffer.
* **Manual memory layout**: Contact information is managed via offset calculations.
* **Dynamic contact list**: Memory expands/shrinks based on the number of people.
* **Functional menu**: Add, remove, search, list, and exit options.

## 🛠️ Technologies Used

* **C Language**
* **Standard C Libraries**:

  * `<stdio.h>`: Input/output
  * `<stdlib.h>`: Memory management
  * `<string.h>`: String manipulation
* **Pointer Arithmetic**: Core technique for accessing and organizing memory
* **Dynamic Allocation**: Using `malloc`, `realloc`, and `free`

## 📝 Possible Improvements (Future Updates)

* Use `structs` to simplify memory handling.
* Add file persistence (save/load).
* Alphabetical sorting of contacts.
* Support for multiple fields (e.g., phone, address).
* GUI or text-based interface using libraries like `ncurses`.

## 👩‍💻 Author

Developed as a memory management challenge in C programming, demonstrating what can be done with no variables, structs and just a single `malloc`.

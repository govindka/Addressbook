
📇 Address Book Management System (C Project)

A simple and efficient Address Book Management System written in C, designed to manage contacts directly from the terminal.
You can create, search, edit, delete, and list contacts — with data automatically saved to a file.

🚀 Features

➕ Add new contacts with name, phone, and email

🔍 Search contacts by name, phone, or email

✏️ Edit contacts easily

❌ Delete contacts from the list

📜 List all saved contacts

✅ Input validation

Phone: must be 10 digits and unique

Email: must include @, end with .com, and be unique

💾 File handling

Loads contacts automatically at startup

Saves all contacts before exit

🧪 Preloaded dummy data for quick testing (populate.c)

🧩 File Overview
File	Description
main.c	Main menu and program entry point
contact.c	Core logic for managing contacts
contact.h	Structure definitions and function prototypes
file.h	File I/O function prototypes
populate.c	Preloaded sample contacts for testing

📂 Example Menu
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save contacts
7. Exit

🧠 Concepts Used

Structures in C

Pointers & arrays

File handling

String manipulation

Input validation

Modular programming

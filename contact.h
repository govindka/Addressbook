#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void edit(AddressBook *addressBook,int);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);
int validate_phone(char * ,AddressBook *addressBook);
int validate_email(char * ,AddressBook *addressBook);
void search_name(AddressBook *addressBook);
void search_phone(AddressBook *addressBook);
void search_email(AddressBook *addressBook);
//void edit_name(AddressBook *addressBook,int,int *);
//void edit_phone(AddressBook *addressBook,int);
//void edit_email(AddressBook *addressBook,int);
#endif

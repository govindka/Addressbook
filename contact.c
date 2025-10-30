#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>
int array[50];
int count = 0;
int flag;

void listContacts(AddressBook *addressBook)
{
    // Sort contacts based on the chosen criteria
    for(int i = 1 ; i <= (addressBook->contactCount) ; i++)
    {
            printf("%d\t%s\t%s\t%s \n",i,addressBook->contacts[i-1].name , addressBook->contacts[i-1].phone , addressBook->contacts[i-1].email);
    }

}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
     //Load contacts from file during initialization (After files)
     loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
        /* Define the logic to create a Contacts */
        printf("Enter name : ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);    //storing name
        char ph[20];
label1: printf("Enter phone number : ");
        scanf(" %s",ph);
        if((validate_phone(ph,addressBook)) == 0)
                goto label1;
        strcpy(addressBook->contacts[addressBook->contactCount].phone,ph);      //storing number
        char em[50];
label2: printf("Enter email : ");
        scanf("%s",em);
        if(validate_email(em ,addressBook) == 0)
                goto label2;
        strcpy(addressBook->contacts[addressBook->contactCount].email,em);     //storing email
        addressBook->contactCount++;

}
int validate_phone(char *ph , AddressBook *addressBook)
{
        int a = strlen(ph);
        if(a != 10)
        {
                printf("Not 10 digits\n");
                return 0;
        }
        for(int i = 0 ; i < a ; i++)
        {
                if(ph[i] <= 47 || ph[i] >=58)   //checking if digits only
                {
                        printf("Enter only digits\n");
                        return 0;
                }
        }
        for(int i = 0; i < (addressBook->contactCount) ; i++)
        {
                int d = strcmp(ph,addressBook->contacts[i].phone);    //checking if number is duplicate
                if(d == 0)
                {
                        printf("phone number already exits\n");
                        return 0;
                }
        }
        return 1;
}
int validate_email(char *em ,AddressBook *addressBook)
{
        if(strchr(em,'@') == NULL)                          //checking if @ is present
        {
                printf("Email should contain @\n");
                return 0;
        }
        char *a = strstr(em,".com");                       //checking if .com is present
        if(a == NULL)
        {
                printf("Email should contain .com\n");
                return 0;
        }
        if(strcmp(a,".com") != 0)
        {
                printf("Email should end with .com\n");
                return 0;
        }
        char * b = strchr(em,'@');
        if((*(b+1)) < 48 || (*(b+1)) > 57 && (*(b+1)) < 65 || (*(b+1)) > 90 && (*(b+1)) < 47 || (*(b+1)) > 122 )
        {
                printf("There should be a alpha numeric chara after @\n");
                return 0;
        }
        if((*(b-1)) < 48 || (*(b-1)) > 57 && (*(b-1)) < 65 || (*(b-1)) > 90 && (*(b-1)) < 47 || (*(b-1)) > 122 )
        {
                printf("There should be a alpha numeric chara before @\n");
                return 0;
        }

        int n = strlen(em);
        for(int i = 0 ; i < n ; i++)
        {
                if(em[i] >= 65 && em[i] <= 90)      //checking if capital is there or not
                {
                        printf("Email should not contain capital\n");
                        return 0;
                }
        }
        if(em[0] == '@' || em[n] == '@')
        {
                printf("Email should not start with @\n");
                return 0;
        }
        for(int i = 0; i < (addressBook->contactCount) ; i++)
        {
                int d = strcmp(em,addressBook->contacts[i].email);
                if(d == 0)
                {
                        printf("Enter unique email id\n");
                        return 0;
                }
        }
        return 1;
}



void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
      int a;
      printf("Enter choice : \n 1. Search by name \n 2. Search by phone number \n 3. Search by email \n 4. Exit\n");
      scanf("%d",&a);
      switch(a)
      {
        case 1 : 
                search_name(addressBook);
                break;

        case 2 : 
                search_phone(addressBook);
                break;
        case 3 :
                search_email(addressBook);
                break;
	case 4 : return;	 //the function will end if 4 is pressed
      }
}


void search_name(AddressBook *addressBook)
{
    count = 0;
    char names[30];
    printf("Enter the name to search:\n");
    scanf(" %[^\n]",names);
    flag = 0 ;
    for(int i = 0 ; i < addressBook -> contactCount ; i++ )
    {
        if(strcmp(names , addressBook->contacts[i].name) == 0)
        {
            array[count++] = i; 
            printf("%d\t\t%s\t\t%s\t\t%s\n" , count , addressBook->contacts[i].name , addressBook->contacts[i].phone , addressBook->contacts[i].email);
            flag =1;
        }
    }
    if(flag == 0)
    {
        printf("Entered name is not found\n");
    }
}




void search_phone(AddressBook *addressBook)
{
    count = 0;
    char phones[30];
    printf("Enter the phone number to search :\n");
    scanf(" %[^\n]",phones);
    flag = 0 ;
    for(int i = 0 ; i < addressBook -> contactCount ; i++ )
    {
        if(strcmp(phones , addressBook->contacts[i].phone) == 0)
        {
            array[count++] = i;
            printf("Contact Found \n%d\t\t%s\t\t%s\t\t%s\n" , count , addressBook->contacts[i].name , addressBook->contacts[i].phone , addressBook->contacts[i].email);
            flag =1;

        }
      
    }
    if(flag == 0)
    {
        printf("Entered phone number is not found\n");
    }
}



void search_email(AddressBook *addressBook)
{
    count = 0;
    char emails[30];
    printf("Enter the email id to search :\n");
    scanf(" %[^\n]",emails);
    for(int i = 0 ; i < addressBook -> contactCount ; i++ )
    {
        if(strcmp(emails , addressBook->contacts[i].email) == 0)
        {
            array[count++] = i;
            printf("Contact Found \n%d\t\t%s\t\t%s\t\t%s\n" , count , addressBook->contacts[i].name , addressBook->contacts[i].phone , addressBook->contacts[i].email);
            flag =1;
        }
    }
    if(flag == 0)
    {
        printf("Entered Email ID is not found\n");
    }
}






void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
      count = 0 ;
      int option;
      label:
      printf("Enter choice : \n 1. Search by name \n 2. Search by phone number \n 3. Search by email \n 4. Exit\n");
      scanf("%d",&option);
      switch(option)
      {
        case 1 : 
                search_name(addressBook);
                break;
        case 2 : 
                search_phone(addressBook);
                break;
        case 3 :
                search_email(addressBook);
                break; 
        case 4 :
                return;
        default :
                printf("Invalid option\n");
                goto label;
      }    
      if(count == 0)
	      goto label;    //no contact found . So asking to enter choice again
      if(flag == 1)
      {
        int a;
        if(count > 1)
         {
        ab :printf("Which contact do you want to edit ? \n");
           scanf("%d",&a);
	   if(a > count || a < 1)          //checking is user entered i/p is greater than the no of contacts with same attribute
	   {
		   printf("Invalid input\n");
		   goto ab;
	   }
           edit(addressBook , a - 1 );  //passig a - 1 since index is always Sl - 1
         }
        else
         {
           edit(addressBook , count - 1 );
         }
     
    }

}

void edit(AddressBook *addressBook,int count)
{	
    int choice;
    char new[50];
 do
 {
 
    printf("Which parameter you want to edit\n1.Name\n2.Phone number\n3.Email id\n4.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 : 
                printf("Enter new name : ");
                scanf(" %[^\n]",new);
                strcpy(addressBook -> contacts[array[count]].name , new);   //entering name into addressbook
		printf("Name updated !!\n");
                break;
        case 2 :
               numm: printf("Enter new number : ");
                    scanf(" %[^\n]",new);
		    if( ( validate_phone(new , addressBook)) == 1)
                    {	
			    strcpy(addressBook -> contacts[array[count]].phone , new);   //entering number into addressbook
		    }
		    else 
			    goto numm;
		printf("Number updated !!\n");
                break;
                 
        case 3 :
             emm:printf("Enter new email id : ");
                 scanf(" %[^\n]",new);
                if( ( validate_email(new , addressBook)) == 1)
                	strcpy(addressBook -> contacts[array[count]].email, new);     //entering email into addressbook
		else
			goto emm;
		printf("Email updated !!\n");
                break;        
        case 4 :
                editContact(addressBook);
                break;  
        default :
                printf("Invalid choice\n");

    }
}while(choice != 4);
}



void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
      count = 0 ;
      int option , a;
      char ch;
      label:
      printf("Enter choice : \n 1. Search by name \n 2. Search by phone number \n 3. Search by email \n 4. Exit\n");
      scanf("%d",&option);
      switch(option)
      {
        case 1 : 
                search_name(addressBook);
                break;
        case 2 : 
                search_phone(addressBook);
                break;
        case 3 :
                search_email(addressBook);
                break; 
        case 4 :
                return;
        default :
                printf("Invalid option\n");
      }
      if(count == 0)
      {
        goto label;
      }
      if(count == 1)
      {
        a = 1 ;
      }
      else
      {
        printf("Enter the serial number you want to delete : ");
        scanf("%d",&a);
      }
    if(flag == 1)
again :
    {  printf("Are you sure want to delete this contact (y/n)\n");
        scanf(" %[^\n]",&ch);

        switch(ch)
     {
        case 'y':
                for(int i = array[a - 1] ; i < addressBook -> contactCount ; i++)
                {
                    strcpy(addressBook -> contacts[i].name , addressBook -> contacts[i+1].name);
                    strcpy(addressBook -> contacts[i].phone , addressBook -> contacts[i+1].phone);
                    strcpy(addressBook -> contacts[i].email , addressBook -> contacts[i+1].email);

                }
                addressBook -> contactCount--; 
                printf("\nContact deleted successfully\n");

        case 'n' :
                 goto label;
        default :
                  printf("Invalid choice \n");
                  goto again;
                 
                 

      }
    }
}

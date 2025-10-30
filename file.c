#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
	FILE *fp = fopen("contacts.csv","w");
	fprintf(fp,"%d\n",addressBook->contactCount);
	for(int  i= 0 ; i < addressBook->contactCount ; i++)
	{
		fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name , addressBook->contacts[i].phone , addressBook->contacts[i].email);
	}
	fclose(fp);	
}

void loadContactsFromFile(AddressBook *addressBook) 
{
	FILE *fp = fopen("contacts.csv","r");
	fscanf(fp,"%d\n",&addressBook->contactCount);
	for(int i = 0 ; i < addressBook->contactCount; i++)
	{
		fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name , addressBook->contacts[i].phone , addressBook->contacts[i].email);
	}	

}

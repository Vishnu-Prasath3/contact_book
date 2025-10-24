#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria)
{
    // Sort contacts based on the chosen criteria
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
    // loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

void createContact(AddressBook *addressBook){
    /* Define the logic to create a Contacts */

    char str[100];
    do{
        printf("Enter the name");
        
    }while(name_validation(str));
    

    
}

void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
}

void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
}

void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
}

int name_validation(char str[])
{scanf("%[^\n]",str);
    
    int i = 0;
    while (str[i] != "\0")
    {
        if ((str[i] >='a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'));
        else
        {
            return 1;
        }
        i++;
    }
return 0;

}

void phone_number_validation()
{


}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "validation.h"
#include "find.h"
#include "delete.h"
#include "edit.h"

// copy character by character
void string_copy(char *desti, char *source)
{

    // copy until null character
    while (*source != '\0')
    {

        // source string to destination string
        *desti = *source;

        // increment both pointers
        desti++;

        // increment source pointer
        source++;
    }

    // null terminate the destination string
    *desti = '\0';
}

// !string coparison function
int string_cmp(char *stringone, char *stringtwo)
{
    // compare both strings has same length
    if (strlen(stringone) != strlen(stringtwo))
    {
        return 0;
    }

    // both has same size ==> compare letter by letter

    int found = 0;

    // iterate through the string
    for (int i = 0; i < strlen(stringone); i++)
    {

        // compare each character
        if (stringone[i] != stringtwo[i])
        {
            return 0;
        }
    }

    // return 1 means strings are identical
    return 1;
}

// !list all contacts
void listContacts(AddressBook *addressBook)
{
    // Sort contacts based on the chosen criteria
    int count = addressBook->contactCount;

    // print all contacts
    int i = 0;

    // iterate through all contacts
    while (i < count)
    {
        // print the contact details
        print(i, addressBook);

        // increment i
        i++;

        printf("\n");
    }
}

// ! initialize address book
void initialize(AddressBook *addressBook)
{
    // set contact count to zero
    addressBook->contactCount = 0;
    // populate with dummy data
    populateAddressBook(addressBook);

    //  Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

// ! save and exit function
void saveAndExit(AddressBook *addressBook)
{
    // Save contacts to file
    saveContactsToFile(addressBook);

    exit(EXIT_SUCCESS); // Exit the program
}

// ! create contact function
void createContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */
    int count = addressBook->contactCount;

    name_validation(addressBook); // name validation function call

    phone_validation(addressBook); // phone number validation function call

    mail_validation(addressBook); // check wheather (@) and (.) symbol present in the gmail

    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    int choice;

    do{
        printf("\n enter you choice \n 1)Name \n 2)phone number\n 3)Mail id \n 4)Exit \n|--🙂--|\n ");

        // get user choice
        scanf("%d", &choice);

        // clear the buffer
        getchar();

        // check for valid input
        if ((int)choice > 0 && (int)choice <= 4)
        {

            break;
        }

        // invalid input message
        printf("\nInvalid input ⛔⛔⛔⛔\n");

    }while(choice >= 3 || choice <= 0);

    char str[100];

    // switch case for user choice
    switch (choice)
    {
        // find by number
    case 1:
    {
        // validate name function call
        find_name(addressBook);
        break;
    }
    // find using phone number
    case 2:
    {
        // validate number function call
        find_number(addressBook);
        break;

    }

        // check by mail -id
    case 3:
        // validate mail function call
        find_email(addressBook);
        break;

    case 4:

        // exit from the case
        break;

    default:

        printf("Entered value is not in choice");

        // recursive call
        searchContact(addressBook);
        break;

    }
}

// ! edit contact function
void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */

    int choice, ret;

    
    while (1)
    {
        printf("Enter the choice to edit\n 1.Edit by name \n 2. Edit by number \n 3.Edit By Email\n");

        char str[100];

        // get user choice
        ret = scanf("%d", &choice);

        if (ret == 1)
        {
            break;
        }
    }

    switch (choice)
    {
        // case 1: if user selected edit by name
    case 1:

        // validate name function call
        edit_by_name(addressBook);

        break;

        // case 2: if user entered edit by number jump
    case 2:

        // validate number function call
        edit_by_number(addressBook);

        break;

    case 3:

        // validate email function call
        edit_by_email(addressBook);

        break;

        // exit from the case
    case 4:

        break;

    default:
        printf("Entered value is not in choice"); // recursive call
        while (choice >= 3)  ; // loop until valid choice
    }
    // validate_name(str1);
}

// ! delete by number

void deleteContact(AddressBook *addressBook)
{
    char str1[50], str2[50];

    int choice; // user choice

    do
    {
        printf("Enter the choice to delete\n 1.delete by name \n 2. delete by number \n 3.delete By Email\n");

        char str[100];

        // get user choice
        getchar(); // clear the buffer
        int ret = scanf("%d", &choice);

        if (ret == 1) // valid input
            break;

    } while (1); // infinite loop until valid input

    switch (choice)
    {
        // case 1: if user selected edit by name
    case 1:
    {

        if (addressBook->contactCount == 0) // check for empty address book
        {

            printf("\nAddressBook is empty");
            break;
        }
        delete_by_name(addressBook); // delete by name function call

        break;
    }
        // case 2: if user entered edit by number jump
    case 2:

        if (addressBook->contactCount == 0) // check for empty address book
        {
            printf("\nAddressBook is empty");
            break;
        }
        delete_by_number(addressBook); // delete by number function call

        break;

        // case 3: if user  edit by email
    case 3:

        if (addressBook->contactCount == 0) // check for empty address book
        {
            printf("\nAddressBook is empty");
            break;
        }
        delete_by_email(addressBook); // delete by email function call

        break;

    case 4:
        // exit from the case
        break;

    default:
        printf("Entered value is not in choice"); // recursive call
        while (choice >= 3);
    }
    // validate_name(str1);
}

void print(int i, AddressBook *addressBook)
{

    printf("\nThe name is %s\n ", addressBook->contacts[i].name);

    printf("The number is %s\n ", addressBook->contacts[i].phone);

    printf("The Email id is %s\n ", addressBook->contacts[i].email);

    return;
}

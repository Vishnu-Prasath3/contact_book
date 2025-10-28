#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "validation.h"


void listContacts(AddressBook *addressBook, int sortCriteria)
{
    // Sort contacts based on the chosen criteria
    
    int count = addressBook->contactCount;
    int i=0;
    while(i<count){
        
        printf(" name : %s\n",addressBook->contacts[i].name);
        printf(" phone : %s\n",addressBook->contacts[i].phone);
        printf(" email : %s\n",addressBook->contacts[i].email);
        i++;
        printf("\n");
    }

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
    int count = addressBook->contactCount;
    name_validation(addressBook,count);
    phone_validation(addressBook,count);
    mail_validation(addressBook,count);    
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    int choice;

    printf("\n enter you choice \n 1)Name \n 2)phone number\n 3)Mail id \n 4)Exit \n|||||||||||||||\n ");
    scanf("%d",&choice);
    
    char str[100];

    switch (choice)
    {
        //find by number
    case  1:
        {
            find_name(addressBook);
            break;
        }
    //find using phone number
    case 2:
    {
        find_number(addressBook);
        break;   
    }

    // check by mail -id
       case 3:
    {
        find_email(addressBook);
        break;
    }

       case 4:

       break;

    default:

      printf("Entered value is not in choice");
        break;
    }

}

void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
}

void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
}


int find_name(AddressBook *addressBook){

    char str[100];
    validate_name(str);

    int limit =addressBook->contactCount;
    int ret;
    for(int i = 0; i <limit; i++){
    
     ret = strcmp(addressBook->contacts[i].name,str);
 
     if(ret == 0)
        print(i,addressBook);
    }  
 
}
////////////////////////////////find by number /////////////////////////////////////////
int find_number(AddressBook *addressBook){

    char str[100];
    validate_number(str);
    
    int limit =addressBook->contactCount;
    int ret;
    for(int i = 0; i <limit; i++){
    
     ret = strcmp(addressBook->contacts[i].phone,str);
 
     if(ret == 0)
       print(i,addressBook);
       return 0;
    } 
    {
        printf("\n--------------\n");
        printf("\n|!!!NOT-FOUND|\n");
        printf("\n--------------\n");

    }
 
}

////////////////////////////////find by email id//////////////////////////////////////////////////
int find_email(AddressBook *addressBook){

    char str[100];
    mail_check(str);
    
    int limit =addressBook->contactCount;
    int ret;
    for(int i = 0; i <limit; i++){
    
     ret = strcmp(addressBook->contacts[i].email,str);
 
     if(ret == 0)
         print(i,addressBook);

    }  
 
}
void print(int i,AddressBook *addressBook){
    printf("your entered name is %s\n ",addressBook->contacts[i].name);
    printf("The number is %s\n ",addressBook->contacts[i].phone);
    printf("The Email id is %s\n ",addressBook->contacts[i].name);   
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "validation.h"

// copy character by character
int string_copy(char *desti, char *source)
{

    while (*source != '\0')
    {

        *desti = *source;

        desti++;

        source++;
    }

    *desti = '\0';
}



// !string copy

int string_cmp(char *stringone, char *stringtwo)
{
    // compare both strings has same length
    if (strlen(stringone) != strlen(stringtwo))
    {
        return 0;
    }

    // both has same size ==> compare letter by letter

    int found = 0;

    for (int i = 0; i < strlen(stringone); i++)
    {

        if (stringone[i] != stringtwo[i])
        {

            found = 1;
        }

        if (found == 1)
        {

            return 0;
        }
    }

    // return 1 means strings are identical
    return 1;
}




void listContacts(AddressBook *addressBook, int sortCriteria)
{
    // Sort contacts based on the chosen criteria
    int count = addressBook->contactCount;

    int i = 0;

    while (i < count)
    {
        print(i, addressBook);

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




void createContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */
    int count = addressBook->contactCount;
    name_validation(addressBook);
    phone_validation(addressBook);
    mail_validation(addressBook); // check wheather (@) and (.) symbol present in the gmail
    addressBook->contactCount++;
}


void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    int choice;

    while (1)
    {
        printf("\n enter you choice \n 1)Name \n 2)phone number\n 3)Mail id \n 4)Exit \n|||||||||||||||\n ");

        scanf("%d", &choice);

        getchar();

        if ((int)choice >= 0 && (int)choice <= 9)
        {

            break;
        }
    }
    char str[100];

    switch (choice)
    {
        // find by number
    case 1:
    {
        find_name(addressBook);

        break;
    }
    // find using phone number
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

        searchContact(addressBook);

        break;
    }
}



void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */

    int choice, ret;

    while (1)
    {
        printf("Enter the choice to edit\n 1.Edit by name \n 2. Edit by number \n 3.Edit By Email\n");

        char str[100];

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

        edit_by_name(addressBook);

        break;

        // case 2: if user entered edit by number jump
    case 2:

         edit_by_number(addressBook);

        break;

    case 3:

        mail_validation(addressBook);

        break;

        // exit from the case
    case 4:

        break;

    default:
        while (!choice >= 3);
    }
    // validate_name(str1);
}







// ! delete by number 

void deleteContact(AddressBook *addressBook)
{
    char str1[50], str2[50];

    int choice;

    
    do{
        printf("Enter the choice to delete\n 1.delete by name \n 2. delete by number \n 3.delete By Email\n");

        char str[100];

        int ret = scanf(" %d", &choice);

        if(ret == 1) break;

    }while(1);

    switch (choice)
    {
        // case 1: if user selected edit by name
    case 1:
    {
    
      if(addressBook->contactCount == 0)
      {
        printf("\nAddressBook is empty");  
        break;
         }
        delete_by_name(addressBook);

        break;
   }
        // case 2: if user entered edit by number jump
    case 2:

    if(addressBook->contactCount == 0)
      {
        printf("\nAddressBook is empty");  
        break;
         }
        delete_by_number(addressBook);

        break;

        // case 3: if user  edit by email
    case 3:

    if(addressBook->contactCount == 0)
      {
        printf("\nAddressBook is empty");  
        break;
         }
        delete_by_email(addressBook);
        
        break;

    case 4:
        // exit from the case
        break;

    default:
        while (!choice >= 3);
    }
    // validate_name(str1);
}

int find_name(AddressBook *addressBook)
{

    char str[100];
    
    validate_name(str);

    int limit = addressBook->contactCount,ret;

    for (int i = 0; i < limit; i++)
    {

        ret = string_cmp(addressBook->contacts[i].name, str);

        if (ret == 1)
           {
            print(i, addressBook);
            }
    }
    if(ret == 0){

        find_name(addressBook);
    }

    
}
////////////////////////////////find by number /////////////////////////////////////////
int find_number(AddressBook *addressBook)
{

    char str[100];
    
    validate_number(str);

    int limit = addressBook->contactCount,ret;

    for (int i = 0; i < limit; i++)
    {

        ret = string_cmp(addressBook->contacts[i].phone, str);

        if (ret == 1)
            {print(i, addressBook);}
    }


    if(ret == 0){
        printf("\n--------------\n");
        printf("\n|!!!NOT-FOUND|\n");
        printf("\n--------------\n");
    }
}

////////////////////////////////find by email id//////////////////////////////////////////////////
int find_email(AddressBook *addressBook)
{

    char str[100];

    mail_check(str);

    int limit = addressBook->contactCount;
    int ret;
    for (int i = 0; i < limit; i++)
    {

        ret = string_cmp(addressBook->contacts[i].email, str);

        if (ret == 1)
            print(i, addressBook);
    }

    if(ret == 0){

        printf("\n--------------\n");
        printf("\n|!!!NOT-FOUND|\n");
        printf("\n--------------\n");
}
}

void print(int i, AddressBook *addressBook)
{

    printf("\nThe name is %s\n ", addressBook->contacts[i].name);

    printf("    The number is %s\n ", addressBook->contacts[i].phone);

    printf("        The Email id is %s\n ", addressBook->contacts[i].email);
    
    return ;
}


int edit_by_name(AddressBook *addressBook)
{

    int count = addressBook->contactCount;

    char str1[50], str2[50];

    printf("\nEnter Name to edit");

    validate_name(str1);

    // check wheather the string in the array
    // strcmp()

    int ret = 0;

    for (int i = 0; i < count; i++)
    {
        ret = string_cmp(str1, addressBook->contacts[i].name);

        if (ret == 1)
        {
            printf("\nEnter the name to Replace");

            validate_name(str2);

            string_copy(addressBook->contacts[i].name, str2);

            printf("\n ||  \n The edited is \n || \n");
            
            print(i,addressBook);

        }

    }

    if (ret == 1) return 0;

    if (ret == 0)
    {

        printf("\ncontact not found");

        edit_by_name(addressBook);
    }

}


int edit_by_number(AddressBook *addressBook){

    int count = addressBook->contactCount;

    char str1[50], str2[50];

    printf("\nEnter Number to edit");

    validate_number(str1);

    int ret = 0;

    for (int i = 0; i < count; i++)
    {
        ret = string_cmp(str1, addressBook->contacts[i].phone);

        if (ret == 1)
        {

            printf("\ncontact found");

            printf("\nEnter the Number to Replace");

            // validate number
            validate_number(str2);

            // copy of phone number
            string_copy(addressBook->contacts[i].phone, str2);

            printf("\n ||  \n The edited is \n || \n");

            print(i,addressBook);

        }
    }

    if (ret == 1) return 0;

    if (ret == 0)
    {

        printf("\ncontact not found");

        edit_by_number(addressBook);
    }
}




int edit_by_email(AddressBook *addressBook)
{

    char str1[50], str2[50];

    printf("\nEnter email to edit");

    // validate email and store in pointer address
    mail_check(str1);

    // check wheather the string in the array
    // strcmp()

    int count = addressBook->contactCount,ret = 0;

    for (int i = 0; i < count; i++)
    {
        ret = string_cmp(str1, addressBook->contacts[i].email);

        if (ret == 1)
        {

            printf("\nEmail found");

            printf("\nEnter the Email to Replace");

            mail_check(str2);

            // string copy function
            string_copy(addressBook->contacts[i].email, str2);

            // section for commenting
            printf("\n ||  \n The edited is \n || \n");
            print(i,addressBook);

            return 0;
        }
    }

    if (ret == 0)
    {

        printf("\ncontact not found");

        // if email not found recursive call
        edit_by_email(addressBook);
    }
}


int delete_by_name(AddressBook *addressBook){

       char str1[100];

       printf("\nEnter Name to delete");

        validate_name(str1);

        addressBook->contactCount;

        // printf("The count is %d",count);
        if(addressBook->contactCount == 1){
            
            printf("Can't delete is zero");

        }
        else if(addressBook->contactCount < 2){

          addressBook->contactCount--;

        }

        // this will work when only count of contact is greater than two
       else {for (int i = 0; i < addressBook->contactCount - 1; i++)
        {
                
           if(string_cmp(str1,addressBook->contacts[i].name)){
            
            for(int j=i; j < addressBook->contactCount -1; j++ ){

                string_copy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                string_copy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                string_copy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);

            }
           }
        }

    }
    addressBook->contactCount--;
}

int delete_by_number(AddressBook *addressBook){

    char str[100];

    printf("\nEnter the number to delete");

    validate_number(str);

    int phone_found=0;
    // this will enter the loop when 
    for (int i = 0; i < addressBook->contactCount - 1; i++)
        {

           if(string_cmp(str,addressBook->contacts[i].phone)){
        phone_found = i;   
        }
    }
    if(phone_found == 0){

        printf("\ncontact not found \n Re-Enter the contact");

        delete_by_number(addressBook);

    }

   
        else if(addressBook->contactCount < 2){

          addressBook->contactCount--;

        }

            for(int j=phone_found; j < addressBook->contactCount -1; j++ ){
                string_copy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                string_copy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                string_copy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
            }
           
        
       

        addressBook->contactCount--;
   
}

int delete_by_email(AddressBook *addressBook){

      char str[100];

    printf("\nEnter the mail to delete");

    mail_check(str);

    int found = 0;

    for (int i = 0; i < addressBook->contactCount - 1; i++)
        {

           if(string_cmp(str,addressBook->contacts[i].email)){
       found = i;       
        }
    }

    // if contact not found make a recursive call

    if(found == 0){
        printf("\nThe contact is not found");
        delete_by_email(addressBook);
        
    }

    // printf("The count is %d",count);

    // if contact count is zero 


        if(addressBook->contactCount == 0){
        
            printf("Can't delete is zero");
            
            return 0;

        }

        else if(addressBook->contactCount < 2){

          addressBook->contactCount--;

        }
        else if(found == addressBook->contactCount){

            addressBook->contactCount--;

            return 0;
 
        }
               
            else{

                for(int j = found; j < addressBook->contactCount -1; j++ ){

                string_copy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                string_copy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                string_copy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);

            }
        }
           
        addressBook->contactCount--;

    }

#include <stdio.h>
#include "contact.h"
#include "validation.h"

// ! edit by name
int edit_by_name(AddressBook *addressBook)
{
   // get the contact count
    int count = addressBook->contactCount;
   
    char str1[50], str2[50];

    printf("\nEnter Name to edit");

    // validate name function call
    validate_name(str1);
    
    // ret variable to check wheather the string found or not
    int ret = 0;

    for (int i = 0; i < count; i++)
    {
        // compare the strings
        ret = string_cmp(str1, addressBook->contacts[i].name);

        // if found
        if (ret == 1)
        {
            printf("\nEnter the name to Replace");

            // validate name function call
            validate_name(str2);

            // copy of name
            string_copy(addressBook->contacts[i].name, str2);

            // section for commenting
            printf("\n ||  \n The edited is \n || \n");
            
            print(i,addressBook);

        }

    }

    if (ret == 1) return 0;

    if (ret == 0)
    {

        printf("\ncontact not found");

        // recursive call
        edit_by_name(addressBook);
    }

}

// ! edit by number
int edit_by_number(AddressBook *addressBook){

    // get the contact count
    int count = addressBook->contactCount;

    char str1[50], str2[50];

    printf("\nEnter Number to edit");

    // validate number function call
    validate_number(str1);

    int ret = 0;

    // iterate through all contacts
    for (int i = 0; i < count; i++)
    {
        // compare the strings
        ret = string_cmp(str1, addressBook->contacts[i].phone);

        // if found
        if (ret == 1)
        {

            printf("\ncontact found");

            printf("\nEnter the Number to Replace");

            // validate number
            validate_number(str2);

            // copy of phone number
            string_copy(addressBook->contacts[i].phone, str2);

            // section for commenting
            printf("\n ||  \n The edited is \n || \n");

            // print the edited contact
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



// ! edit by email
int edit_by_email(AddressBook *addressBook)
{

    char str1[50], str2[50];

    printf("\nEnter email to edit");

    // validate email and store in pointer address
    mail_check(str1);

   // get the contact count
    int count = addressBook->contactCount,ret = 0;

    // iterate through all contacts
    for (int i = 0; i < count; i++)
    {
        // compare the strings
        ret = string_cmp(str1, addressBook->contacts[i].email);

        // if found
        if (ret == 1)
        {

            printf("\nEmail found");

            printf("\nEnter the Email to Replace");

            // validate email function call
            mail_check(str2);

            // string copy function
            string_copy(addressBook->contacts[i].email, str2);

            // section for commenting
            printf("\n ||  \n The edited is \n || \n");

            // print the edited contact
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

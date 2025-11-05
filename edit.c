#include <stdio.h>
#include "contact.h"
#include "validation.h"


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

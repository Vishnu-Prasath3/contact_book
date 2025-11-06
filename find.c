#include <stdio.h>
#include "contact.h"
#include "validation.h"

// ! find by name
int find_name(AddressBook *addressBook)
{

    char str[100];
    // validate name function call
    validate_name(str);

    int limit = addressBook->contactCount,ret;

    // iterate through all contacts
    for (int i = 0; i < limit; i++)
    {

        // compare the strings
        ret = string_cmp(addressBook->contacts[i].name, str);

        // if found print the contact
        if (ret == 1)
           {
            // print the contact details
            print(i, addressBook);
            }
    }
    if(ret == 0){

        printf("\n--------------\n");
        printf("\n|!!!NOT-FOUND|\n");   
        find_name(addressBook);
    }

    
}
////////////////////////////////find by number /////////////////////////////////////////
int find_number(AddressBook *addressBook)
{

    char str[100];
    
    // validate number function call
    validate_number(str);

    // get the contact count
    int limit = addressBook->contactCount,ret;

    // iterate through all contacts
    for (int i = 0; i < limit; i++)
    {

        // compare the strings
        ret = string_cmp(addressBook->contacts[i].phone, str);

        // if found print the contact
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

    // validate mail function call
    mail_check(str);

    // get the contact count
    int limit = addressBook->contactCount;
    
    // iterate through all contacts
    int ret;

    // iterate through all contacts
    for (int i = 0; i < limit; i++)
    {

        // compare the strings
        ret = string_cmp(addressBook->contacts[i].email, str);

        //  if found print the contact
        if (ret == 1)
            print(i, addressBook);
    }

    // if contact not found
    if(ret == 0){

        printf("\n--------------\n");
        printf("\n|!!!NOT-FOUND|\n");
        printf("\n--------------\n");
}

}
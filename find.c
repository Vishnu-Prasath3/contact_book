#include <stdio.h>
#include "contact.h"
#include "validation.h"


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
#include <stdio.h>
#include "contact.h"
#include "validation.h"


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

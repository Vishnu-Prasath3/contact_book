#include <stdio.h>
#include "contact.h"
#include <string.h>
#include <ctype.h>

void validate_name(char str[]){  //checking 
    
    printf("\nEnter the Name\n");

    scanf(" %[^\n]", str);  

   
    int i = 0;

    while(str[i] != '\0')
    {
    
    if((str[i]>='A'&&str[i]<='Z') || (str[i]>='a'&&str[i]<='z') || str[i]==' ');
    
    else
    {
        //if the name conntains someother dumps return  0
        printf("you have entered Invalild name\n");
        validate_name(str);
    }

    i++;
   }

   return ;
}


void name_validation(AddressBook *addressBook,int count){
        
        char str[50];  

        validate_name( str); //passing base address of the string

        strcpy(addressBook->contacts[count].name,str); //copy of str to address book

        printf(" %s ",addressBook->contacts[count].name);
        
        //  printf("%s",addressBook->contacts[count].name);


}


//////////////////////////// check for mail id //////////////////////////////////////////
   
  int mail_check(char str[]){ //check
   
    printf("\nEnter the Mail Id\n");
    
    scanf(" %[^\n]", str);

    char gmail[] = "@gmail.com";
    
    char *ret = strstr(str ,gmail);


    
     if(!isalpha(str[0])){
        
        printf("\nFirst digit should be alphabet");

        mail_check(str);
     }
   
    if( ret == NULL){
        printf("\nInvalid gmail");
        mail_check(str);
    }
  
}


void mail_validation(AddressBook *addressBook,int count){

   char str[100];
   mail_check(str);
   strcpy(addressBook->contacts[count].email,str);
}
////////////////////////////////phone_validation(addressBook)////////////////////////////////////////////

int validate_number(char str[]){   //check
     
        int i = 0;

        printf("\n::::::Enter the 10_Digit IND-number::::::\n");
        
        scanf(" %[^\n]",str);
         
        printf("you entered digit is %s",str);

        if(strlen(str) < 10 || strlen(str) > 10  ){
   
        printf("\ninvalid number ::::> Re-Enter\n"); 

        validate_number(str);
        }

 
        while (i < strlen(str))
        {   

            if(str[i] >= '0' && str[i] <= '9');
            // if(!isdigit(str[i]))
            else{
                printf("\n--------------------------");
                printf("\n|     Invalid number      |");
                printf("\n--------------------------\n");
                validate_number(str);   
            }
            i++;
        }
        return 0; 
}

void phone_validation(AddressBook *addressBook,int count){

      char str[50];
      validate_number(str);
    //   
      printf("%s",str);
      strcpy(addressBook->contacts[count].phone,str);

    //   checking for printing
      printf(addressBook->contacts[count].phone);

      
}

// char *string_copy()

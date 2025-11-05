#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{

    // file pointer
    FILE *fp;
    
    // opening an pointer in write mode
    fp = fopen("contact.csv", "w");

    // check wheather the pointer is null or not
    if (fp == NULL)
    {
        printf("\n⟢⟢⟢⟢⟢File Not-Found⟢⟢⟢⟢⟢");

        return;
    }

    fprintf(fp,"%d\n",addressBook->contactCount);

    // iterate contact count times for saving into the file
    for(int i = 0; i < addressBook->contactCount; i++)
    {
    
        // writing the each line
        fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

  }

  //close the file for buffer close and other resources available
  fclose(fp);

}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp;
    fp = fopen("./contact.csv","r");
    
    if( fp == NULL ){
       printf("Error: file not found");
    }
     fscanf(fp, "%[^\n]");

    for(int i = 0; i < addressBook->contactCount; i++){

        

    }

}

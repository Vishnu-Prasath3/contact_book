#include <stdio.h>
#include "file.h"
#include "contact.h"

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
    // writing the contact count first
    fprintf(fp, "%d\n", addressBook->contactCount);

    // iterate contact count times for saving into the file
    for (int i = 0; i < addressBook->contactCount; i++)
    {

        // writing the each line
        fprintf(fp, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    // close the file for buffer close and other resources available
    fclose(fp);
}

// function to load contacts from file
void loadContactsFromFile(AddressBook *addressBook)
{
    // file pointer
    FILE *fp;

    // opening file in read mode
    fp = fopen("./contact.csv", "r");

    // check wheather file is present or not
    if (fp == NULL)
    {
        printf("Error: file not found");
    }

    // variable to store size
    int size;

    // read the size from the file
    fscanf(fp, "%d", &size);

    // i were initialized to size times
    // size were fetched from contact.csv

    for (int i = 0; i < size; i++)
    {
        // reading each line from the file
        fscanf(fp, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

        // incrementing the contact count
        addressBook->contactCount++;
    }
    printf("\n Contact count is %d Loaded\n", addressBook->contactCount);
}

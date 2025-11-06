#include <stdio.h>
#include "contact.h"


int main() {


    int choice;

    AddressBook addressBook; //Structure initialization  

    initialize(&addressBook); //initialize function call 

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        // Get user choice
        scanf("%d", &choice); 
        
        switch (choice) {
            case 1: 
                createContact(&addressBook); //jump to create contact function
                break;
            case 2:
                searchContact(&addressBook); //jump to search contact function
                break;
            case 3:
                editContact(&addressBook); //jump to edit contact   function
                break;
            case 4:
                deleteContact(&addressBook);  //jump to delete contact  function
                break;
            case 5:          
                listContacts(&addressBook); //jump to list all contacts function
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook); // Save contacts to file function call
                break;

                default:
                // Handle invalid choices
                printf("Invalid choice. Please try again.\n"); 
        }
    } while (choice != 7); 
    
       return 0; // Exit the program
}

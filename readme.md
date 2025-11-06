1.documentation
2.single command
3.prompt message

<!-- validation.c -->

=======>validation take's care it
validation like{name, email, phone number}

<!-- phone number validation -->

s1: checking length of the number

s2: if number less or greater than 10 recursive call

s3: checking wheather number is digit or not

s4: if it not an digit .recursive call

<!-- mail id validation -->

@gmail.oom --->after _.com_ no character should be inserted

<!-- strcpy() in C -->

strcpy() is a built-in function used to copy one string into another

The strcpy function in C is used to copy a string, strcpy(dest, src);,

Here I defined user defined function as strcpy where the string copy from one function

to the other function

<!--edit contact-->

---

1. Function: int edit_by_name(AddressBook \*addressBook)

---

Description:

    Allows the user to modify an existing contact’s name.

    The function searches for a contact by the current name, and if found, prompts the

    user to enter a new name.

Steps: 1. Prompts the user to input the name to be edited.

    2. Validates the entered name using validate_name().

    3. Iterates through the contact list to find a matching name using string_cmp().

    4. If found:
        - Asks for a replacement name.
        - Copies the new name using string_copy().
        - Displays the updated contact using print().

    5. If (not-found):
        - Displays an error message and recursively re-prompts the user.

---

2. Function: int edit_by_number(AddressBook \*addressBook)

---

Description:
Enables the user to edit an existing contact’s phone number.

Steps: 1. Prompts the user to input the current phone number.

    2. Enters to the validate_number().

    3. Searches through the contact list using string_cmp().

    4. match is found:
        - Prompts the user for the new phone number.
        - Validates and updates it using string_copy().
        - Displays the updated contact.

    5. no match is found:
        - Displays an error and recursively restarts the function.

---

3. Function: int edit_by_email(AddressBook \*addressBook)

---

Description:
Provides functionality to modify a contact’s email address.

Steps: 1. Prompts the user to enter the email to be edited. 2. Validates the entered email using mail_check(). 3. Iterates through the contact list to find a matching email using string_cmp(). 4. If found: - Prompts the user to enter the replacement email. - Updates the record using string_copy(). - Prints the modified contact using print(). 5. If not found: - Displays an error message and recursively prompts again.

<!-- Delete contact  -->

traverse the structure by copying one array to another.
=================>next to prev<===============
array shifting taken place

if last contact were deleted delete the last contact;

Array

<!-- cannot delete an array but we can modify the array by the size -->

In csv file we should have to print the contact count value

<!-- find  -->

/\*

- This module allows the user to search for a contact in the address book

- using three criteria: name, phone number, or email ID

- It validates user input, compares strings, and prints matching contact details.

find contact in username in addressbook

\*/

---

## Function: int find_email(AddressBook \*addressBook)

Description:
Prompts user for a valid email ID, validates it, and searches for a match.
If found, prints contact details; otherwise, displays "NOT FOUND".

Parameters:
addressBook - Pointer to AddressBook structure

---

## Function: int find_name(AddressBook \*addressBook)

Description:
Prompts user for a name, validates it, and searches for the contact by name.
If found, prints contact details; otherwise, displays "NOT FOUND" and retries.

Parameters:
addressBook - Pointer to AddressBook structure

---

## Function: int find_number(AddressBook \*addressBook)

Description:
Prompts user for a ==>phone number, validates input, and searches for matching contact.
If found, prints details; otherwise, prints "NOT FOUND".

Parameters:
addressBook - Pointer to AddressBook

<!--  -->

Contact Deletion Module - Quick Reference

Overview

Three functions to delete contacts from an address book by name, by phone, and by email.

-

## Functions

`delete_by_name(AddressBook *addressBook)`
Deletes a contact by name.
\*\*How it works:

1. Ask user for name

2. Find matching contact
3. Shift remaining contacts left
4. Reduce contact count

delete_by_name(&myBook);

// User enters: "John Doe"

// Contact "John Doe" is deleted
The
--
==?delete_by_number(AddressBook \*addressBook)
Deletes a contact by phone number.

\*\*How it works:

1. Ask user for phone number
2. Search for matching number
3. If not found, ask again
4. Shift remaining contacts left

5. Reduce contact count

delete_by_number(&myBook);
// User enters "1234567890"
// Contact with that number is deleted

delete_by_email(AddressBook \*addressBook)
Deletes a contact by e-mail.
\*\*How it works:

1. Ask user for email

2. Search for matching email

3. If not found, ask again

4. Shift remaining contacts left
5. Contact count reduction

This is a simple, easy-to-use contact management system implemented in C. Store, search, edit, and delete your contacts with ease!

What Can It Do?

- **Create** new contacts with name, phone, and email
- **Search** contacts by name, phone, or email
- **Edit** existing contact information

- **List** all your contacts at once
- **Save** your contacts automatically to a file

- **Load** contacts from file when you start

<!-- contact.c -->

**Function*call***

1.Every Function call were happen to here

2.function definition and function were happens here

**INITIALIZE**
1.This will load contacts will happen

2.Increase the contact count;

**save_exit**
1.save the current structure to the file format

**create_contact**
1.validate the contact

2.stores the strings in the contact in structure

**print_contact**
1.print the contact details like
--->name
--->phone number
--->email


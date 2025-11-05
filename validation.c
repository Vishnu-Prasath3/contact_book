#include <stdio.h>
#include "contact.h"
#include <string.h>
#include <ctype.h>

int is_char(char c)
{

  return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0);
}

void validate_name(char str[])
{ // checking

  printf("\n----->Enter the Name-----<\n");

  scanf(" %[^\n]", str);

  int i = 0;

  while (str[i] != '\0')
  {
    if ((str[i] != ' ' && !is_char(str[i])))
    {
      // if the name conntains someother dumps return  0
      printf("you have entered Invalild name\n");
      validate_name(str);
    }
    i++;
  }

  return;
}

void name_validation(AddressBook *addressBook)
{

  char str[50];

  validate_name(str); // passing base address of the string
   
  if( !(str[0] >= 'A') && !(str[0] <= 'Z') )
  {
    validate_name(str);
  }
  
  int count = addressBook->contactCount;

  strcpy(addressBook->contacts[count].name, str); // copy of str to address book

  //  printf("%s",addressBook->contacts[count].name);

  return;
}

//////////////////////////// check for mail id //////////////////////////////////////////

int mail_check(char str[])
{

  printf("\nEnter the Mail Id\n");

  scanf(" %[^\n]", str);
  getchar(); // to fill the buffer size

  // first digit should be character

  if (!is_char(str[0]))
  {

    printf("1st character should be alphabet");

    mail_check(str);
  }

  int len = 0;

  while (str[len] != '\0')
    len++;

  int at = -1, dot = -1;

  for (int i = 0; i < len; i++)
  {
    if (str[i] == '@')
    {

      at = i;
    }
    if (str[i] == '.')
    {
      dot = i;
    }
  }

  // fot should present after @
  if (at > dot)
  {
    printf("\n invalid gmail");
    mail_check(str);
  }

  // if both dot and @ were not present
  if (dot == -1 || at == -1)
  {

    printf("\n@ and . should be present in the gmail");

    mail_check(str);
  }

  //  if dot present at lost
  if (len == '.')
  {

    printf("\nDot should not at last");

    mail_check(str);
  }
}

void mail_validation(AddressBook *addressBook)
{

  char str[100];
  mail_check(str);
  int count = addressBook->contactCount;
  strcpy(addressBook->contacts[count].email, str);
}

//////////phone_validation(addressBook)//////////

int validate_number(char str[])
{ // check

  int i = 0;

  printf("\n::::::Enter the 10_Digit IND-number::::::\n");

  scanf(" %[^\n]", str);

  if (strlen(str) < 10 || strlen(str) > 10)
  {

    printf("\ninvalid number ::::> Re-Enter\n");

    // recursive call
    validate_number(str);
  }

  while (i < strlen(str))
  {

    if (!(str[i] >= '0') && !(str[i] <= '9'))
    {
      printf("\n--------------------------");
      printf("\n|     Invalid number      |");
      printf("\n--------------------------\n");
      validate_number(str);
    }
    i++;
  }

  return 0;
}

// ||| =============>>>>>>>Phone saving<<<<<<<<========|||

void phone_validation(AddressBook *addressBook)
{

  char str[50];

  // phone-number-validation function call
  validate_number(str);
  int count = addressBook->contactCount;

  strcpy(addressBook->contacts[count].phone, str);
}

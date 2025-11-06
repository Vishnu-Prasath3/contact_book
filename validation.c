#include <stdio.h>
#include "contact.h"
#include <string.h>
#include <ctype.h>

int is_char(char c)
{

  return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0);
}

void validate_name(char str[])
{
  // checking

  printf("\n----->Enter the 𝐇𝐄┃𝐇𝐈𝐌 or 𝐒𝐇𝐄┃𝐇𝐄𝐑 Name-----<\n");

  // getchar(); // to clear the buffer

  scanf(" %[^\n]", str);

  int i = 0;

  while (str[i] != '\0')
  {
    if ((str[i] != ' ' && !is_char(str[i])))
    {
      // if the name conntains someother dumps return  0
      printf("🔴🔴🔴you have entered Invalild name🔴🔴🔴\n");

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

  if (!(str[0] >= 'A') && !(str[0] <= 'Z'))
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

  printf("\nEnter the Mail ✉Id\n");

  scanf(" %[^\n]", str);
  getchar(); // to fill the buffer size

  // first digit should be character

  if (!is_char(str[0]))
  {

    printf("💥1st character should be alphabet💥");

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
    if (str[i] == ' ')
    {

      printf("Space is not-allowed in Email");

      mail_check(str);
    }
  }

  // fot should present after @
  if (at > dot)
  {
    printf("\n📌Invalid gmail📌");

    mail_check(str);
  }

  // if both dot and @ were not present
  if (dot == -1 || at == -1)
  {

    printf("\n🎯@ and . should be present in the gmail🎯");

    mail_check(str);
  }

  //  if dot present at lost
  if (len == '.')
  {

    printf("\n🎯Dot should not at last🎯");

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

// phone_validation(addressBook)

int validate_number(char str[])
{

  int i = 0;

  printf("\n::::::Enter the 🔟_Digit 📞-number::::::\n");

  // buffer clearing the buffer
  getchar();

  scanf("%[^\n]", str);

  /*
  number length should be 10
  if number greater or smaller than 10 recursive
  call will happen until the condition satisfies
  */
  if (strlen(str) < 10 || strlen(str) > 10)
  {

    printf("\n❌invalid number😔::::> ⌨ Re-Enter\n");

    // recursive call
    validate_number(str);
  }

  // validating number if not an number recursive function call happen

  for (int i = 0; i < 10; i++)
  {

    if ((str[i] >= '0') && (str[i] <= '9'))
      ;

    else
    {

      printf("\n--------------------------");

      printf("\n|🚫🚫🚫Invalid number🚫🚫🚫|");

      printf("\n--------------------------\n");

      validate_number(str);
    }
  }

  return 0;
}

// ||| =============>>>>>>>phone number saving function<<<<<<<<========|||

void phone_validation(AddressBook *addressBook)
{

  char str[50];

  // phone-number-validation function call
  validate_number(str);

  int count = addressBook->contactCount;

  strcpy(addressBook->contacts[count].phone, str);
}

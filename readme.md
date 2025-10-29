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

In C, strcpy() is a built-in function used to copy one string into another. It is a part of the C standard strings library.

The strcpy function in C is used to copy a string, with syntax: strcpy(dest, src);, where dest is the destination array and src is the source string.
It returns a pointer to the dest string after copying the content from src.

int main() {
  
    char s1[] = "Hello beeks!";
    char s2[20] = "GfG";
    char s3[40];

    // Copy contents of s1 to s2 using strcpy
    strcpy(s2, s1);

    // Copy a constant string into s3
    strcpy(s3, "Copy successful");

    printf("s1: %s\n", s1);
  	printf("s2: %s\n", s2);
  	printf("s3: %s", s3);
  	
    return 0;
}
Output
str1: Hello beeks!
str2: Hello beeks!
str3: Copy successful
<>======<> Risk of Buffer Overflow (Unsafe Use) <>======<>
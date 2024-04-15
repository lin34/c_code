/*
Every character is a single byte.
Value between 0-127 ASCII
Ends with null terminaltor 0

\ is the escape character.
can specify which base and then the number for ascii.
e.g. \n   \xA \12 (octal) are all the same
*/
#include <stdio.h>
#include <string.h>
// Write a function that returns the length of a string (strlen)
int get_string_length(char *str)
{
    int offset = 0;
    while (str[offset] != 0)
    {
        offset++;
    }
    return offset;
}
// strcpy
void copy_string(char *from, char *to)
{
    int offset = 0;
    while (from[offset] != 0)
    {
        to[offset] = from[offset];
        offset++;
    }
    to[offset] = 0;
}

void reverse0(char *str)
{
    // in place string reversal
    int length = strlen(str);

    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    printf("new str: %s", str);
}

void reverse1(char *str)
{
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void reverse3(char *str)
{
    char *end = str + strlen(str) - 1;

    while (str < end)
    {
        char temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

void reverse4(char *str, int length)
{
    if (length <= 1)
        return;
    char tmp = str[0];
    str[0] = str[length - 1];
    str[length - 1] = tmp;
    reverse4(str + 1, length - 2);
}

int main(int argc, char **argv)
{
    /* char str[] = "test"== an array of chars initialized with
    contents "test"
    char *str = "Test" is a pointer to the literal (const) string"test"
    This second string is immutable and constant! The 1st can be modified
    */
    char a[] = "string"; // the compiler puts {'s','t','r','i','n','g', 0} onto STACK

    char *b = "string"; // the compiler puts just the pointer onto STACK
                        // and {'s','t','r','i','n','g',0} in static memory area.

    char str1[] = "123456";
    char str2[] = "hello world!";
    char *p = "efgh";
    char new_string[500];

    printf("Reverse string %s\n", str1);
    reverse4(str1, strlen(str1));
    printf("Reversed = %s\n", str1);

    copy_string(str2, new_string);
    printf("%s\n", new_string);
    // Prints out: Memory address for string
    printf("1: %d\n", str1);

    // Prints out: 123456
    printf("2: %s\n", str1);

    // Prints out: 123456. str1 and &str1 are the same
    printf("3: %s\n", &str1);
    // Prints out: efgh
    printf("4: %s\n", p);
    // Prints out: memory address to start of "efgh", 4 bytes 32 bits
    // p and &p are not the same
    printf("5: %#010x\n", &p);

    // Prints out: Seg fault. tries to dereference "efgh"
    printf("6: %s\n", *p);
    // Prints out: segmentation fault. tries to dereference "123456"
    printf("7: %s\n", *str1);
}
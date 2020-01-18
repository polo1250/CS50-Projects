// This program print hello world
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get the name of the user
    string name = get_string("Name: ");
    
    printf("hello, %s\n", name);
}

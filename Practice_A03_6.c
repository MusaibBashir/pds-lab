//Write a function rev() which has no argument but inside it reads a set of characters and prints them in a reverse fashion.

#include <stdio.h>

void rev() {
    char c;
    if ((c = getchar()) != '\n') { 
        rev();  // Recursion, the main trick of this function
        printf("%c",c);  // Print the current character after the recursion has printed the ones after it
    }
  //Basically what we are doing is making it move to the next letter while storing the previous one in memory until it reaches the last letter, from there it starts printing back in reverse;
}

int main() {
    printf("Enter a string: ");
    rev(); 
    return 0;
}

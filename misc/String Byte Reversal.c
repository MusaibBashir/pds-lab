/*Byte reversals Given a byte as input in the form of a character, print the new character formed by reversing the 7-bit string created from all but the leftmost bit. For example, a becomes C, C becomes a, b becomes #, # becomes b, etc.
Hint: Let’s walk through the process step by step for the input character ’a’. The ASCII value of ’a’ is 97, which is 01100001 in binary. You can mask this value using 0x7F (= 01111111 in binary), resulting in 01100001. (Masking here means bit-wise and using the operator &.) Next, reversing the 7 bits of this binary sequence (excluding the leftmost one), producing 1000011. This corresponds to the ASCII value 67, which is the character ’C’.
From the book, C the Code*/

#include <stdio.h>

char reverse_bits(char c) {
    unsigned char masked = c & 0x7F;  // Mask to get the 7 bits (excluding the leftmost bit)
    unsigned char reversed = 0;
    
    // Reverse the 7 bits (rightmost bit is a sign bit)
    for (int i = 0; i < 7; i++) {
        reversed <<= 1;  // making rightmost bit 0, so that on taking 'OR' we can get 0 or 1 depending on masked bit.
        reversed |= (masked & 1);  // Take the rightmost bit(using &1) and add that to reversed
        masked >>= 1;  // Shift binary to right, so we get a new rightmost bit.
    }
    
    return reversed; //it is  a character
}

int main() {
    char ch;
    printf("Enter a character: ");
    ch=getchar();    
    char reversed_char = reverse_bits(ch);
    
    printf("Reversed character: %c\n", reversed_char);
    
    return 0;
}

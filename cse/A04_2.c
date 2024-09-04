/*In a galaxy far, far away a fierce battle is raging between the Resistance and the sinister Empire. As a member of the Resistance, you’ve intercepted the following message from the captain of a spacecraft just before it was captured by the Empire.
.epoh ylno ym er’uoy .ibonek naw-ibo ,em pleh
Your mission is to decrypt this message and uncover its true meaning in English.
Write a recursive function that takes the above string as input and prints the decrypted text to the console. You must not declare a new array for the decryption and you must not use any other header file except stdio.h.
For your reference, here are few more examples of encrypted text that you received
bit earlier but could not decrypt yet.
esrevinu olleh
L ssecnirp si eman ym*/

#include <stdio.h>
void decrypt(char arr[], int size){
if(size==1){
printf("%c", arr[0]);
return;}
decrypt(arr+1,size-1);
printf("%c", arr[0]);
}

int main() {
char enc[100],ch;
int len=0;
printf("Enter Encrypted message: ");
do
{
    ch=getchar();
    if (ch!='\n')
    enc[len++]=ch;
} while (ch!='\n');
printf("Decrypted Message: ");
decrypt(enc,len);
return 0;
}

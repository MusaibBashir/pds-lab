#include <stdio.h>
void transfer (int n, char from, char to, char temp);
int main( ) 
{ 
int n; 
scanf ("%d", &n);
transfer (n, 'L', 'R','C');
}
void transfer (int n, char from, char to, char temp) {
if (n > 0) {
transfer (n-1, from, temp, to);
printf ("Move disk %d from %c to %c \n", n, from, to);
transfer (n-1, temp, to, from);
}
return;
}

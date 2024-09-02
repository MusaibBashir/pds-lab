/*Write a C program for generating a pattern like this:
3 3 3 3 3
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3
*/

#include <stdio.h>
int main() 
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int len = 2 * n - 1;
    int minh, minv, min;
    for (int i = 1; i <= len; i++)  //Rows
    {
      for (int j = 1; j <= len; j++) //Columns
      { 
        minh = i <= len - i ? i -1 : len - i; //Min dist from horizontal edges
        minv = j <= len - j ? j - 1: len - j; // Min dist from vertical edges
        min = minh <= minv ? minh : minv; //Min dist of the above two
        printf("%d ",n - min); //n-min came from observation of pattern
      }
      printf("\n");
    }
return 0;
}

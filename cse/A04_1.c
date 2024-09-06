/*The Recam´an’s sequence a0, a1, a2, . . . is defined as:
an= 0 if n = 0
an= an−1 − n if an−1 − n > 0 and not already present in the sequence.
an= an−1 + n otherwise
Write a recursive function to print the first n terms in the sequence
For reference, the following are the first 75 terms in the sequence.
1 3 6 2 7 13 20 12 21 11 22 10 23 9 24 8 25 43 62 42 63 41 18
42 17 43 16 44 15 45 14 46 79 113 78 114 77 39 78 38 79 37 80
36 81 35 82 34 83 33 84 32 85 31 86 30 87 29 88 28 89 27 90 26
91 157 224 156 225 155 226 154 227 153 228*/

#include <stdio.h>
int recaman(int n, int arr[]) {
    int prev,curr=0;
    if(n==0)
    return 0;
    prev=recaman(n-1,arr);
    
    if (prev-n>0){
        for (int i = 0; i < n; i++) {
            if (arr[i]==(prev-n)){
                    curr=prev+n;
                    arr[n-1]=curr;
                break;
            }
        }
        
        if(!curr){
            curr=prev-n;
            arr[n-1]=curr;
        }
    }
    else{
        curr=prev+n;
        arr[n-1]=curr;
        }
return curr;

}

int main() {
int num;
scanf("%d", &num);
int arr[num];
recaman(num, arr);
for (int i = 0; i < num; i++) {
printf("%d ", arr[i]);
}
return 0;
}

/*
   write a standard input into a text file(first.txt),
   read the text file, and the standard output appears.
   date: 2019. 4. 6.
*/
 
#include <stdio.h> 

void size(FILE *rt) 
 { 
   char arr[100]; 

   fgets(arr, sizeof(arr), rt); 
   puts(arr);			//확인용 

} 

int main(void) 
{ 
   char arr[100]; 

   FILE *wt1 = fopen("first.txt", "w");  // "wt"
   FILE *rt1; 

   fgets(arr, sizeof(arr), stdin); 
   fputs(arr, wt1); 
   fclose(wt1); 

   rt1 = fopen("first.txt", "r");  // "rt"
   size(rt1); 
   fclose(rt1); 
} 

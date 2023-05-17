#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
   char ch;
   FILE *fp;
   fp=fopen("std1.txt","w");
   printf("enter the text.press cntrl Z:");
   while((ch = getchar())!=EOF){
      putc(ch,fp);
   }
   fclose(fp);
   fp=fopen("std1.txt","r");
   printf("text on the file:");
   while ((ch=getc(fp))!=EOF){
      if(ch == ',')
         printf("\t\t");
      else
         printf("%c",ch);
   }
   fclose(fp);
   return 0;
}

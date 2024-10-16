#include <stdio.h>
#include <string.h>

int main(){
    char str[111];
    while (fgets(str, 102, stdin) != NULL) {
        int Low=0, Up=0, Num=0, Blank=0;
        for (int i=0; str[i] != '\0'; i++){
            if ('a'<=str[i] && str[i]<='z'){
                Low++;
            }else if ('A'<=str[i] && str[i]<='Z'){
                Up++;
            }else if ('0'<=str[i] && str[i]<='9'){
                Num++;
            }else if (str[i]==' '){
                Blank++;
            }
      }
      printf("%d %d %d %d\n", Low, Up, Num, Blank);
   }
}
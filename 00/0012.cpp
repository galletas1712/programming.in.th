#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char c[16];
    scanf("%s", c);
    int col = 5 + (strlen(c)-1)*4;
    int a_count = 0;
    for(int i = 1; i <= 5; i++){
        bool has = false;
        int bef = 0;
        for(int j = 1; j <= col; j++){
            if(i == 1 || i == 5){
                if(j == 3+(a_count * 4)){
                    if((a_count+1)% 3 == 0 && a_count != 0){
                        printf("*");
                    }else{
                        printf("#");
                    }
                    a_count++;
                }else{
                    printf(".");
                }
            }else if(i == 2 || i == 4){
                if(j-2 == 3+(a_count * 4)) a_count++;
                if(j % 2 == 0){
                    if((a_count+1)% 3 == 0 && a_count != 0){
                        printf("*");
                    }else{
                        printf("#");
                    }
                }else{
                    printf(".");
                }
            }else if(i == 3){
                if(j == 1+(a_count*4)){
                    if((a_count+1) % 3 == 0 && a_count != 0){
                        if(j != col){
                            printf("*");
                            has = true;
                            bef = j;
                        }else{
                            printf("#");
                        }
                    }else if(has && j == bef+4){
                        printf("*");
                        has = false;
                    }else{
                        printf("#");
                    }
                }else if(j == 3+(a_count*4)){
                    printf("%c", c[a_count]);
                    a_count++;
                }else{
                    printf(".");
                }
            }
        }
        a_count = 0;
        printf("\n");
    }
}

// if(j == 3+a_count*4){
//   if(i == 3){
//     printf("%c", c[a_count]);
//     a_count += 1;
//   }else if(i == 1 || i == 5){
//     printf("#");
//   }
// }else if((j == a_count*4 && i == 3) || (j % 2 == 0 && (i == 2 || i == 4))){
//   printf("#");
// }else{
//   printf(".");
// }

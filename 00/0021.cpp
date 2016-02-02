#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    char string[110];
    gets(string);
    int len = strlen(string);
    int i = 0;
    while(i < len){
        printf("%c", string[i]);
        // printf("%d", i);
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
            i+= 3;
        else
            i++;
    }
}

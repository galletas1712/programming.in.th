#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char string[10010];
    gets(string);
    bool lower = false;
    bool upper = false;
    for(int i = 0; i < strlen(string); i++){
        if(islower(string[i]))
            lower = true;
        else if(isupper(string[i]))
            upper = true;
        if(lower == true && upper == true) break;
    }
    if(lower && !upper)
        printf("All Small Letter");
    else if(upper && !lower)
        printf("All Capital Letter");
    else if(upper && lower)
        printf("Mix");
}

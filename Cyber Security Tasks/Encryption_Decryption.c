#include <stdio.h>
#include <stdlib.h>


int op = 0;
char msg[100] = {};
int key = 0;
char en_msg[100] = {};
char de_msg[100] = {};

int main(){

    printf("Enter Opeartion you want (Encryption -> 1 , Decryption -> 2): \n");
    scanf("%i",&op);
    fflush(stdin);
    printf("Enter Message: \n");
    gets(msg);
    printf("Enter Key: \n");
    scanf("%i",&key);

    if(op == 1){
        for(unsigned int i = 0 ; (i < 100) && (msg[i] != '\0') ; i++){
            if(msg[i] == ' '){
                msg[i] = ' ';
            }
            else{
                msg[i] = (msg[i] + (key % 26));
            }
        }
        printf("%s \n",msg);
    }
    else if(op == 2){
        for(unsigned int i = 0 ; (i < 100) && (msg[i] != '\0') ; i++){
            if(msg[i] == ' '){
                msg[i] = ' ';
            }
            else{
                msg[i] = (msg[i] - (key % 26));
            }
        }
        printf("%s \n",msg);
    }
    else{
        printf("Error! \n");
    }
    return 0;
}
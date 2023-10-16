#include<stdio.h>
#include<stdlib.h>

typedef unsigned int uint32;
void nible_sort(uint32 value);
void Swap_Two_Numbers(unsigned int *pNumber1, unsigned int *pNumber2);
int main(){

    nible_sort(0xF69A2873);  
    return 0;
}

void nible_sort(uint32 value){
    uint32 value1 = (value & (0xF0000000)) >> 28;
    uint32 value2 = (value & (0x0F000000)) >> 24;
    uint32 value3 = (value & (0x00F00000)) >> 20;
    uint32 value4 = (value & (0x000F0000)) >> 16;
    uint32 value5 = (value & (0x0000F000)) >> 12;
    uint32 value6 = (value & (0x00000F00)) >> 8;
    uint32 value7 = (value & (0x000000F0)) >> 4;
    uint32 value8 = (value & (0x0000000F));
    uint32 my_array[8] = {value1 ,value2, value3, value4, value5, value6, value7, value8};
    unsigned int BS_Iteration = 0, Adjacent_Iteration = 0;
    unsigned char Sort_Flag = 0;

    for(BS_Iteration=0; BS_Iteration<8-1; BS_Iteration++){

        for(Adjacent_Iteration=0; Adjacent_Iteration < 8-BS_Iteration-1; Adjacent_Iteration++){
            if(my_array[Adjacent_Iteration] > my_array[Adjacent_Iteration+1]){
                Swap_Two_Numbers(&my_array[Adjacent_Iteration], &my_array[Adjacent_Iteration+1]);
                Sort_Flag = 1;
            }
        }

        if(Sort_Flag == 0){
            return;
        }
    }

    printf("0x ");
    for(uint32 Data_Counter=0; Data_Counter< 8; Data_Counter++){
        printf("%x", my_array[Data_Counter]);
    }
    printf("\n");
}

void Swap_Two_Numbers(unsigned int *pNumber1, unsigned int *pNumber2){
    unsigned int Temp_Number = *pNumber1;
    *pNumber1 = *pNumber2;
    *pNumber2 = Temp_Number;
}

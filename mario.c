#include <stdio.h>

int main(void){
    int height;
    printf("Enter mario tower height: ");
    scanf("%d", &height); 
    for (int x = 0; x <= height; x++){
        for (int y = height-x; y != 0; y--){
            printf(" ");
        }
        for (int y = 0; y <= x; y++){
            printf("#");
        }
        
        printf(" ");

        for (int y = 0; y <= x; y++){
            printf("#");
        }
        printf("\n");
    }
    return 0;

}
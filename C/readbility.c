#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
    char input_text[100];
    char input_dpl[100];
    int strSize[100];
    int sentSize[100];
    int sentCnt = 0;
    int loop;
    int total = 0; 
    int sentTotal = 0;
    int strCnt = 0;
    char sentDelim[] = ".!?";
    printf("Text: ");
    fgets(input_text, sizeof(input_text), stdin);
    for(loop = 0; loop < sizeof(input_text); loop++) {
      input_dpl[loop] = input_text[loop];
    }
    
    for(loop = 0; loop < sizeof(input_text); loop++) {
      printf("Char %d is, %d\n", loop, input_text[loop]);
    }

    char* p = strtok(input_text, " ");

    
    while (p != NULL) { 
        strSize[strCnt++] = strlen(p);
        p = strtok(NULL, " "); 
    } 
    // for (loop = 0; loop < strCnt; loop++)
    // {
    //     total+=strSize[loop];
    // }    
    printf("Total number of letters: %d\n", total);
    
    double avg = (double)total*100/strCnt;
    

    char* ps = strtok(input_dpl,sentDelim);
    while (ps != NULL) { 
        sentSize[sentCnt++] = strlen(ps);
        ps = strtok(NULL, sentDelim); 
    } 
    for (loop = 0; loop < sentCnt; loop++)
    {
        sentTotal+=strSize[loop];
    }    
    double avgSent = (double)sentCnt*100/strCnt;
 ;
    double index = 0.0588 * avg - 0.296 * avgSent - 15.8;
    int i_round = (int)floor(index);
    printf("The average index is %d\n", i_round);
    return 0;

}
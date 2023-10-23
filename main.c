#include <stdio.h>
#include <string.h> 

int main() {
    printf("Hello World\n");
    int min = 1;
    long max = 1000000;
    long input;
    //scanf("%d", &input);
    input = 123456;
    while(1){
        if(input < min || input > max){
            printf("Invalid input\n");
            scanf("%d", &input);
        }
        else{
            break;
        }
    }
    char one_to_ten[10][10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    char eleven_to_nineteen[9][10] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen", "nineteen"};
    char twenty_to_ninety[8][10] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char hundred[] = "hundred";
    char thousand[] = "thousand";
    char million[] = "million";

    char input_str[7];
    sprintf(input_str, "%07d", input);
    if(input_str[0] != '0'){
        printf("%s %s", one_to_ten[(int)input_str[0] - '0' - 1],million);
    }
    char temp[4];
    printf("TEST\n");
    for(int i = 1; i < 4; i++){
        temp[i - 1] = input_str[i];
    }
    printf("%d \n", atoi(temp));
    
    return 0;
}
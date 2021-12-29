//  Dissanayake D.M.I.H
//  CS WE03

//  Question 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPal(char str[], char b[]);
int checkval(char pwrd[]);

int main () {

    int p = 0;
    int num =0;
    int val = 0;
    int job = 0;
    int len = 0;
    
        printf("\nInput number of passwords:- ");
        scanf("%d", &num);

        if(num > 0 && num <= 100) {      // condition for number of passwords
            printf("Enter the passwords:- \n");
        }
        else {
            printf("!!!\nInput number is invalid\nInput number should be between 1 & 100\n");
       return 0;}

    char passwords[num][14];

    while(p < num){                             
        scanf("%s", passwords[p]);
        
        len = strlen(passwords[p]);      //calling function

        val = checkval(passwords[p]);    //calling function

        if(val == 1)
            p++;
        else {
            printf("!!!\nInvalid password\nPasswords must have odd number of charactors\nPassword length should be between 2 and 14 number of charactors\nPasswords should be only lowercase letters");
        }
    }

    for(int p = 0; p < num-1; p++){

        for(int j = 1; j < num; j++){
            if(p != j){
                
                int palindrome = isPal(passwords[p], passwords[j]);    

                if (palindrome == 1){
                    job++;
                    printf("\n%lu  %c\n",strlen(passwords[p]), passwords[p][strlen(passwords[p])/2]);
                    break;
                }
            }
        } 
        if(job == 1)
            break;
    } 
    
    if(job != 1){
        printf("\nCan not find the password...\n");
    }

    return 0;
} 

//function 1
int checkval(char password[]) {         

    int len = strlen(password);

    
    if(len %2 != 1)                      
        return 0;

    
    else if(len < 2 || len > 14)      
        return 0;
    
    
    else {
        for(int x = 0; x < len; x++) {   
            if(password[x] < 'a' || password[x] > 'z')
                return 0;          
        }
    }
    return 1;
}



//function 2
int isPal(char a[], char b[]) {

    if(strlen(a) != strlen(b)) 
        return 0;

    int p = 0, q = strlen(a), count = 0;

    while(q != 0) {
        if(a[p] == b[--q]) {
            count++;
        }
        else
            break;
        p++;
    }

    if(count == strlen(a)){ 
        return 1;
    }
    else{
        return 0;
    }
}
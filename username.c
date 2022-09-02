#include <stdio.h>
#include <string.h>

int main()
{
char username[20];
printf("Please enter your username: \n");

scanf("%s", username);
printf("Please enter your password: \n");
char password[20];
scanf("%s", password);
    if (!strcmp(username,"Deepak")) 
    {
     if (!strcmp(password, "Rajput90")){
     printf("Welcome!\n");
    }
    
    else
    {
     printf("The user name or password you entered is invalid.\n");
    }
    }
    
}
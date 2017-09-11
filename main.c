//Author : Anouri ilias
//profile git/annouri

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User{
    char first_name[10];
    char last_name[10];
    char email[10];
    char gender[10];
    char company[10];
    char user_name[10];
    char university[10];
    struct User *next_user;
}User;

//Initialise User
User *initialise(){
    User *user=malloc(sizeof(User));
    strcpy(user->first_name,"null");
    strcpy(user->last_name,"null");
    strcpy(user->email,"null");
    strcpy(user->gender,"null");
    strcpy(user->company,"null");
    strcpy(user->user_name,"null");
    strcpy(user->university,"null");
    user->next_user=NULL;
    return user;
}
User *add_user(User *list_user,User *user){
    if(strcmp(list_user->first_name,"null")==0)
        return user;
    else{
        User *temp=initialise();
        temp=list_user;
        while(temp->next_user!=NULL){
            temp=temp->next_user;
        }
        temp->next_user=user;
        return list_user;
    }
};
User * load_user_string(char *data){
    User *user=initialise();
    char *token;
    token=strtok(data,",");
    strcpy(user->first_name,token);
    token=strtok(NULL,",");
    strcpy(user->last_name,token);
    token=strtok(NULL,",");
    strcpy(user->email,token);
    token=strtok(NULL,",");
    strcpy(user->gender,token);
    token=strtok(NULL,",");
    strcpy(user->company,token);
    token=strtok(NULL,",");
    strcpy(user->user_name,token);
    token=strtok(NULL,",");
    strcpy(user->university,token);
    return user;

}
User *load_user(){
    User *list_users=initialise();
    FILE *file;
    file=fopen("faker_db.csv","r");
    char line[1000];
    if (file){
        while (fgets(line,1000,file)!=NULL){
            printf("%s\n",line);
            list_users=add_user(list_users,load_user_string(line));
            fclose(file);
        }

    }
    return list_users;
};
void printf_list_users(User *list_users){
    while (list_users!=NULL)
    {
        printf("%s\t",list_users->first_name);
        printf("%s\t",list_users->last_name);
        printf("%s\t",list_users->user_name);
        printf("%s\t",list_users->email);
        printf("%s\t",list_users->gender);
        printf("%s\t",list_users->company);
        printf("%s\t\n",list_users->university);
        list_users=list_users->next_user;
    }
}
int main() {
    User *list_users=initialise();
    list_users=load_user();
    printf_list_users(list_users);
    return 0;
}
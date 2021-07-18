#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char command[50], arg1[20], arg2[20];

    while(1) {
        printf("Type in DOS commands, hit CTRL+C to exit.\n");
        scanf("%s", command);
        switch(command[0]) {
            case 'c':
                switch (command[1]) {
                    case 'd':
                        printf("\nPlease enter arg to cd: ");
                        scanf("%s", arg1);
                        strcpy(command, "cd ");
                        strcat(command, arg1);
                        system(command);
                        break;
                }
            case 'o':
                switch(command[2]) {
                    case 'p':
                        switch(command[3]){
                            case 'y':
                                printf("\nEnter 1st arg to copy: ");
                                scanf("%s", arg1);
                                printf("\nEnter 2nd arg to copy: ");
                                scanf("%s", arg2);
                                strcpy(command, "cp ");
                                strcat(command, arg1);
                                strcat(command, " ");
                                strcat(command, arg2);
                                system(command);
                                break;
                        }
                } break;
            case 't':
                switch(command[1]) {
                    case 'y':
                        switch(command[2]){
                            case 'p':
                                switch(command[3]){
                                    case 'e':
                                        printf("\n Enter the arg to type: ");
                                        scanf("%s", arg1);
                                        strcpy(command, "cat ");
                                        strcat(command, arg1);
                                        system(command);
                                        break;
                                } break;
                        } break;
                } break;

            case 'r':
                switch(command[1]) {
                    case 'e':
                        switch(command[2]) {
                            case 'n':
                                printf("\nEnter the 1st arg to move: ");
                                scanf("%s", arg1);
                                printf("\nEnter the 2nd arg to move: ");
                                scanf("%s", arg2);
                                strcpy(command, "mv ");
                                strcat(command, arg1);
                                strcat(command, " ");
                                strcat(command, arg2);
                                system(command);
                                break;
                        } break;
                } break;

            case 'd':
                switch(command[1]) {
                    case 'e':
                        switch(command[2]) {
                            case 'l':
                                printf("\n Enter arg to delete: ");
                                scanf("%s", arg1);
                                strcpy(command, "rm ");
                                strcat(command, arg1);
                                system(command);
                                break;
                        }
                    case 'i':
                        switch(command[2]) {
                            case 'r':
                                system("ls");
                                break;
                        }
                }break;

            default:
                printf("\nInvalid input, try again with cd, dir, type, del, ren or copy ");
        }

       
    }

}


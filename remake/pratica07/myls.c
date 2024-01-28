#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <getopt.h>

void listDir(char dirname[], int f_flag, int d_flag, int e_flag)
{
    // if(e_flag == 1)
    //     f_flag = 0;
    
    DIR *dp; 
    char tmp[strlen(dirname)];
    regex_t reegex;
    int value;
    struct dirent *dent;
   
    dp = opendir(dirname); 
    if(dp == NULL)
        return;

    dent = readdir(dp);

    while(dent!=NULL) 
    {
        value = regcomp(&reegex,"[.]",0);
        if(f_flag == 1){
            if(e_flag == 1){
                if(dent->d_type == 8){
                    value = regexec(&reegex, dent->d_name, 0, NULL, 0);
                    if(value != 0)
                        printf("%s%s/%s\n","f ",dirname,dent->d_name);
                }
            }
            else{
                if(dent->d_type == 8)
                    printf("%s%s/%s\n","f ",dirname,dent->d_name);
            }
        }

        if(d_flag == 1){
            if(dent->d_name[0] != '.') // do not list hidden dirs/files
            {
                if(dent->d_type == 4)
                    printf("%s%s/%s\n","d ",dirname,dent->d_name);
            }
        }

        if(e_flag == 1){
            if(dent->d_type == 8){
                value = regexec(&reegex, dent->d_name, 0, NULL, 0);
                if(value == 0)
                    printf("%s%s/%s\n","e ",dirname,dent->d_name);
            }
        }
        dent = readdir(dp);
    }
}   

int main(int argc, char *argv[])
{
    int opt, f_flag, d_flag, e_flag;
    f_flag = 0; d_flag = 0; e_flag = 0;
    int option_index = 0;
    struct option long_options[] = {
            {    "dir",       no_argument, 0, 'd' },
            {    "ext",       no_argument, 0, 'e' },
            {   "file",       no_argument, 0, 'f' },
            {        0,                 0, 0,  0  }
        };
    while ((opt = getopt_long(argc, argv, "fde", long_options, &option_index)) != -1)
    {
        switch (opt)
        {
            case 'f':
                f_flag = 1;
                break;
            case 'd':
                d_flag = 1;
                break;
            case 'e':
                e_flag = 1;
                break;
                /* If getopt() finds an option character in argv that was not included in
                  optstring, or if it detects a missing option argument, it returns '?'
                 */
            default: /* '?' */
                fprintf(stderr, "Bad usage");
                exit(EXIT_FAILURE);
        }
    }

    // printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n", flags, tfnd, nsecs, optind);


    if (optind >= argc)
    {
        fprintf(stderr, "Expected argument after options\n");
        return EXIT_FAILURE;
    }

    for(int i = optind; i < argc; i++){
        printf("%s\n", argv[i]);
        listDir(argv[i], f_flag, d_flag, e_flag);
        printf("\n");
    }

    /* Other code omitted */

    return EXIT_SUCCESS;
}

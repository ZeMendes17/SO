#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
  man opendir
  man readdir
*/

void listDir(char dirname[])
{
    DIR *dp; 
    char tmp[strlen(dirname)];
    
    struct dirent *dent;
   
    dp = opendir(dirname); 
    if(dp == NULL)
        return;

    dent = readdir(dp);

    while(dent!=NULL) 
    {
        if(dent->d_name[0] != '.') // do not list hidden dirs/files
        {
          printf("%s%s/%s\n",(dent->d_type == 4 ? "d " : "  "),dirname,dent->d_name);
          if(dent->d_type == 4){
            strcpy(tmp,dirname);
            listDir(strcat(strcat(dirname,"/"),dent->d_name));
            strcpy(dirname,tmp);
          }
        }
        dent = readdir(dp);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage: %s base_directory\n",argv[0]);
        return EXIT_FAILURE;
    }

    listDir(argv[1]);
    
    return EXIT_SUCCESS;
}


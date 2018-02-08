#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int replace(char *find, char *replace, char *prefix);

int main(int argc,char **argv)
{
  if(argc < 4){
    printf("Wrong Number of Arguments\n");
    exit(-1);
  }

  replace(argv[1],argv[2],argv[3]);
 
 return 0;
}

int replace(char *find, char *replace, char *prefix){
  //open directory
  DIR *dir = opendir("./");
  struct dirent *dp;

  if(dir != NULL){
    //go through each file in directory
    while ((dp = readdir(dir)) != NULL){
      const char *fileName = dp->d_name;

      //get length of file name to help check if it is .txt
      const int FILE_NAME_LENGTH = strlen(fileName);
      
      //only use txt files
      if(strncmp(fileName + FILE_NAME_LENGTH -4, ".txt",4) == 0){
        fprintf(stdout,"Opening %s...\n\n",fileName);
        FILE *file = fopen(fileName,"r");
        //creates temp filename,and pointers
        char temp[] = "temp.txt",*tempLine,*tempWord;
        char line[255];
        FILE *tempFile = fopen(temp,"w");
        int numOfReplaces = 0;
        int lineNum = 1; //keep track of line number

        while(fgets(line,255,file) != NULL){
          //see if find param is in the line
          if(strstr(line,find)){
            tempLine = line;
            while(tempWord = strstr(tempLine,find)){
              fprintf(stdout,"Occurence of %s found on line %d in %s. Replacing with %s\n",find,lineNum,fileName,replace);
              while(tempLine != tempWord){
                fputc(*tempLine,tempFile);
                tempLine++;
              }
              //leave space for the length of find param
              tempWord = tempWord + strlen(find);
              fprintf(tempFile,"%s",replace);
              tempLine = tempWord;
            }
            //put in rest of the line
            while(*tempLine != '\0'){
              fputc(*tempLine,tempFile);
              tempLine++;
            }
            numOfReplaces++;
          }
          else{
            //if no occurence of find is found, just output entire line
            fputs(line, tempFile);
          }
          lineNum++;
        }
        
        //search again but for prefix
        if(numOfReplaces == 0){
          fprintf(stdout,"No occurences of the find param were found. Searching file for prefix...\n");
          fseek(file,0,SEEK_SET);
          fseek(tempFile,0,SEEK_SET);
          lineNum = 1;//keep track of line number

          while(fgets(line,255,file) != NULL){
          //see if prefix param is in the line
          if(strstr(line,prefix)){
            tempLine = line;
            while(tempWord = strstr(tempLine,prefix)){
              fprintf(stdout,"Occurence of %s found on line %d in %s. Replacing with %s\n\n",prefix,lineNum,fileName,find);
              
              while(tempLine != tempWord){
                fputc(*tempLine,tempFile);
                tempLine++;
              }
              //find next space to know how long word is
              char *temp = tempLine;
              char *substringEnd = strstr(temp," ");
              
              //creates substring to be prepended on
              size_t len = substringEnd - temp;
              char *substring = malloc(len + 1);
              if(substring){
                memcpy(substring,temp,len);
              }

              //used to combine the find param and the prefixed substring
              char *combine = malloc(strlen(substring) + strlen(find) + 1);
              strcpy(combine,find);
              strcat(combine,substring);

              tempWord = tempWord + strlen(substring);
              printf("%s\n",tempWord);
              fprintf(tempFile,"%s",combine);

              printf("%s %s\n", substring,combine);

              free(combine);
              free(substring);

              tempLine = tempWord;
            }
            //put in rest of the line
            while(*tempLine != '\0'){
              fputc(*tempLine,tempFile);
              tempLine++;
            }
          }
          else{
            //if no occurence of find is found, just output entire line
            fputs(line, tempFile);
          }
          lineNum++;
          }
        }

        fprintf(stdout,"\nClosing %s...\n\n",fileName);
        fclose(file);
        fclose(tempFile);

        //replaces file with temp
        remove(fileName);
        rename(temp,fileName);
      }
    }

  }

  closedir(dir);
}
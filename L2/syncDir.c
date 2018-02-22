#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

int copyFile(char *pathA, char *pathB, char *file);
int aToB(char *pathA, char *pathB);
int bToA(char *pathB, char *pathA);

int main(int argc,char **argv)
{
  if(argc < 3){
    printf("Wrong number of arguments. Try again.\n");
    exit(-1);
  }

  aToB(argv[1],argv[2]);
  bToA(argv[2],argv[1]);

  printf("%s and %s are now synchronized!\n",argv[1],argv[2]);
  return 0;
}

//copies file from pathA to pathB
int copyFile(char *pathA, char *pathB, char *file){
  char filePathA[255], filePathB[255];
  snprintf(filePathA,255,"%s/%s",pathA,file);
  snprintf(filePathB,255,"%s/%s",pathB,file);

  FILE *fileA = fopen(filePathA, "r");
  FILE *fileB = fopen(filePathB, "w");
  char line[255];
  
  if((fileA != NULL) && (fileB != NULL) ){
    while(fgets(line,255,fileA) != NULL){
      fputs(line,fileB);
    }
    printf("Copied %s to directory %s\n",file,pathB);
    
    fclose(fileA);
    fclose(fileB);
  }
  return 0;
}

//job is to copy files into directory b, and check time stamps to copy files into each other
int aToB(char *pathA, char *pathB){
  DIR *dirA = opendir(pathA);
  struct dirent *dpA;

  if(dirA != NULL){

    while((dpA = readdir(dirA)) != NULL){
      char *fileNameA = dpA->d_name;
                  
      int numOfCopies = 0; //int to check if there are no copies

      DIR *dirB = opendir(pathB);
      struct dirent *dpB;

      if(dirB != NULL){
        while((dpB = readdir(dirB)) != NULL){
          char *fileNameB = dpB->d_name;

          if(strcmp(fileNameA,fileNameB)==0){
            printf("%s was found in both directories.\n", fileNameA);
            char filePathA[255], filePathB[255];
            //appends strings together to form full file path
            snprintf(filePathA,255,"%s/%s",pathA,fileNameA);
            snprintf(filePathB,255,"%s/%s",pathB,fileNameB);

            struct stat attr;
            stat(filePathA, &attr);
            time_t timeA = attr.st_mtime;
            
            stat(filePathB, &attr);
            time_t timeB = attr.st_mtime;
            
            //determine which file gets written over
            if(timeA > timeB){
              copyFile(pathA,pathB,fileNameA);
            }
            else if (timeA < timeB){
              copyFile(pathB,pathA,fileNameB);
            }

            numOfCopies++;
          }
        }
      }
      closedir(dirB);
      //copies file into dirB
      if(numOfCopies == 0){
        printf("%s not found in %s.\n",fileNameA,pathB);
        copyFile(pathA,pathB,fileNameA);
      }
    }

  } 

  closedir(dirA);
  return 0;
}

//job is to delete files from b
int bToA(char *pathB, char *pathA){
  
  DIR *dirB = opendir(pathB);
  struct dirent *dpB;

  if(dirB != NULL){

    while((dpB = readdir(dirB)) != NULL){
      const char *fileNameB = dpB->d_name;
      int numOfCopies = 0; //int to check if there are no copies

      DIR *dirA = opendir(pathA);
      struct dirent *dpA;

      //go through directory A to determine if there are copies
      if( dirA != NULL){
        while((dpA = readdir(dirA)) != NULL){
          const char *fileNameA = dpA->d_name;

          if(strcmp(fileNameA,fileNameB)==0){
            numOfCopies++;
          }

        }
      }
      closedir(dirA);

      //if no copies are found, delete it
      if(numOfCopies == 0){
        printf("%s not found in %s.\n",fileNameB,pathA);
        char filePathB[255];
        snprintf(filePathB,255,"%s/%s",pathB,fileNameB);
        
        remove(filePathB);
        printf("Removed %s from %s\n", fileNameB, pathB);
      }
    }

  } 

  closedir(dirB);
  return 0;
}
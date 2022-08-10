#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *vreme();
int add(FILE *open,char path[30], char ting[2]);
int main(int argc, char *argv[])
{
  FILE *open;
  // samo smeni ja patekata i za sekoja datoteka ke raboti
  add(open,"path/link.txt","a");
  system("PAUSE");	
  return 0;
}

char *vreme()
{
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to compute the current time.\n");  // return EXIT_FAILURE;
    }
    // Convert to local time format. 
    c_time_string = ctime(&current_time);
    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");//return EXIT_FAILURE;
    }
    EXIT_SUCCESS;
    return c_time_string;     
}
int add(FILE *open,char path[30], char ting[2])
{
  char n[2],tekst[100];
  printf("Do you want to empty your files y/n?");
  scanf("%s",&n);
  if(strcmp(n,"y") == 0)
  {
      printf("FIle empty!!!\n"); 
      open = fopen(path,"w");
      fclose(open); 
  } 
      open = fopen(path,ting);
      if(open == NULL)
      {
          printf("Unsuccessful!\n"); 
          return 0;       
      }  
      while(1)
      { 
          printf("Do you want to enter a new link y/n  "); 
          scanf("%s",n);
          if(strcmp(n,"y") == 0)
          {
              printf("Enter LINK: ");   
              scanf("%s",tekst);
              fprintf(open,"LINK: %s TIME: %s",tekst, vreme()); 
              printf("Successful!!!\n");  
          } 
          else{
                   printf("The process is terminated. :/ \n"); // da se prasa dali saka da vidi so ima vo datoteka
                   
                   break;
               }
      }
      fclose(open); 
  return 0;
}

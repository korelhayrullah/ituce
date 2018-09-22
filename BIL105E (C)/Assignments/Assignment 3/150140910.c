/************************************************************/
/*   Name-Surname: Korel Chairoula - 150140910              */
/*   e-mail      : korel_hayrullah@hotmail.com              */
/*   Course Name : BIL 105E - Int to Sci & Eng Computing C  */
/*   Term        : Spring 2015-2016                         */
/*   Assignment  : Homework #3                              */
/************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTER 81


int user_menu(void);//function prototype
int set_ccs(char **ccs);//function prototype
char *sub_string (char *ccs, int begin_index, int end_index);//function prototype
char *remove_string(char **ccs, int begin_index, int end_index);//function prototype
int insert_string(char **ccs, char *insert, int begin_index);// function prototype
int replace_string(char **ccs, char *find, char *replace);//function prototype

int main(){
  //defining variables
  char **ccs, *insert, *find, *replace, *temporary,*temporary2;
  int begin_index, end_index, control,temporary3,temporary4;
  /*****************************************************************************************************************/
  ccs = malloc(3 * sizeof(char *));//memory allocation for three string arrays
  *ccs = NULL; // at the very beginning to be sure *ccs is initialized with NULL
  *(ccs+1) = NULL; //at the very beginning to be sure *(ccs+1) is initialized with NULL
  *(ccs+2) = NULL;//at the very beginning to be sure *(ccs+2) is initialized with NULL
  /*****************************************************************************************************************/

  if (ccs == NULL){ //if ccs or *ccs are NULL then it will do the steps below
    printf("%s\n","Memory allocation unsuccesfull.\n");
    return 0; //terminates the program
  } //end of if

  while(1){ //loop for continuous work until 0 is entered
    control = user_menu();//calling user_menu function

    if (control == 0){
      printf("\nGoodbye!\n");
      free(ccs);
      return 0;
    }
    else if(control == 1){
      set_ccs(ccs);
    }

    else if (control == 2){
      if (*(ccs) == NULL)
        printf("\nYou have to set Current Character Sequence (CCS) before doing any operations!\n\n\n");//end of if
      else{
      printf("Enter the BEGIN INDEX and END INDEX numbers: ");
      scanf("%d %d",&begin_index, &end_index);
      temporary = sub_string(*ccs, begin_index, end_index);
      printf("\n\nCSS:\"%s\"\n",*(ccs));
      printf("Substring(%d,%d): \"%s\"\n\n\n",begin_index,end_index,temporary);
      free(temporary);//freeing temporary
      }//end of else
    }//end of else if

    else if(control == 3){
      if (*(ccs) == NULL)
        printf("You have to set Current Character Sequence (CCS) before doing any operations!\n\n\n"); //end of if
      else{
        printf("Enter the BEGIN INDEX and END INDEX numbers: ");
        scanf("%d %d",&begin_index, &end_index);
        temporary2 = remove_string(&(*ccs), begin_index, end_index);
        printf("\n\nCSS:\"%s\"\n",*(ccs));
        printf("Removed String(%d,%d): \"%s\"\n\n\n",begin_index,end_index,temporary2);
        free(temporary2);//freeing temporary2
      }//end of else

    }//end of else if

    else if (control == 4){
      if (*(ccs) == NULL)
        printf("You have to set Current Character Sequence (CCS) before doing any operations!\n\n\n");//end of if
      else{
        insert = malloc(sizeof(char) * MAX_CHARACTER);
        printf("Enter a new string for insertion: ");
        fgetc(stdin);
        fgets(insert,MAX_CHARACTER,stdin);

        printf("\n\nEnter the BEGIN INDEX number where the new string begins: ");
        scanf("%d",&begin_index);
        temporary3 = insert_string(&(*ccs),insert,begin_index);
        printf("CSS:\"%s\"\n\n\n",*(ccs));

      }//end of else
    }//end of else if

    else if (control == 5){
      if (*(ccs) == NULL)
        printf("You have to set Current Character Sequence (CCS) before doing any operations!\n\n\n");//end of if
      else{
        printf("Find What: ");
        find = malloc(sizeof(char)*MAX_CHARACTER);//memory allocatio for find
        fgetc(stdin);//getting out the \n character
        fgets(find,MAX_CHARACTER,stdin);//getting string for find
        printf("Replace with: ");
        replace = malloc(sizeof(char)*MAX_CHARACTER);//memory allocation for replace
        fgets(replace,MAX_CHARACTER,stdin);//getting string for replace
        temporary4 = replace_string(&(*ccs), find, replace);
        printf("\nThere were %d replacement.\n",temporary4);
        printf("CSS:\"%s\"\n\n\n",*(ccs));
      }


    }//end of else if

    else{
      printf("\nWrong choice entered. Please try again.\n\n\n");//end of else
    }
  }//end of while
  return 0;
}//end of main



//user_menu function which prints the menu for the user
int user_menu(void){
  int control;
  printf("0:Exit the program\n"
         "1:Set Current Character Sequence\n"
         "2:Get Substring\n"
         "3:Remove Substring\n"
         "4:Insert\n"
         "5:Replace\n");
  printf("\nEnter Your Choice: ");
  scanf("%d",&control); //user enters control to choose one of the options printed with the user_menu function
  return control;
}//end of int user_menu

int set_ccs(char **ccs){
  /***************************************************/
  int length; //defining variable
  /***************************************************/
  *ccs = malloc (sizeof(char) * MAX_CHARACTER);//memory allocation for array 1 with the maximum character
  printf("Enter CCS: ");
  fgetc(stdin); //taking the \n character from stdin. Otherwise, fgets does not work!
  fgets(*(ccs),MAX_CHARACTER,stdin);//taking string from the user
  puts("\n");
  length = strlen(*(ccs));
  *(*(ccs)+length-1) = '\0';
  *ccs = realloc(*ccs, sizeof(char) * (length+1)); //reallocating memory for *(ccs)
  if (*ccs == NULL) //checking if *css is NULL
    return -1;
  return (length + 1) * sizeof(char);
}//end of int set_ccs

char *sub_string (char *ccs, int begin_index, int end_index){
  /***************************************************/
  char *temporary; //defining variables
  int allocation,i,j = 0;
  /***************************************************/
  if (begin_index >= (int)strlen(ccs) || end_index >= (int)strlen (ccs))//checking whether begin_index and end_index is in the css bound
    return NULL;
    //end of if
  else{
      allocation = (end_index - begin_index) + 2;
      temporary = malloc(sizeof(char) * allocation);//memory allocation for temporary array with the maximum character
      for (i = begin_index ; i <= end_index;i++){
        *(temporary + j) = *(ccs + i); //taking characters starting from begin_index to end_index and equalizing them to temporary
        j++;
      }
      *(temporary + j) = '\0';//adding end of character to temporary
      return temporary;
  }//end of else
}//end of char *sub_string

char *remove_string(char **ccs, int begin_index, int end_index){
  /***************************************************/
  char *temporary2,*hold;//defining variables
  int allocation,length,reallocation,i,j = 0;
  /***************************************************/
  if (begin_index >= (int)strlen((*ccs)) || end_index >= (int)strlen((*ccs)))//checking whether begin_index and end_index is in the css bound
    return NULL;
    //end of if

  else{
    allocation = (end_index - begin_index) + 2;
    length = strlen(*(ccs));//getting length of (*(ccs))
    reallocation = length - allocation; //calculations to get enough memory for hold
    *(ccs+1) = malloc(sizeof(char)* (begin_index + 1));//allocating memory for *(ccs+1) at the first case to get enough memory until begin index
    hold = malloc(sizeof(char) * (reallocation +2));//allocating enough memory for hold

    temporary2 = malloc(sizeof(char) * allocation);

    for (i = begin_index ; i <= end_index;i++){
      *(temporary2 + j) = *(*(ccs)+i);//taking characters from the original taken string and equalizing to temporary2 which will return after the characters removed from the string
      j++;
    }//end of for
    *(temporary2 + j) = '\0';//adding end of file character to temporary2


    for (i = 0; i < begin_index;i++)
      *(*(ccs+1)+i) = *(*(ccs)+i);//taking characters from the original taken string and equalizing to hold which is the left side's remaining characters until begin index
      //end of for
    j = 0;
    for (i = (end_index+1);i < length;i++){
      *(hold+j) = *(*(ccs)+i);//taking characters from the original taken string and equalizing to hold which is the right side's remaining characters after end index
      j++;
    }//end of for

    *(hold + j) = '\0';//adding end of file character to hold

    *(ccs+1) = realloc(*(ccs+1),sizeof(char) * ((length - allocation) + 2));//reallocating memory for *(ccs+1) which before it was just until begin index + 1. Now it is enough for to concatenated space
    strcat(*(ccs+1),hold);//concatenation of *(ccs+1) and hold


    *(ccs)= realloc(*(ccs),sizeof(char)*((length - allocation) + 2)); //reallocating memory for *(ccs)

    for (i = 0;i <= ((length - allocation)+1);i++){
      *(*(ccs)+i) = *(*(ccs+1)+i);//copying *(ccs+1) to *(ccs+0)
    }//end of for
    *(*(ccs)+i) = '\0';//adding terminating character to *(ccs)

    return temporary2;
    }//end of else


}//end of char *remove_string

int insert_string(char **ccs, char *insert, int begin_index){
  /***************************************************/
  int length,length2,length3,i,j = 0;//definin variables
  /***************************************************/

  if (begin_index >= (int)strlen((*ccs))+1)//checking whether begin_index is in the css bound.The +1 is is the user wants to add at the end of the string something
    return -1;
    //end of if
  else{
    length = strlen(*(ccs));
    *(ccs+1) = malloc(sizeof(char) * begin_index);//memory allocation just enough for *(ccs+1)
    for (i = 0; i < begin_index;i++)
      *(*(ccs+1)+i) = *(*(ccs)+i);//taking characters until begin index and keeping them at (*ccs+1)
      //end of for

      insert = realloc(insert, sizeof(char)* (strlen(insert)));//reallocating memory just enough for insert
      *(insert+(strlen(insert)-1)) = '\0'; //adding terminating character to insert

      *(ccs+1) = realloc(*(ccs+1),sizeof(char) * (begin_index + (strlen(insert)+1)));
      strcat(*(ccs+1),insert);//concatenation of *(ccs+1) and insert

      length2 = strlen(*(ccs))- begin_index;

      *(ccs+2) = malloc(sizeof(char) * (length2 + 1));//memory allocation for *(ccs+2)

      for (i = begin_index;i <= strlen(*(ccs))-1;i++){
        *(*(ccs+2)+j) = *(*(ccs)+i);
        j++;
      }
      *(*(ccs+2)+j) = '\0';//adding terminating character to *(ccs+2)


      length3 = strlen(insert) + strlen(*(ccs));
      *(ccs+1) = realloc(*(ccs+1),sizeof(char) * (length3 + 1));

      strcat(*(ccs+1),*(ccs+2));//concatenation of *(ccs+1) and *(ccs+2)

      *(*(ccs+1)+(length3 + 1)) = '\0';//adding terminating character to the finished and concatenated string
      *(ccs)= realloc(*(ccs), sizeof(char) * (length3 +1));

      for(i = 0; i < (strlen(*(ccs+1)));i++)
        *(*(ccs)+i) = *(*(ccs+1)+i);//copying *(ccs+1) to *(ccs+0)
      //end of for//adding terminating character to *(ccs)

      if (*ccs == NULL) //checking if *css is NULL
        return -1;
      return (strlen(*ccs) + 1) * sizeof(char);
  }

}//end of int insert_string

int replace_string(char **ccs, char *find, char *replace){
  /***************************************************/
  unsigned int counter = 0;
  int i = 0,j,begin_index,end_index;//defining varaiables
  /***************************************************/

  *(find+strlen(find)-1) = '\0';//adding terminating character to find
  find = realloc(find, sizeof(char) * strlen(find));//reallocating memory for find
  *(replace+strlen(replace)-1) = '\0';//adding terminating character to find
  replace = realloc(replace, sizeof(char) * strlen(replace));//reallocating memory for replace


for(i = 0; i < strlen(*(ccs));i++){
  if(*(find) == *(*(ccs)+i)){
    begin_index = i;
    end_index = i - 2;
    end_index++;

    for (j = 0;j <= strlen(find);j++){
      end_index++;



      if(*(find+j+2) == '\0'){
        remove_string(ccs, begin_index, (end_index - 1));
        insert_string(ccs,replace,begin_index);
        //insert_string(ccs, replace, begin_index);
        counter++;//incrementing counter by 1
        i = i - 2;
        break;
      }
            if(*(find+j) != *(*(ccs)+i))
        break;
        //end of if
      i++;//incrementing i by 1
    }
  }
}
  return counter;
}//end of int replace_string

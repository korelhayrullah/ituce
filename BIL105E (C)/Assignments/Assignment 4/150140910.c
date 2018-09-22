/************************************************************/
/*   Name-Surname: Korel Chairoula - 150140910              */
/*   e-mail      : korel_hayrullah@hotmail.com              */
/*   Course Name : BIL 105E - Int to Sci & Eng Computing C  */
/*   Term        : Spring 2015-2016                         */
/*   Assignment  : Homework #4                              */
/************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define BOLDRED "\033[1m\033[31m"
#define RESET "\033[0m"
//BOLDRED and RESET definitions are just for fun which I discovered and wanted it to add to this program just for good-looking :)


  typedef struct{//declaring struct
    int personId;
    double height;
    double weight;
    double BMI;
    }person;

  FILE *in;//declaring file pointer for input
  FILE *out;//declaring file pointer for output

int main(int argc, char** argv){//taking arguments to main function

  /*****************************************************************/
  int N,M,i,j;
  char **titles;
  double tmp_BMI,tmp_Height,tmp_Weight,tmp_difference,threshold;
  int tmp_personId;//declaring variables
  /*****************************************************************/

  N = atoi(argv[1]);//counter for N (array to integer) and converting it to integer since it is taken as string
  person people[N];//struct array for N

  double difference[N];//declaring variable
  M = atoi(argv[2]);//counter for M (array to integer) and converting it to integer since it is taken as string
  threshold = atof(argv[3]);//counter for threshold (array to float)



  if(M > N){//checking arguments
    printf(BOLDRED"WARNING!!!"RESET" Second argument(N) can not be greater than the Third argument(M).\n");
    exit(1);
  }

/***************************************************************************/
  titles = malloc(sizeof(char*) * 3);//allocating memopry for titles
  *(titles)= malloc(sizeof(char) * 15);//allocating memopry for *(titles)
  *(titles+1) = malloc(sizeof(char)* 15);//allocating memopry for *(titles+1)
  *(titles+2) = malloc (sizeof(char)* 15);//allocating memopry for *(titles+2)
/***************************************************************************/

  if ((in = fopen("height_weight.txt","r")) == NULL){//if file is NULL error will be given and exited
    printf(BOLDRED"Input.txt could not be opened.\n"RESET);
    exit(1);
  }

  if ((out = fopen("output.txt","w")) == NULL){//if file is NULL error will be given and exited
    printf(BOLDRED"Output.txt could not be opened.\n"RESET);
    exit(1);
  }

  fscanf(in,"%s %s %s",*(titles),*(titles+1),*(titles+2));//scanning titles from height_weight.txt file(which is input)

  *(titles)= realloc(*(titles),sizeof(char) * (int)(strlen(*(titles))));//reallocating memory just enough for 1st string
  *(titles+1)= realloc(*(titles+1),sizeof(char) * (int)(strlen(*(titles+1))));//reallocating memory just enough for 2nd string
  *(titles+2)= realloc(*(titles+2),sizeof(char) * (int)(strlen(*(titles+2))));//reallocating memory just enough for 3rd string


  for (i = 0 ; i < N;i++){
    //getting people.Id, people.height, people.weight from the height_weight.txt input file
    fscanf(in,"%d %lf %lf",&people[i].personId,&people[i].height,&people[i].weight);
  }


  if(people[N-1].personId < N){//checking wheter the number N is greater than the total people from the input text file
    printf(BOLDRED"WARNING!!!"RESET" The second argument(N) is bigger than the total people in the provided input text file.\n");
    exit(1);
  }


  for(i = 0; i < N;i++){
    //calculating BMI, finding the difference from calculated BMI values and calculating absolute value of difference
    people[i].BMI = people[i].weight / ((people[i].height * people[i].height) / 10000);
    difference[i] = people[i].BMI - threshold;
    difference[i] = fabs(difference[i]);
  }


  //a simple bubble sort for sorting the struct
  for(i = 0;i < N - 1;i++){
    for(j = 0;j < N - i - 1;j++){
      if(difference[j] < difference[j+1]){
        tmp_BMI = people[j].BMI;
        tmp_Height = people[j].height;
        tmp_Weight = people[j].weight;
        tmp_personId = people[j].personId;
        tmp_difference = difference[j];

        people[j].BMI = people[j+1].BMI;
        people[j].height = people[j+1].height;
        people[j].weight = people[j+1].weight;
        people[j].personId = people[j+1].personId;
        difference[j] = difference[j+1];

        people[j+1].BMI = tmp_BMI;
        people[j+1].height = tmp_Height;
        people[j+1].weight = tmp_Weight;
        people[j+1].personId = tmp_personId;
        difference[j+1] = tmp_difference;
      }
    }
  }


  fprintf(out,"|---------------------------------------------------------------------|\n");
  fprintf(out,"|%s|%14s|%14s|%9s|%19s|\n",*(titles),*(titles+1),*(titles+2),"BMI","|BMI-Threshold|");//printing the headers to output.txt
  fprintf(out,"|---------------------------------------------------------------------|\n");


  for (i = 0 ; i < M;i++){
    //printing all datas on output.txt
    fprintf(out,"|%9d| %13.0lf| %13.0lf| %8.2lf| %18.2lf|\n",people[i].personId,people[i].height,people[i].weight,people[i].BMI,difference[i]);
    fprintf(out,"|---------------------------------------------------------------------|\n");
  }


  fclose(in);//closing input file
  fclose(out);//closing output file
  free(*(titles));//freeing allocated memory for *(titles)
  free(*(titles+1));//freeing allocated memory for *(titles+1)
  free(*(titles+2));//freeing allocated memory for *(titles+2)
  free(titles);//freeing allocated memory for titles


  return 0;
}//end of main

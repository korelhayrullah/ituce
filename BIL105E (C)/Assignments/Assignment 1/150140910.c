/**********************************************************************************************/
/*Student Name: Korel Chairoula -- Student ID:150140910 -- e-mail: korel_hayrullah@hotmail.com*/
/**********************************************************************************************/
#include <stdio.h> /*this is the standard library*/
#include <stdlib.h> /*this library is used for the function "srand"*/
#include <time.h> /*this libraryu is used for the function "time"*/

int main(){

	/*all the variables that used in the program*/
	int players, probability, passes, countPasses, targetScore, randomTeam, randomPlayer1, randomPlayer2, randomProbability;
	int Team1 = 0;
	int Team2 = 0;
	/*Takes inputs from the user below*/
	printf("Enter the number of players per team (N)\n");
	scanf("%d",&players);
	printf("Enter the probability of succesful pass (P)\n");
	scanf("%d",&probability);
	printf("Enter the number of passes to win a single round (W)\n");
	scanf("%d",&passes);
	printf("Enter target score (S)\n");
	scanf("%d",&targetScore);
	/*srand is used for generating random numbers while seeding with the time function to get every time a different random number*/
	srand(time(NULL));

	/*the loop "for" below, loops for every round and increments round counter by one in every loop*/
	for(int countRound = 1;;countRound++ ){
		printf("Round-%d:\n",countRound);

		randomTeam = 1 + rand() % 2; /*generates random team number which is going to start*/

		printf("\tTeam%d is selected.\n",randomTeam);

		randomPlayer1 = 1 + rand() % players;/*generates random player number*/

		printf("\tPlayer%d ", randomPlayer1);

		countPasses = 1;

		/*the statement "while" below looks if the counted passes are smaller than the passes entered from the user*/
		while(countPasses < passes){
			randomProbability = 1 + rand() % 100; /*generates random probability rate from 1 to 100*/
			/*the statement "if" below checks the probability rate entered by the user between random generated probability*/
			if(randomProbability <= probability){
				countPasses++;
				randomPlayer2 = 1 + rand() % players;/*generates random player*/
				/*the statement "while" below prevents collapsing the randomly assigned numbers*/
				while(randomPlayer1 == randomPlayer2){
					randomPlayer2 = 1 + rand() % players;
				}
				randomPlayer1 = randomPlayer2;

				printf("-> Player%d",randomPlayer2);

			}
			else{
				/*The statement "if" below checks which team has captured the ball if the above statements are not true.If the above ones success this statement is skipped*/
				if(randomTeam == 1){
					randomTeam = 2;/*this is for switching the teams*/
					countPasses = 1; /*resets counted passes*/
					printf("\n\tTeam%d captured the ball!\n", randomTeam);
					randomPlayer1 = 1 + rand() % players;
				}

				else {
					countPasses = 1; /*resets counted passes*/
					randomTeam = 1; /*this is for switching the teams*/
					printf("\n\tTeam %d captured the ball!\n", randomTeam);
					randomPlayer1 = 1 + rand() % players;
				}

				printf("\tPlayer%d ", randomPlayer1);
			}
		}
		/*the satetement "if" below checks the given passes by the user with the passes incremented when successful passes happens by the selected team*/
		if(countPasses == passes){

			/*the statement "if" below checks for the team's successful passes and increments it by one */
			if(randomTeam == 1){
				Team1++;
				printf("\n\tSuccess! The new score of Team1 is %d\n\n",Team1);
			}

			else{
				Team2++;
				printf("\n\tSuccess! The new score of Team2 is %d\n\n",Team2);
			}

			/*the statement "if" checks if the one of the two teams has reached the target score*/
			if(Team1 == targetScore || Team2 == targetScore){

		/*the if statement below is used for separating the teams when reached the target score the user entered in*/
		if(Team1 == targetScore){
			printf("GAME OVER: Team1 reached the target score (%d) and won the game.\n",targetScore);
			break;
		}

		else{
			printf("GAME OVER: Team2 reached the target score (%d) and won the game.\n",targetScore);
			break;
		}

	 }
	}
 }
	return 0;
}

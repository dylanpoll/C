//libraries list 
#include <stdio.h>
#include <stdlib.h>  // rand(), srand()
#include <time.h>    // time()
#include <string.h>



//structures start
struct RACE_INFO
{   
    char dog_name[20];
    char bet_name[20];
    int wager;
};

//function list 
float results(struct RACE_INFO *Races, int current_race); 	//log of races, will use arrays
float wager(struct RACE_INFO *Races, int current_race); 		//place bet and select from dogs
float race(struct RACE_INFO *Races, int current_race);		//rolls for dog race resaults
float balance();	//Gregs current balance
char dognames();	//holds the dog names

int main(void) 
{
	//initializations
	int running = 1; 	//terminates the program
	char select; 	//for selecting the menu 
    int current_race = 0;

    struct RACE_INFO Races[100] = {};

	// below is a user greeting for when the program is first run, wont print again.
	printf("Hello greg~! I have been expecting you...\n");
	printf("Welcome to the gambling pit!\n");
    
    

    do{
		//menu print
		printf("\n");
		printf("please make a selection!\n");
		printf("[G]amble\n");				/*the program will ask Greg for his wager and allow Greg to pick a dog from a list. The program will 
										then run the race. The result will be shown to Greg. The results of the race will be stored for future use.*/
		printf("[R]esults of All Races\n");	//the program will show Greg the results of all previous races entered during this run of the program.
		printf("[L]eave the Dog Track\n"); 	//the program will end.
	
	
		scanf(" %c", &select); //get user input, the space eliminated whitespace so the loop wont end
		printf("\n");
		
    		switch(select){
    		case 'g':
   				wager(Races, current_race);
                current_race += 1;
    			break;
    		case 'G':
   				wager(Races, current_race);
                current_race += 1;
    			break;
			case 'r':
       		 	results(Races, current_race);
    			break;
    		case 'R':
       		 	results(Races, current_race);
    			break;
    		case'l':
    			printf("ending program~! \n");
    			running = 0;
                break;
			case'L':
    			printf("ending program~! \n");
    			running = 0;
                break;
			default:
				if(select !=' '){
    		    printf("invalid input, please select again! \n");
  	  				}
				break;
    			}
		}while(running);
    return 0;
}

char dognames()
{
    printf("Dogs Names: ");
    printf("Bernie, Leo, Cat, Tofu, Sloth, Nimbus, Atmel, Rudolf, Guifuerry \n");
    /*
    --name		pays		odds---
    Bernie		2 to 1 		40%
    Leo			5 to 1		10%
    Cat			10 to 1		8%
    Tofu		15 to 1		6%
    Sloth		50 to 1		1%
    Nimbus		20 to 1		4%
    Atmel		10 to 1		8%
    rudolf		5 to 1		10%
    Guifuerry	3 to 1		13%
    ------
    */
    return 0;
}

float results(struct RACE_INFO *Races, int current_race)
{
    printf("Race results:\n");
    int i = 0;
    
    for (i = 0 ; i < current_race; i++)
    {
        printf("Race #%d\n", i+1);
        printf("Winner dog's name: %s\n", Races[i].dog_name);
        printf("Greg dog's name: %s\n", Races[i].bet_name);
        printf("Greg money won: %d\n\n", Races[i].wager);
    }
}

float wager(struct RACE_INFO *Races, int current_race)
{
    //char *dogs[9] = {"Bernie", "Leo", "Cat", "Tofu", "Sloth", "Nimbus", "Atmel", "Rudolf", "Guifuerry"};
	float wager;
    dognames();
    char name[20];
    printf("Choose your dog name: ");
	scanf("%s", name);
	printf("Please place your bet! : ");
	scanf("%f", &wager);
	printf("\n");
    
    strcpy(Races[current_race].bet_name, name);
    Races[current_race].wager = wager;

    race(Races, current_race);	
}

float race(struct RACE_INFO *Races, int current_race)
{
    
	int winner = 0;
    char winner_name[20];
    int pays = 1;

    time_t t;

    srand((unsigned) time(&t));
    int num = (rand() % 100);     

    //Compare with dogs odds
    if (num <= 40)
    {
        strcpy(winner_name, "Bernie");
        pays = 2;
    }
    else if (num > 40 && num <= 50)
    {
        strcpy(winner_name, "Leo");
        //winner_name = "Leo";
        pays = 5;
    }
    else if (num > 50 && num <= 58)
    {
        strcpy(winner_name, "Cat");
        //winner_name = "Cat";
        pays = 10;
    }
    else if (num > 58 && num <= 64)
    {
        strcpy(winner_name, "Tofu");
        //winner_name = "Tofu";
        pays = 15;
    }
    else if (num > 64 && num <= 65)
    {
        strcpy(winner_name, "Sloth");
        //winner_name = "Sloth";
        pays = 50;
    }
    else if (num > 65 && num <= 69)
    {
        strcpy(winner_name, "Nimbus");
        //winner_name = "Nimbus";
        pays = 20;
    }
    else if (num > 69 && num <= 78)
    {
        strcpy(winner_name, "Atmel");
        //winner_name = "Atmel";
        pays = 10;
    }
    else if (num > 78 && num <= 88)
    {
        strcpy(winner_name, "Rudolf");
        //winner_name = "Rudolf";
        pays = 5;
    }
    else if (num > 88 && num <= 100)
    {
        strcpy(winner_name, "Guifuerry");
        //winner_name = "Guifuerry";
        pays = 3;
    }
      
    strcpy(Races[current_race].dog_name, winner_name);

    if(strcmp(Races[current_race].dog_name, Races[current_race].bet_name) == 0)
    {
        printf("Greg wons!\n");
        Races[current_race].wager *= pays;
        printf("Winner dog: %s\n", Races[current_race].dog_name);
        Races[current_race].wager = 0;
        
    }
    
    else
    {
        printf("Greg lost...\n");
        printf("Winner dog: %s\n", Races[current_race].dog_name);
        Races[current_race].wager = 0;
    }
}




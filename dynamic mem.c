#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

typedef struct square{
	int num;
	int length;
} square;

int main(){
	int loop = 1;
do{
	int arrayLen = 0, i, j;
		char select;
do{
	printf("    *********************************************** \n");
	printf("\n");
	printf("\n");
	printf(" **                 MAIN   MENU                     ** \n");
	printf("\n");
	printf("\n");
	printf("    *********************************************** \n");
	printf("E) use this program\n");
	printf("Q) Quit");
	printf("\n");
	scanf(" %c", &select);
if(select == 'E' || select == 'e'){
		square **list = NULL;
		srand(time(0)); 
		
		printf("Please enter a number you like: ");
		scanf(" %d", &arrayLen);
		
		list = malloc(arrayLen * sizeof(square*));
		
		printf("Generating %d square of random length.\n", arrayLen);
		
			 if (list == NULL){
		            printf("Memory Allocation Error\n");
		            exit(0);
		       	 }
				   else {
				       printf("Memory Has Been Allocated\n");   
				       }        
		   					 for(i=0; i<arrayLen; i++){
					        	list[i]=malloc(sizeof(square));
					        	list[i]->num = i+ 1;
								list[i]->length= (rand() % 
					           (100 - 2 + 1)) + 2;
				}
		printf("Printing all squares....\n");
			
			for(j=0; j<arrayLen; j++){
		       	printf("square number: %d, length: %d\n" , list[j]->num,
		       	list[j]->length);
				}
		printf("freeing up memory.....\n");
				
			for(j=0; j<arrayLen; j++){
		        	free(list[j]);
				}
		free(list);
		}
	
}while(select == 'e' || select == 'E');
if(select == 'q'){
return 0;
}
if(select == 'Q'){
return 0;
}
}while(loop == 1);
}


 #include <stdio.h>
#include <stdlib.h>

// Here the parameter is an array of pointers
int assign(int** arr, int id, int stat)
{
	int i,j;
	
	for (i = 0; i < id; i++) {
		for (j = 0; j < stat; j++) {
			arr[i][j] = i + j;
		}
	}
}



// Program to pass 2D array to a function in C
int main()
{
	int columns; //columns
	int rows,i,j; // rows

		int p,z;
		
	printf(" please enter how many columns you want in the array :");
		scanf("%i", &p);
		
   	printf("\nplease enter how many rows you want in the array :");
   		scanf(" %i", &z);
   	printf("\n");
   	
 columns = p;
 rows = z;  	
	// dynamically create array called games of pointers of size id
	int **games = (int **)malloc(rows * sizeof(int *));

	// dynamically allocate memory of size stat for each row
	for (columns = 0; columns < rows; columns++)
		games[columns] = (int *)malloc(rows * sizeof(int));

	assign(games, rows, columns);
	
		// print 2D array
	
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			printf("%3d", games[i][j]);
		}
		printf("\n");
	}

	// deallocate memory
	for (i = 0; i < rows; i++)
		free(games[i]);
	free(games);

	return 0;
}

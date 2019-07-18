/* Implementation of The Josephus Problem using the C language.

   There are many different ways to implement this problem. The one that is being 
   presented here sure it's not the most effective method but, in my opinion, it is 
   the most natural to think.

	-----Description of the Problem:

	Soldiers are standing in a circle waiting to be killed. Counting begins at a specified 
	point in the circle and proceeds around the circle in a specified direction. The first
	soldier kills the soldier (that's still alive) next to him, then the next soldier in the
	circle (still alive) kills the next soldier (still alive) next to him. This goes on till
	there's only one soldier left (the one that survived).

	The problem — given the number of soldier — is to choose the position in the initial circle to 
	avoid execution.

	-----Example:

	Let´s imagine that there are 5 soldiers. In which position is the soldier that is going to survive?
	(A) - alive. 
	(D) - dead.

	soldiers = [1(A), 2(A), 3(A), 4(A), 5(A)] 
	soldiers = [1(A), 2(D), 3(A), 4(A), 5(A)] (1 killed 2)
	soldiers = [1(A), 2(D), 3(A), 4(D), 5(A)] (3 killed 4)
	soldiers = [1(D), 2(D), 3(A), 4(D), 5(A)] (5 killed 1)
	soldiers = [1(D), 2(D), 3(A), 4(D), 5(D)] (3 killed 5)

	So, the soldier in the 3rd position survived!
*/

#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996) //visual studio gives a warning about the use of scanf (it suggests to use scanf_s).

int evaluateNumberSoldiersAlive(int *vec, int max); //function that evaluates the number of soldiers that are still alive.
void printDetails(int* vec, int max); //prints the details for each round (showing the soldiers still alive).

void main(void)
{
	int num = 0; //number of different situations that we are going to evaluate. 
	int details = 0; //if details = 1, it shows the details of each round for every situation.
	int i = 0, j = 0, m = 1;
	int *soldiers; //represents the circle of soldiers. Which element survived[i] represents a soldier.
	int *survived; //in the element survived[i] is going to be saved the number of the soldier that survived in the situation with i+1 soldiers.
	int currentlymax = 0; //represents the number of soldiers alive at the beginning.
	int flag1 = 0, flag2 = 0;
	int survive = 0;

	do
	{
		flag1 = 0;

		/* Observation: if the user insertes 5 (and therefore, num = 5), is it is going to be evaluated the
			soldier that survives in the situation of a circle with 1 soldier, 2 soldiers, 3 soldiers, 4 soldiers and 5 soldiers.
			So, it is going to be evaluated 5 situations (from 1 to 5).
		*/
		printf("\nInsert the maximum number of soldiers: ");

		if (scanf("%d", &num) == 1) //if successful, scanf returns the total number of characters written, otherwise a negative number is returned.
		{
			if (num <= 0)
			{
				printf("\nThe number of maximum soldiers can not be 0 or less!");
				flag1 = 1;
			}
		}
		else
		{
			printf("\nIt was not possible to read the number!");
			flag1 = 1;
		}

		printf("\nDo you want to see details for each round? ");
		printf("\n|1| - Yes.");
		printf("\n|2| - No.");
		printf("\nInsert your option: ");
	
		if (scanf("%d", &details) == 1)
		{
			if (!((details == 1) || (details == 2)))
			{
				printf("\nThe option inserted is not acceptable!");
				flag1 = 1;
			}	
		}

	} while (flag1); //loops until the number inserted is acceptable.

	printf("\n");

	survived = (int*) malloc(num * (sizeof(int)));

	for (i = 0; i < num; i++)
	{
		currentlymax = i + 1;
		soldiers = (int*) malloc(currentlymax * (sizeof(int))); 

		for (j = 0; j < currentlymax; j++)
			soldiers[j] = 1; //declares every soldier as alive (1 = alive / 0 = dead).

		j = 0;
		m = 0;

		if (details == 1)
		{
			printf("\n\n\n**********");
			printf("Situation: %d soldiers", i + 1);

			printDetails(soldiers, currentlymax);
		}
		

		while ((survive = evaluateNumberSoldiersAlive(soldiers, currentlymax)) == -1)  //loops until there's only one soldier alive.
		{
			m = 0;

			if (soldiers[j] == 1) //if soldier j is alive it can kill.
			{
				m = j + 1;
				flag2 = 0;

				do
				{
					if (m >= currentlymax)
						m = 0;

					if (soldiers[m] == 1) //if the next player is alive.
					{
						soldiers[m] = 0; //declares that next player as dead.
						flag2 = 1; //a soldier was killed.

						if (details == 1)
							printDetails(soldiers, currentlymax);

					}
					else if (soldiers[m] == 0) //if soldier (m) is already dead, let´s see soldier(m + 1).
						m++;

				} while (!flag2); //loops until a soldier was killed.
			}
			
			j++;

			if (j == currentlymax)
				j = 0;
		}

		printf("\n---For the situation with %d soldiers, survived number %d.", i+1, survive + 1);
	}	

	printf("\n\n\n");
}


int evaluateNumberSoldiersAlive(int* vec, int max)
{
	int i = 0;
	int j = 0;
	int survived = 0;

	for (i = 0; i < max; i++)
	{
		if (vec[i] == 1)
		{
			j++;
			survived = i;
		}
	}

	if (j == 1)
		return survived; //if there's only one soldier alive, it returns the number of that soldier.
	else
		return -1; //if there's more than 1 soldier alive, it returns -1.
}

void printDetails(int* vec, int max)
{
	int d = 0;

	printf("\nSoldiers Still Alive = { ");

	for (d = 0; d < max; d++)
	{
		if (vec[d] == 1)
			printf(" %d ", d + 1);
	}
	printf(" }");
}
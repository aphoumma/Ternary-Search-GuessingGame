/*

Alex Phoummalayvane
CSC 2560
GUESSING GAME LOGIC (using ternary search)

This program creates a guessing game and uses a ternary search algorithm to find the answer. Also displays CHEATER message.

1.) The program asks for a two numbers to be stored in the low bound and high bound variables respectively.

2.) The search space is calculated by taking the high bound and subtracting the low bound. The secret number must be within the search space.

3.) The number of partitions counts the number of times the search space is split in half.

4.) A while loop is used because the program will keep running until the given condition (secret number found or caught cheating) is satisfied.

5.) If the secret number is guessed, a winners message is printed

6.) Cheater is caught if there are no more possible partitions to make and flag variable "guessed" has not been marked as true yet.

7.) The ternary search algorithm works by dividing the problem in thirds and then updating the search space and dividing in thirds repeatedly.

*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	int low = 0;
	int high = 0;
	int middle1 = 0;
	int middle2 = 0;
	int counter = 0; // question counter
	char answer = '0'; 
	int  search_space = 0;
	int number_of_partitions = 0;
	int guessed = 0; // This is a flag variable to represent true (1) or fale (0). If the number has been found, this will change to true. 


	printf("Please pick a lower bound.\n");
	scanf("%d", &low);
	printf("Please pick an upper bound greater by more than four than lower bound.\n");
	scanf("%d", &high);
	printf("Your number must be between %d and %d.\n", low, high);



	search_space = high - low;
	while (search_space != 0) // keep looping while search space is not zero 
	{
		// cut searchspace by thirds and increment the number of partitions
		search_space = search_space / 3;
		number_of_partitions = number_of_partitions + 1;


	}
	printf("I will find out your number with maximum %d questions\n", number_of_partitions + 1);

	// keep looping while low bound is less than or equal to high bound number
	while (low <= high && high != 0)
	{
		middle1 = low + (high - low) / 3;   // ternary search splits problem in thirds
		middle2 = high - (high - low) / 3;
		counter++; //increment question counter each time 
		printf("Question #%d\n", counter);


		printf("Enter E if your number is equal to %2d \n", middle1);
		printf("Enter R if your number is equal to %2d \n", middle2);
		printf("Enter S if your number is smaller then %2d \n", middle1); 
		printf("Enter G if your number is larger then %2d \n", middle2);
		scanf(" %c", &answer);



		if (answer == 'E' || answer == 'e') {
			guessed = 1; // mark flag variable as true which means secret num has been guessed
			printf("Told you so I'd win!\n");
			printf("I did it with %d questions \n", counter);
		}

		if (answer == 'R' || answer == 'r') {
			guessed = 1; // mark flag variable as true which means secret num has been guessed
			printf("Told you so I'd win!\n");
			printf("I did it with %d questions \n", counter);
		}

		if (answer == 'S' || answer == 's')
		{
			high = middle1 - 1;
		}
			else if (answer == 'G' || answer == 'g')
			{
				low = middle2 + 1;
			}
			else
			{
				low = middle1 + 1;
				high = middle2 - 1;
			}



		if (guessed == 1)
			low = high + 1;



	}

	// If search space is less than or equal to zero, there are no other partitions to make and the number must have been found already
	// If flag variable called "guessed" is not equal to 1, that means the secret number has not been marked as guessed
	// If there are no other partitions to make AND the answer has not been found, then a cheater message will display
	if (search_space<=0 && guessed != 1)
		printf("CHEATER! The answer has been found already \n");


	printf("Goodbye!\n");

}

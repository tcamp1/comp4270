#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int randomNumber(){
	return (random() % 4) + 1;
}

int main()
{
	int someRandomNumber;

	pid_t child1ID;
	pid_t child2ID;

	pid_t stopID1;
	pid_t stopID2;

	int status1;
	int status2;

	time_t currentTime;

	srandom(time(NULL));

	if ((child1ID = fork()) == 0) { 
		someRandomNumber = randomNumber();
		printf("Child 1 randomNumber %i seconds\n", someRandomNumber);
		sleep(someRandomNumber);
		time(&currentTime);
		printf ("Hello world from child 1 at %s \n", ctime(&currentTime));
	}

	if ((child2ID = fork()) == 0){
		someRandomNumber = randomNumber();
		printf("Child 2 randomNumber %i seconds\n", someRandomNumber);
		sleep(someRandomNumber);
		time(&currentTime);
		printf("Hello world from child 2 at %s \n", ctime(&currentTime));
	}

	if (child1ID > 0 && child2ID > 0) { 
		stopID1 = waitpid(child1ID, &status1, 0);
		stopID2 = waitpid(child2ID, &status2, 0);
		time(&currentTime);
		printf ("Hello world from the parent at %s \n", ctime(&currentTime)); 
	}
}

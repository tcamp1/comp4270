#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
int main()
{
	int i;
	int status;
	pid_t childID;
	pid_t stopID;
	time_t currentTime;

	if ((childID = fork()) == 0)
	{ 
		time(&currentTime);
		printf ("Hello world from the child at %s\n", ctime(&currentTime));
	}

	if (childID > 0) {
		stopID = waitpid(childID, &status, 0);
		time(&currentTime);
  		printf ("Hello world from the parent at %s\n", ctime(&currentTime));
	}
}

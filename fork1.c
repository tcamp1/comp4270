#include <stdio.h>
#include <unistd.h>

int pid1=-1;

int main()
{
	if ((pid1 = fork()) == 0)
	{ 
		printf ("Hello world from the child.\n");
	}


	if (pid1>0) { printf ("Hello world from the parent.\n"); }

}

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int ret;
	pid_t pid;

	putenv("RUNNABLE_PROG=LN40BG_openclose");
	putenv("PATH=/home/jb/LN40BG/LN40BG_openclose");

	pid = fork();
	if(pid == 0){
		printf("Gyerek vagyok, pidem:%d, szulom pidje:%d\n", getpid(), getppid());
		ret = execl(getenv("PATH"), getenv("RUNNABLE_PROG"), NULL);
	}

	wait(NULL);
		
	printf("Szulo vagyok, pidem:%d, gyerek pidje:%d\n", getpid(), pid);

	exit(0);
}

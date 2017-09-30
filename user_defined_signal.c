#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

void userSignal1(int handler)
{
	printf("Handled SIGUSR1(%d) by process: %d\n",handler,getpid());
}

void userSignal2(int handler)
{
	printf("Handled SIGUSR2(%d) by process: %d\n",handler,getpid());
}

int main(int argc, char *argv[])
{
	pid_t pid, terminatedPid;
	int res, status;

	signal(SIGUSR1, userSignal1);
	signal(SIGUSR2, userSignal2);	
	
	if((pid=fork())==0)
	{
		printf("fork completed\n");
		execl("user_defined_signal_client",NULL);
	}
	else
	{
		terminatedPid = wait(&status);
		printf("Terminated child with pid=%d and status=%d\n",terminatedPid,status);
	}
	
	return 0;
}

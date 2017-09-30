#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	pid_t ppid;
	printf("user_defined_signal_client\n");
	ppid = getppid();
	
	kill(ppid,SIGUSR1);
	kill(ppid,SIGUSR2);
	return 0;
}

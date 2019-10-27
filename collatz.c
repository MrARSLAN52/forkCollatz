#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void program(int sayi);

void  main(void)
{
     int girilen;
     printf("sayi : ");
     scanf("%d",&girilen);
     program(girilen);

     return 0;
}

void program(int sayi)
{
	printf("%d ",sayi);
	if(sayi == 1) return;
	pid_t  pid;
	pid = fork();

	while(pid == -1)
	{
		pid = fork();
	}

	if(pid == 0)
	{
		if(sayi % 2 == 0)
		{
			sayi = sayi / 2;
		}
		else
		{
			sayi = sayi * 3 + 1;
		}
	}
	else
	{
		wait(NULL);
		program(sayi);
	}

}
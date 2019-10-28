#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>



void program(int sayi);

int sayiiste()
{
	
	int gelen;
	printf("pozitif bir sayı giriniz : ");
	scanf("%d",&gelen);
	return gelen;
    
}

void  main(void)
{
    int girilen = 0;
	
	do
	{
		girilen = sayiiste();
	}
	while(girilen <= 0);
	
	program(girilen);
	
    return 0;
}



void program(int sayi)
{
	
	pid_t pid = fork();
	
	while(pid == -1)
	{
		pid = fork();
	}
	
	if(pid == 0)
	{
		
		printf("%d ",sayi);
		if(sayi == 1) return;
		
		else if(sayi % 2 == 0)
		{
			sayi = sayi / 2;
		}
		else
		{
			sayi = sayi * 3 + 1;
		}
			
		program(sayi);
	}
	else
	{
		
		wait(&pid);
		kill(getpid(),SIGKILL);
	}

}




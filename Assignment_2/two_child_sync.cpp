#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <semaphore.h>
#include <ctime>
#include <cstdlib>
#include <fcntl.h>
using namespace std;

int myrandom(void){
	clock_t t=clock();
	srand((int)t);
	int val=rand();
	return val%10;
}

int main()
{
	int pida,pidb,val;
	pid_t pa,pb;
	pida=fork();
	int i=0,j=0;
	int sync=1;
	sem_t* mutex;
	mutex=sem_open("/semaphore",O_CREAT,0644,0);
	if(pida==0){
		pa=getpid();
		for(i=0;i<10;i++){
			//while(sync<=0);
			//while(j<i-1);
			sem_wait(mutex);
			cout<<"process a : "<<i<<endl;
			val=myrandom();
			sleep(val);
		}
		exit(0);
	}
	else{
		pidb=fork();
		if(pidb==0){
			pb=getpid();
			for(j=0;j<10;j++){
				//while(sync<=0);
				//sync--;
				cout<<"process b : "<<j<<endl;
				val=myrandom();
				sleep(val);
				sem_post(mutex);
			}
			exit(0);
		}
		else{
			wait(NULL);
		}
		wait(NULL);
	}
	

return 0;
}
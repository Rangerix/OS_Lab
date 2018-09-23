#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctime>
#include <cstdlib>
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
	int i,j;
	if(pida==0){
		pa=getpid();
		for(i=0;i<10;i++){
			cout<<"process a : "<<i<<" pid : "<<pa<<endl;
			val=myrandom();
			sleep(val);
		}

	}
	else{
		pidb=fork();
		if(pidb==0){
			pb=getpid();
			for(j=0;j<10;j++){
				cout<<"process b : "<<j<<" pid : "<<pb<<endl;
				val=myrandom();
				sleep(val);
			}
		}
		else{
			wait(NULL);
		}
		wait(NULL);
	}

return 0;
}
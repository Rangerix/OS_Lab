#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

int main()
{
	double start,end;
	start=time(NULL);
	double elapsed=0;
	while(elapsed<30){
		end=time(NULL);
		sleep(1);
		elapsed=(double)(end- start)/(double)CLOCKS_PER_SEC*1000000;
		//cout<<"elapsed : "<<elapsed<<endl;
		cout<<"enter something\n";
		int x;
		cin>>x;
	}

return 0;
}
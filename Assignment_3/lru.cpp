#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class mylru{
	int size;
	vector<int> cache;
	public:
	mylru(int x=4){
		size=4;
		cache.clear();
	}
	int reference(int val){
		int i;
		int hit=0;
		for(i=0;i<cache.size();i++)
			if(cache[i]==val) hit=1;
		cache.erase(remove(cache.begin(), cache.end(), val), cache.end());
		cache.push_back(val);
		if(cache.size()>size) 
			cache.erase(cache.begin());
		return hit;
	}
	void show(){
		for(int i=0;i<cache.size();i++)
			cout<<cache[i]<<" ";
		cout<<endl;
	}
};

int main()
{
	mylru lru1(4);
	int calls[]={9, 10, 11, 7, 12, 8, 7, 6, 12, 5, 4, 3, 10, 11, 12, 4, 5, 6, 9, 4, 5};
	int count=sizeof(calls)/sizeof(int);
	int i,hitcount=0;
	cout <<"frame size : 4\n";
	for(i=0;i<count;i++){
		int flag=lru1.reference(calls[i]);
		if(flag){
			//cout<<"hit\n";
			hitcount++;
		}
		cout<<"reference : "<<calls[i]<<" : \t";
		lru1.show();
	}
	cout << "total hit : "<<hitcount<<endl;
	cout << "total no : " <<count<<endl;
	cout << "==========================================================\n";
	cout <<"frame size : 5\n";
	hitcount=0;
	mylru lru2(5);
	for(i=0;i<count;i++){
		int flag=lru2.reference(calls[i]);
		if(flag){
			//cout<<"hit\n";
			hitcount++;
		}
		cout<<"reference : "<<calls[i]<<" : \t";
		lru2.show();

	}
	cout << "total hit : "<<hitcount<<endl;
	cout << "total no : " <<count<<endl;

return 0;
}
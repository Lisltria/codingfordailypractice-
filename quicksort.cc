#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int val;
	node(int x){val = x;}
};
struct stat{
	int s,e;
};

vector<node> arr{1,2,3,4,5,4,3,2,1,0};

void quicksort(vector<node> & array,int s,int e){
	if(s>e)return ;
	stat first, tmp;
	first.s = s;
	first.e =e;	
	int i, j;
	queue<stat> status;
	status.push(first);
	while(!status.empty()){
		first = status.front();
		status.pop();
		i = first.s;
		j = first.s;
		
		while(i <= first.e && j <= first.e) {
			if(array[j].val <= array[first.e].val ){
				node tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				i++;
			}
			j++;
		}
		tmp = first;
		tmp.e = i - 2;
		if(tmp.s < tmp.e){
			status.push(tmp);
		}
		tmp = first;
		tmp.s = i;
		if(tmp.s < tmp.e){
			status.push(tmp);
		}
	}
}

int main(){
	quicksort(arr,0,arr.size()-1);
	for(auto it = arr.begin();it != arr.end(); it++)
		cout<<(*it).val<<" ";
	return 0;
}

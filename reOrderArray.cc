#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
		stable_partition(array.begin(), array.end(),[&](int &x){return x%2==1;});		
    }
};
int main() {
	vector<int> arr{1,2,3,4,5};
	Solution t;
	t.reOrderArray(arr);
	for(auto it = arr.begin(); it != arr.end(); it++)
		cout<<*it<<endl;
	return 0;
}

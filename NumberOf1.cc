#include <iostream>
using namespace std;

class Solution {
public:
	int NumberOf1(int n) {
		int count = 0;
		if(n < 0) {
			unsigned int t = (unsigned int)n;
			//t -= 1;
			//t ^= 0xffffffff;
			while(t) {
				count += t & 0x0001;
				t >>= 1;
			}
		}
		else {
			unsigned int t = (unsigned int)n;
			while(t) {
				count += t & 0x0001;
				t >>= 1;
			}
		}
	 return count;		
     }
};

int main(){
	Solution t;
	cout << t.NumberOf1(-3)<<endl;
	cout<< t.NumberOf1(3) << endl;
	return 0;
}

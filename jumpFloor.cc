#include <iostream>

using namespace std;
class Solution {
public:
    int jumpFloor(int number) {
        int last_, last__;
		last_ = 2;
		last__ = 1;
		if(number == 1) return 1;
		else if(number == 2) return 2;
		else {
			for(int i = 3; i <=number; i++) {
				last_ = last_ + last__;
				last__ = last_ - last__;
			}
		}
		return last__;
    }
};

class Solution2 {
public:
	int pow(int x, int n){
		if(x>1){
			return pow(x-1,n*2);
		}
		else
			return n;
	}
    int jumpFloorII(int number) {
		if(number == 0)return 1;
		return pow(number,1);
    }

	int rectCover(int number) {
		if(number == 0) return 0;
		else if(number == 1) return 1;
		else if(number == 2) return 2;
		else {
			int last_ = 1;
			int last__ = 2;
			int ans = 3;
			for(int i = 3; i <= number; i++) {
				ans = last_ + last__;
				last__ = last_;
				last_ = ans;
			}
			return ans;
		}
		
	}
};

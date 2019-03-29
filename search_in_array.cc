#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		bool Find(int target, vector<vector<int> > array) {
			bool ret = false;
			for (auto iter = array.begin(); iter != array.end(); iter++) {
				if (iter->empty() )break;
				auto start = iter->begin();
				auto end = iter->end() - 1;
				if( *start <= target && *end >= target ) {
					if(ret) break;
					int l = 0;
					int r = iter->size();
					int mid = l+(r-l)/2;
					while ( l <= r ) {
						if( (*iter)[mid] == target ) {
							ret = true;
							break;
						}
						else if ( (*iter)[mid] < target ){
							l = mid + 1;
							mid = l+(r-l) / 2;
						}
						else if ( (*iter)[mid] > target ){
							r = mid -1;
							mid = l+(r-l) / 2;
						}
					}

				}
			}
			return ret;
		}
};

int main() {
	vector<int> a1{1,2,3,4},a2{5,6,7,8},a3{9,10,11,12};
	vector<vector<int> >aa;
	Solution t;
	aa.push_back(a1);
	aa.push_back(a2);
	aa.push_back(a3);
	if(t.Find(1,aa))cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	return 0;
}


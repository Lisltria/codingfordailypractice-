#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if ( rotateArray.empty())return 0;
        int r,l,mid;
        l = 0;
        r = rotateArray.size() - 1;
        mid = l + (r-l)/2;
        while(l<r){
            if(rotateArray[mid] == rotateArray[r]) {
                r = mid;
                mid = l + (r-l)/2;
            }
            else if(rotateArray[mid] < rotateArray[r]) {
                r = mid;
                mid = l + (r-l)/2;
            }
            else if(rotateArray[mid] > rotateArray[r]) {
                l= mid +1;
                mid = l + (r-l)/2;
            }
        }
        return rotateArray[l];
    }
};

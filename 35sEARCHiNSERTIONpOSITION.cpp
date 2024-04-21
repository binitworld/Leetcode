#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start =0;
        int end =nums.size();
        while(start<end){
        const int mid=(start+end)/2;
        if(target==nums[mid])
            return mid;
        if(target>nums[mid])
            start= mid + 1;
        else
            end = mid;
        
        }
        return start;
    }   
};
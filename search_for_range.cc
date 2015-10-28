#include<iostream>
#include<stdexcept>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> result;
            result.push_back(-1);
            result.push_back(-1);

            int low = 0 , high = nums.size() - 1;
            int mid;
            while(low < high) {
                mid = (low + high) /2;
                if(nums[mid] >= target) {
                    high = mid - 1;
                } else if(nums[mid] ) {
                    low = mid + 1;
                }
            }
            if(nums[low] ==  target)
            result[0] = low;
            low = 0 , high = nums.size() - 1;
            while(low <= high) {
                mid = (low + high) /2;
                if(nums[mid] <= target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if(nums[high] == target)
            result[1] = high;
            return result; 
        }
};
int main() {

    vector<int> vec;
    int a[6] = {5, 7, 7, 8, 8, 10};
    for(int i=0;i<6;i++)
        vec.push_back(a[i]);
    Solution sol;

    vector<int> result;
    result = sol.searchRange(vec, 8);
    /*
       try{
       vec.at(2) = 100;
       } catch (out_of_range err){
       cout<<"fwe\t"<<err.what()<<endl;
       }
       */
    for(vector<int>::const_iterator iter =result.begin(); iter != result.end(); iter++)
    {
        cout<<(*iter)<<endl;
    }


    return 0;

}

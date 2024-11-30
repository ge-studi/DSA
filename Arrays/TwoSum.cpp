/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]*/

#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
vector<int> twoSum(vector<int>& nums, int target){
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target)
            return{i,j};
        }
    }
    return {};
}

};

int main() {
    int size, target;
    
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> nums(size); // Declare a vector to hold the input numbers

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    Solution sol; 
    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
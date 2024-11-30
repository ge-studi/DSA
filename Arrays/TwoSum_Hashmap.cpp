// Using Hashmap to reduce Time Complexity
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int> map;
    int complement;
    for(int i=0;i<nums.size();i++){
        complement = target -nums[i];
        if(map.find(complement)!=map.end()){
            return{complement,i};
        }
        map[nums[i]]=i;
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
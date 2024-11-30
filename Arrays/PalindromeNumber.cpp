/*Easy
Given an integer x, return true if x is a 
palindrome, and false otherwise.
 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0))
        return false;
        int reversed =0;
       while(x>reversed){
        reversed = reversed*10 + x % 10;
        x/=10;
       }
       
       return x==reversed || x==reversed/10;
    }
};

int main(){
    int num;
    cout<<"Enter number"<<endl;
    cin>>num;

    
    Solution sol; 
    int result = sol.isPalindrome(num);
    if(result)
       cout << "Output: true" << endl; 
    else
        cout << "Output: false" << endl; 
    return 0;
}
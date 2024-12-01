/*Restaurants during pandemic

Description

You have a restaurant at a beachside which has N dining tables. Each dining table has only one chair so each table can accommodate only one person. These dining tables are along a straight line parallel to the beach at positions x1,...,xN.

C customers are currently queued up outside the restaurant since you have reopened the restaurant after a long time due to the pandemic. You need to assign the dining tables to the customers such that the minimum distance between any two customers is as large as possible in order to take care of the precautions considering the current pandemic situation. (Consider all C customers dine at the same time) Find the largest minimum distance possible.

Input Description

The first line of the input contains one integer t (1sts 10) - the number of test cases. Then Utest cases follow.

The first line of each test case contains 2 integers N (2≤ N ≤ 100000) and c (2≤ CsN). The second line of each test case contains n integers (1 s Xis 1000000000)-The elements of the array W.

Output Description
Output Description

For each test case, print the answer: The largest minimum distance.

Sample Input 1

2

5 2

2 4 1 6 8

5 3

3 1 3 3 3

Sample Output 1

7

0

Objective: Place C customers at N positions (dining tables) such that the minimum distance between any two customers is maximized.
Constraints:
The positions are fixed (given as an array).
All C customers must be seated.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCustomers(const vector<int>& positions,int c ,int dist){
    int count = 1; //Place 1st customer
    int last_position = positions[0];

    for(int i=1;i<positions.size();++i){
        if(positions[i]-last_position>= dist){
            ++count; //add another customer
            last_position = positions[i];
            if(count == c){
                return true; //exit if all customers placed
            }
        }
    }
    return false;

}

int largestMinimumDistance(const vector<int>& positions,int c){
    int low=1;
    int high = positions.back() - positions.front();
    int result = 0;

    while(low<=high){
        int mid = low + (high-low) / 2;
        if(canPlaceCustomers(positions,c,mid)){
               result = mid; //update result if valid
               low = mid+1; //try larger dist
        }

   else{
    high =mid -1; // reduce distance

   }
    }
    return result;
}

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n,c;
        cin>>n>>c;

        vector<int>positions(n);
        for(int& pos  :positions){
            cin>>pos;
        }

        //sort positions
        sort(positions.begin(),positions.end());

        //find largest min dist
        cout<<largestMinimumDistance(positions,c)<< '\n';
    }
    return 0;
}
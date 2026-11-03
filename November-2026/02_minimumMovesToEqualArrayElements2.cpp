#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        
        // Approach-1: Sorting + Median, Sort the array and choose the middle element (median) as the target. 
        // Increment smaller elements and decrement larger elements towards the median; the sum of absolute differences gives the minimum moves.
        // Time Complexity: O(n*log n) + O(n) and Space Complexity: O(1)

        sort(nums.begin(), nums.end());
        int middleElement = nums[n/2];
        
        int moves = 0;
        for(int i = 0; i < n; i++) {
            moves += abs(middleElement - nums[i]);
        }
        return moves;
    }
};
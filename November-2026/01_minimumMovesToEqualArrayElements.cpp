#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkElementsEqual(vector<int>& nums) {
        int n = nums.size();
        int ele = nums[0];

        for(int i = 1; i < n; i++) {
            if(ele != nums[i]) return false;
        }
        return true;
    }

public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        // Approach-3: Use the observation that (sum(nums) - n * minElement) gives the total moves required. 
        // Calculate the minimum element and array sum once.
        // Time Complexity: O(n) and Space Complexity: O(1)
        
        int moves = 0;
        int minElement = *min_element(nums.begin(), nums.end());
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        for(int i = 0; i < n; i++) {
            moves += (totalSum - (n*minElement));
        }
        return moves;


        // Approach-2: Instead of incrementing n-1 elements, think of decrementing the largest elements until all elements reach the minimum value. 
        // The total moves are simply the sum of differences between each element and the minimum.
        // Time Complexity: O(n) and Space Complexity: O(1)
        /*
        int moves = 0;
        int minElement = *min_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            moves += (nums[i] - minElement);
        }
        return moves;
        */


        // Approach-1: Repeatedly increment all elements except the maximum element by 1 until every element becomes equal.
        // Time Complexity: O(n*n) and Space Complexity: O(1)
        /*
        int moves = 0;
        while(!checkElementsEqual(nums)) {
            int maxElementIdx = *max_element(nums.begin(), nums.end());

            for(int i = 0; i < n; i++) {
                if(i == maxElementIdx) continue;
                else nums[i] += 1;
            }
            moves++;
        }
        return moves;
        */
    }
};
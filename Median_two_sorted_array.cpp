/* 

Link : https://leetcode.com/problems/median-of-two-sorted-arrays/

Problem Statement :
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
*/

//Solution :
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int x = nums1.size();
        int y = nums2.size();
        
        int low = 0;
        int high = x;
        
        while(left <= right){
            int partitionx = (low + high) >> 1;
            int partitiony = (x + y + 1)/2 - partitionx;
            
            int maxleftx = (partitionx == 0) ? INT_MIN : nums1[partitionx - 1];
            int maxrightx = (partitionx == x) ? INT_MAX : nums1[partitionx];
            
            int maxlefty = (partitiony == 0) ? INT_MIN : nums2[partitiony - 1];
            int maxrighty = (partitiony == y) ? INT_MAX : nums2[partitiony];
            
            if(maxleftx <= maxrighty && maxlefty <= maxrightx){
                if((x+y) % 2 == 0)
                    return (double)(max(maxleftx, maxlefty) + min(maxrightx, maxrighty))/2;
                else
                    return max(maxleftx, maxlefty);
            }
            else if(maxleftx > maxrighty)
                high = partitionx - 1;
            else
                low = partitionx + 1;
        }
        return -1;
    }
};

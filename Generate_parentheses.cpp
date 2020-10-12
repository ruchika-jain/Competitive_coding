/*

Link : https://leetcode.com/problems/generate-parentheses/

Problem Statement :
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

*/

//Solution :

//backtracking approach :
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", n, n);
        return res;
    }
    void backtrack(vector<string>& res, string curr, int left, int right) {
        if(right == 0 && left == 0) {
            res.push_back(curr);
            return;
        }
        if(left > 0) {
            backtrack(res, curr + '(', left-1, right);
        }
        if(left < right)
            backtrack(res, curr + ')', left, right-1);
    }
};

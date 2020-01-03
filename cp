LC 1
Two integers adding to a sum and return the indeces
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int c=target-nums[i];
            if(m.find(c)!=m.end()){
                res.push_back(m[c]);
                res.push_back(i);
                break;
            }
            m[nums[i]]=i; 
            
        }
        return res;
    }
};

Corner case- Check that the complement is not itself and if it is same, then also check that m[c]!=if

LC 7
Reverse integer wiyhin 2^32 if more than that return 0

#include<bits/stdc++.h>
class Solution {
public:
    int reverse(int x) {
        int temp=0;
        int d;
        while(x!=0){
            d=x%10;
            x/=10;
            if(temp>INT_MAX/10||(temp==INT_MAX/10 && d>7))return 0;
            if(temp<INT_MIN/10||(temp==INT_MIN/10 && d<-8))return 0;
            temp=temp*10+d;
        }
        
        return temp;
    }
};

Alternate-Converting to string
class Solution {
public:
    int reverse(long x) {
        long temp=0;
        long v=abs(x);
        string s=to_string(v);
        string rs=" ";
        for(int i=s.length()-1;i>=0;i--)
            rs+=s[i];
        temp=stol(rs);
        if((temp>pow(2,31))||(x>0 && temp==pow(2,31)))
           return 0;
        else if(x>0)
           return temp;
        else 
        return -temp;
    }
};


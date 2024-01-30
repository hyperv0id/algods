#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/koko-eating-bananas/submissions/431669442/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int small = 1, big = 1e9;
       while(small < big){
           int m = (small+big)>>1;
           int t = cnt(piles, m);
           if(t > h){
               small = m+1;
           }
        //    else if(t == h){return m;}
           else{
               big = m;
           }
        //    printf("%d\t%d\t%d\t%d\n", small, m, big, t);
       }
       return small;
    }

    int cnt(vector<int>& piles, int x){
        int ans=0;
        for(auto&&p : piles){
            ans += p/x;
            if(p%x!=0)ans++;
        }
        return ans;
    }


};
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> arr = {30,11,23,4,20};
    cout << s.minEatingSpeed(arr, 6) << endl;
    return 0;
}

class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        unordered_map<char,int> mp;
        int mini=0;
        int max_el=0;
        int cnt=0;

        if(s.size()==1){
            return 1;
        }

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            if(it.second%2==0){
                ans=ans+it.second;
            }else {
                if(it.second==1 && cnt!=1){
                    ans=ans+1;
                    cnt++;
                }
                mini=it.second-1;
                ans=ans+mini;
                max_el=max(max_el,mini);
            }
        }
        if(max_el!=0 &&cnt!=1){
            ans=ans+1;
        }
        return ans;
    }
};
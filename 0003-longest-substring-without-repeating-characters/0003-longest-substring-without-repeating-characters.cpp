class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //two pointers traversing the string
        int j=0;
        int i=0;
        unordered_map<char,int> mp;
        int ans=INT_MIN;

        if(s.length()==0){
            return 0;
        }

        while(s.length()>j){
            mp[s[j]]++; //increase the frequency of the element as you traverse the string
            if(mp.size()==j-i+1){// when map size is equal to the window size means all    
                                 //unique characters are there
               ans=max(ans,j-i+1);                  
            }
            else{
                //this means characters r repeated so we need to reset value
                 while(mp.size()<j-i+1)  //till the duplicates are removed completely
                 {
                     mp[s[i]]--;//decrease the value of starting of substring and we keep decreasing untill all duplicates r removed using the loop
                     if(mp[s[i]]==0){
                         mp.erase(s[i]);//if frequency 0 remove the element completely
                     }
                     i++;
                 }
            }
            j++;
        }
        return ans;
    }
};




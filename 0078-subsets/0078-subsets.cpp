// class Solution {
// private:
//     void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans) {
//         //base case
//         if(index >= nums.size()) {
//             ans.push_back(output);
//             return ;
//         }
        
//         //exclude
//         solve(nums, output, index+1, ans);
        
//         //include
//         int element = nums[index];
//         output.push_back(element);
//         solve(nums, output, index+1, ans);
        
//     }
    
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
        
//         vector<vector<int> > ans;
//         vector<int> output;
//         int index = 0;
//         solve(nums, output, index, ans);
//         return ans;
        
//     }
// };




















class Solution {
public:
    void solve(vector<int>& nums,vector<int> output, vector<vector<int>> &ans, int ind){
        if(ind>=nums.size()){
            ans.push_back(output);
            return;
        }
        //exclude
        solve(nums,output,ans,ind+1);

        //include
        output.push_back(nums[ind]);
        solve(nums,output,ans,ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>> ans;
        solve(nums,output,ans,0);
        return ans;
    }
};
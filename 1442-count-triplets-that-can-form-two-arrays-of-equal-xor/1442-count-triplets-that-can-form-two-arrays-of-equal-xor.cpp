class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int a=0;
                for(int k=i;k<j;k++){
                    a=a^arr[k];
                }

                int b=0;
                for(int k=j;k<arr.size();k++){
                    b=b^arr[k];
                    if(a==b){
                        cnt++;
                    }
                }
                
            }
        }
        return cnt;
    }
};
class Solution {
public:
   vector<string>ans;

   void generate(string &s,int open,int close){

       if(open==0 && close==0){
           ans.push_back(s);
           return; 
       }

       if(open>0){//until open not there we cannot have a closed bracket
           s.push_back('(');
           generate(s,open-1,close);
           s.pop_back();//for backtracking
       }

       if(close>0 && open<close){//means we have more no of open bracket in the dtring s and its valid to put close bracket in the string
           s.push_back(')');
           generate(s,open,close-1);
           s.pop_back();//for backtracking
       }
   }

    vector<string> generateParenthesis(int n) {
        string s;
        generate(s,n,n);
        return ans;
    }
};

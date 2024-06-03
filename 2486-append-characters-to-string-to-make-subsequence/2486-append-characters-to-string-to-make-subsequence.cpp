class Solution {
public:
    int appendCharacters(string s, string t) {
        int st1=0;
        int st2=0;
        int e1=s.length();
        int e2=t.length();
        while(st1<e1 && st2<e2){
            if(s[st1]==t[st2]){
                st2++;
            }
            st1++;
        }
        return e2-st2;
    }
};
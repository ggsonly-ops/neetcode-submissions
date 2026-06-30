class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length()) return false;

        int hash[26] = {0};

        for(int i=0;i<s1.length();i++){
            hash[s1[i]-'a']++;
        }
        

        int counter=0;
        for(int i=0;i<26;i++){
            if(hash[i]!=0) counter++;
        }
        

        int l=0;
        int r=0;


        while(r < s2.size()){
            
            if(r-l+1 > s1.length()){
                hash[s2[l]-'a']++;
                if(hash[s2[l]-'a']==1) counter++;
                l++;
            }

            hash[s2[r]-'a']--;
            if(hash[s2[r]-'a']==0) counter--;
            if(counter==0) return true;
            r++;
        }

        return false;
    }
};

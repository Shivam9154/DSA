class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string word3;
        while(i<word1.size() && j<word2.size()){
            word3+=word1[i];
            word3+=word2[j];
            i++;
            j++;
        }
        while(j<word2.size()){
            word3+= word2[j];
            j++;
        }
        while(i<word1.size()){
            word3+=word1[i];
            i++;
        }
        return word3;
    }
};
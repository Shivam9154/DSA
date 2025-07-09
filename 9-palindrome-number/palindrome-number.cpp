class Solution {
public:
    bool isPalindrome(int x) {
       int temp=x;
       if(x<0){
        return 0;
       }
       long long int y=0;
       while(x!=0){
        y=y*10 + (x%10);
        x=x/10;
       }
       if(temp==y){
        return 1;
       }   
       return 0;
    }
};
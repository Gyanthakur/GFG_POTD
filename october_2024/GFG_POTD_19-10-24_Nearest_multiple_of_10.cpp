
class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.length()-1;
        if(str[n]<='5'){
            str[n]='0';
            return str;
        }
        str[n]='0';
        n--;
        while(n>=0 and str[n]=='9'){
            str[n]='0';
            n--;
        }
        if(n==-1)return '1'+str;
        str[n]++;
        return str;
    }
};
